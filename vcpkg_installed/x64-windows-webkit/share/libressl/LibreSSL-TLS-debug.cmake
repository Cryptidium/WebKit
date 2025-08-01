#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LibreSSL::TLS" for configuration "Debug"
set_property(TARGET LibreSSL::TLS APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(LibreSSL::TLS PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/tls.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/tls-32.dll"
  )

list(APPEND _cmake_import_check_targets LibreSSL::TLS )
list(APPEND _cmake_import_check_files_for_LibreSSL::TLS "${_IMPORT_PREFIX}/debug/lib/tls.lib" "${_IMPORT_PREFIX}/debug/bin/tls-32.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
