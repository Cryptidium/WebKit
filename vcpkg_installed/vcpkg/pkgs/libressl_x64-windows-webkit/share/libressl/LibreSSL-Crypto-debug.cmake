#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LibreSSL::Crypto" for configuration "Debug"
set_property(TARGET LibreSSL::Crypto APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(LibreSSL::Crypto PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/crypto.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/crypto-56.dll"
  )

list(APPEND _cmake_import_check_targets LibreSSL::Crypto )
list(APPEND _cmake_import_check_files_for_LibreSSL::Crypto "${_IMPORT_PREFIX}/debug/lib/crypto.lib" "${_IMPORT_PREFIX}/debug/bin/crypto-56.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
