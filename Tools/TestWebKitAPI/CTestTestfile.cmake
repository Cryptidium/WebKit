# CMake generated Testfile for 
# Source directory: C:/WebKit/Tools/TestWebKitAPI
# Build directory: C:/WebKit/WebKitBuild/Release/Tools/TestWebKitAPI
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[TestWTF]=] "C:/WebKit/WebKitBuild/Release/bin/TestWTF")
set_tests_properties([=[TestWTF]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;11;add_test;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;447;WEBKIT_TEST;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;0;")
add_test([=[TestJavaScriptCore]=] "C:/WebKit/WebKitBuild/Release/bin/TestJavaScriptCore")
set_tests_properties([=[TestJavaScriptCore]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;11;add_test;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;451;WEBKIT_TEST;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;0;")
add_test([=[TestWebCore]=] "C:/WebKit/WebKitBuild/Release/bin/TestWebCore")
set_tests_properties([=[TestWebCore]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;11;add_test;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;456;WEBKIT_TEST;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;0;")
add_test([=[TestWebKit]=] "C:/WebKit/WebKitBuild/Release/bin/TestWebKit")
set_tests_properties([=[TestWebKit]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;11;add_test;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;466;WEBKIT_TEST;C:/WebKit/Tools/TestWebKitAPI/CMakeLists.txt;0;")
