#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nghttp3::nghttp3" for configuration "Debug"
set_property(TARGET nghttp3::nghttp3 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nghttp3::nghttp3 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/nghttp3.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/nghttp3.dll"
  )

list(APPEND _cmake_import_check_targets nghttp3::nghttp3 )
list(APPEND _cmake_import_check_files_for_nghttp3::nghttp3 "${_IMPORT_PREFIX}/debug/lib/nghttp3.lib" "${_IMPORT_PREFIX}/debug/bin/nghttp3.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
