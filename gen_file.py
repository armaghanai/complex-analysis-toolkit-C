import os
import re

def make_guard(directory, module):
    text = f"{directory}_{module}".upper()
    text = re.sub(r'[^A-Z0-9]', '_', text)
    return text + "_H"

module = input("Module name: ").strip()

if not module:
    print("Error: Module name cannot be empty.")
    exit()

directory = input("Directory [default: cvt]: ").strip()

if not directory:
    directory = "cvt"

#create_test = input("Create test file? [Y/n]: ").strip().lower()
#create_test = (create_test == "" or create_test == "y")

include_dir = os.path.join("include", directory)
src_dir = os.path.join("src", directory)
#test_dir = "tests"

os.makedirs(include_dir, exist_ok=True)
os.makedirs(src_dir, exist_ok=True)

#if create_test:
    #os.makedirs(test_dir, exist_ok=True)

guard = make_guard(directory, module)

header_path = os.path.join(include_dir, module + ".h")
source_path = os.path.join(src_dir, module + ".c")
#test_path = os.path.join(test_dir, "test_" + module + ".c")

# ---------------- Header ----------------

if not os.path.exists(header_path):
    with open(header_path, "w") as f:
        f.write(f"""#ifndef {guard}
#define {guard}

#ifdef __cplusplus
extern "C" {{
#endif

// Includes


// Types


// Function declarations


#ifdef __cplusplus
}}
#endif

#endif /* {guard} */
""")
    print("Created:", header_path)
else:
    print("Skipped:", header_path, "(already exists)")

# ---------------- Source ----------------

if not os.path.exists(source_path):
    with open(source_path, "w") as f:
        f.write(f"""#include <{directory}/{module}.h>


// Function definitions

""")
    print("Created:", source_path)
else:
    print("Skipped:", source_path, "(already exists)")

# ---------------- Test ----------------

'''if create_test:
    if not os.path.exists(test_path):
        with open(test_path, "w") as f:
            f.write(f"""#include <stdio.h>
#include <{directory}/{module}.h>

int main(void)
{{
    printf("Testing {module}\\n");

    return 0;
}}
""")
        print("Created:", test_path)
    else:
        print("Skipped:", test_path, "(already exists)")'''

print("\nDone!")