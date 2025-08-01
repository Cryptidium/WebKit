#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ICU::uc" for configuration "Debug"
set_property(TARGET ICU::uc APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::uc PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icuucd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icuuc77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::uc )
list(APPEND _cmake_import_check_files_for_ICU::uc "${_IMPORT_PREFIX}/debug/lib/icuucd.lib" "${_IMPORT_PREFIX}/debug/bin/icuuc77d.dll" )

# Import target "ICU::in" for configuration "Debug"
set_property(TARGET ICU::in APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::in PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icuind.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icuin77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::in )
list(APPEND _cmake_import_check_files_for_ICU::in "${_IMPORT_PREFIX}/debug/lib/icuind.lib" "${_IMPORT_PREFIX}/debug/bin/icuin77d.dll" )

# Import target "ICU::io" for configuration "Debug"
set_property(TARGET ICU::io APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::io PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icuiod.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icuio77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::io )
list(APPEND _cmake_import_check_files_for_ICU::io "${_IMPORT_PREFIX}/debug/lib/icuiod.lib" "${_IMPORT_PREFIX}/debug/bin/icuio77d.dll" )

# Import target "ICU::tu" for configuration "Debug"
set_property(TARGET ICU::tu APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::tu PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icutud.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icutu77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::tu )
list(APPEND _cmake_import_check_files_for_ICU::tu "${_IMPORT_PREFIX}/debug/lib/icutud.lib" "${_IMPORT_PREFIX}/debug/bin/icutu77d.dll" )

# Import target "ICU::test" for configuration "Debug"
set_property(TARGET ICU::test APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::test PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icutestd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icutest77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::test )
list(APPEND _cmake_import_check_files_for_ICU::test "${_IMPORT_PREFIX}/debug/lib/icutestd.lib" "${_IMPORT_PREFIX}/debug/bin/icutest77d.dll" )

# Import target "ICU::makeconv" for configuration "Debug"
set_property(TARGET ICU::makeconv APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::makeconv PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/makeconv.exe"
  )

list(APPEND _cmake_import_check_targets ICU::makeconv )
list(APPEND _cmake_import_check_files_for_ICU::makeconv "${_IMPORT_PREFIX}/tools/icu/makeconv.exe" )

# Import target "ICU::genrb" for configuration "Debug"
set_property(TARGET ICU::genrb APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::genrb PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/genrb.exe"
  )

list(APPEND _cmake_import_check_targets ICU::genrb )
list(APPEND _cmake_import_check_files_for_ICU::genrb "${_IMPORT_PREFIX}/tools/icu/genrb.exe" )

# Import target "ICU::genbrk" for configuration "Debug"
set_property(TARGET ICU::genbrk APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::genbrk PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/genbrk.exe"
  )

list(APPEND _cmake_import_check_targets ICU::genbrk )
list(APPEND _cmake_import_check_files_for_ICU::genbrk "${_IMPORT_PREFIX}/tools/icu/genbrk.exe" )

# Import target "ICU::gencnval" for configuration "Debug"
set_property(TARGET ICU::gencnval APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gencnval PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/gencnval.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gencnval )
list(APPEND _cmake_import_check_files_for_ICU::gencnval "${_IMPORT_PREFIX}/tools/icu/gencnval.exe" )

# Import target "ICU::gensprep" for configuration "Debug"
set_property(TARGET ICU::gensprep APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gensprep PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/sbin/gensprep.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gensprep )
list(APPEND _cmake_import_check_files_for_ICU::gensprep "${_IMPORT_PREFIX}/sbin/gensprep.exe" )

# Import target "ICU::icuinfo" for configuration "Debug"
set_property(TARGET ICU::icuinfo APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::icuinfo PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/icuinfo.exe"
  )

list(APPEND _cmake_import_check_targets ICU::icuinfo )
list(APPEND _cmake_import_check_files_for_ICU::icuinfo "${_IMPORT_PREFIX}/tools/icu/icuinfo.exe" )

# Import target "ICU::genccode" for configuration "Debug"
set_property(TARGET ICU::genccode APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::genccode PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/sbin/genccode.exe"
  )

list(APPEND _cmake_import_check_targets ICU::genccode )
list(APPEND _cmake_import_check_files_for_ICU::genccode "${_IMPORT_PREFIX}/sbin/genccode.exe" )

# Import target "ICU::gencmn" for configuration "Debug"
set_property(TARGET ICU::gencmn APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gencmn PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/sbin/gencmn.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gencmn )
list(APPEND _cmake_import_check_files_for_ICU::gencmn "${_IMPORT_PREFIX}/sbin/gencmn.exe" )

# Import target "ICU::icupkg" for configuration "Debug"
set_property(TARGET ICU::icupkg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::icupkg PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/sbin/icupkg.exe"
  )

list(APPEND _cmake_import_check_targets ICU::icupkg )
list(APPEND _cmake_import_check_files_for_ICU::icupkg "${_IMPORT_PREFIX}/sbin/icupkg.exe" )

# Import target "ICU::pkgdata" for configuration "Debug"
set_property(TARGET ICU::pkgdata APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::pkgdata PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/pkgdata.exe"
  )

list(APPEND _cmake_import_check_targets ICU::pkgdata )
list(APPEND _cmake_import_check_files_for_ICU::pkgdata "${_IMPORT_PREFIX}/tools/icu/pkgdata.exe" )

# Import target "ICU::gentest" for configuration "Debug"
set_property(TARGET ICU::gentest APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gentest PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/gentest.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gentest )
list(APPEND _cmake_import_check_files_for_ICU::gentest "${_IMPORT_PREFIX}/tools/icu/gentest.exe" )

# Import target "ICU::gennorm2" for configuration "Debug"
set_property(TARGET ICU::gennorm2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gennorm2 PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/sbin/gennorm2.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gennorm2 )
list(APPEND _cmake_import_check_files_for_ICU::gennorm2 "${_IMPORT_PREFIX}/sbin/gennorm2.exe" )

# Import target "ICU::gencfu" for configuration "Debug"
set_property(TARGET ICU::gencfu APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gencfu PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/gencfu.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gencfu )
list(APPEND _cmake_import_check_files_for_ICU::gencfu "${_IMPORT_PREFIX}/tools/icu/gencfu.exe" )

# Import target "ICU::gendict" for configuration "Debug"
set_property(TARGET ICU::gendict APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::gendict PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/tools/icu/gendict.exe"
  )

list(APPEND _cmake_import_check_targets ICU::gendict )
list(APPEND _cmake_import_check_files_for_ICU::gendict "${_IMPORT_PREFIX}/tools/icu/gendict.exe" )

# Import target "ICU::dt" for configuration "Debug"
set_property(TARGET ICU::dt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ICU::dt PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/icudtd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/icudt77d.dll"
  )

list(APPEND _cmake_import_check_targets ICU::dt )
list(APPEND _cmake_import_check_files_for_ICU::dt "${_IMPORT_PREFIX}/debug/lib/icudtd.lib" "${_IMPORT_PREFIX}/debug/bin/icudt77d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
