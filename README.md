```
│   .gitignore
│   CHANGELOG.md
│   CMakeLists.txt
│   CONTRIBUTING.md
│   gen_file.py
│   LICENSE
│   README.md
│   
├───build
│   │   .ninja_deps
│   │   .ninja_log
│   │   build.ninja
│   │   CMakeCache.txt
│   │   cmake_install.cmake
│   │   complex_tests.exe
│   │   libcomplex_analysis.a
│   │   
│   └───CMakeFiles
│       │   cmake.check_cache
│       │   cmake.verify_globs
│       │   CMakeConfigureLog.yaml
│       │   InstallScripts.json
│       │   rules.ninja
│       │   TargetDirectories.txt
│       │   VerifyGlobs.cmake
│       │   
│       ├───4.4.0
│       │   │   CMakeCCompiler.cmake
│       │   │   CMakeDetermineCompilerABI_C.bin
│       │   │   CMakeRCCompiler.cmake
│       │   │   CMakeSystem.cmake
│       │   │   
│       │   └───CompilerIdC
│       │       │   a.exe
│       │       │   CMakeCCompilerId.c
│       │       │   
│       │       └───tmp
│       ├───complex_analysis.dir
│       │   └───src
│       │       └───complex
│       │               complex_constants.c.obj
│       │               complex_conversion.c.obj
│       │               complex_num.c.obj
│       │               complex_polar.c.obj
│       │               complex_utils.c.obj
│       │               
│       ├───complex_tests.dir
│       │   └───tests
│       │           test_complex_num.c.obj
│       │           test_complex_polar.c.obj
│       │           test_constants.c.obj
│       │           test_conversion.c.obj
│       │           test_main.c.obj
│       │           test_utils.c.obj
│       │           
│       └───pkgRedirects
├───docs
│       api.md
│       getting_started.md
│       
├───examples
├───include
│   └───complex
│           complex_constants.h
│           complex_conversion.h
│           complex_num.h
│           complex_polar.h
│           complex_utils.h
│           
├───src
│   └───complex
│           complex_constants.c
│           complex_conversion.c
│           complex_num.c
│           complex_polar.c
│           complex_utils.c
│           
└───tests
        test_complex_num.c
        test_complex_polar.c
        test_constants.c
        test_conversion.c
        test_helpers.h
        test_main.c
        test_utils.c
```