#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cpr::cpr" for configuration ""
set_property(TARGET cpr::cpr APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cpr::cpr PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcpr.so.1.10.5"
  IMPORTED_SONAME_NOCONFIG "libcpr.so.1"
  )

list(APPEND _cmake_import_check_targets cpr::cpr )
list(APPEND _cmake_import_check_files_for_cpr::cpr "${_IMPORT_PREFIX}/lib/libcpr.so.1.10.5" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
