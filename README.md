# WebKit for Windows
A pre compiled version of WebKit for Windows to save you time
# Current version
2.49.4
# Tips for psychopaths wanting to compile WebKit themselves
1. Don't
2. Install all tools like LLVM, Python etc. in a short path without any spaces in it
3. Use the x86_x64 Cross Tools Command Prompt for VS 2022
4. Run the command prompt as administrator
5. Don't bother with linux, its not gonna work
6. Use the following build command since thats what worked for me
```bash
perl Tools\Scripts\build-webkit ^
     --wincairo --release --skip-library-update ^
     --cmakeargs=-DCMAKE_C_COMPILER=C:/Dev/LLVM/bin/clang-cl.exe -DCMAKE_CXX_COMPILER=C:/Dev/LLVM/bin/clang-cl.exe -DCLANG_BUILTINS_LIBRARY=C:/WebKit/clang_rt.builtins-x86_64.lib
```
