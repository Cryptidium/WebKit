#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LibreSSL::SSL" for configuration "Debug"
set_property(TARGET LibreSSL::SSL APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(LibreSSL::SSL PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/ssl.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/ssl-59.dll"
  )

list(APPEND _cmake_import_check_targets LibreSSL::SSL )
list(APPEND _cmake_import_check_files_for_LibreSSL::SSL "${_IMPORT_PREFIX}/debug/lib/ssl.lib" "${_IMPORT_PREFIX}/debug/bin/ssl-59.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
