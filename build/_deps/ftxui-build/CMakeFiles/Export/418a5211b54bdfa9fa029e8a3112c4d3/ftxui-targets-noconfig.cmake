#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ftxui::screen" for configuration ""
set_property(TARGET ftxui::screen APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ftxui::screen PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libftxui-screen.so.5.0.0"
  IMPORTED_SONAME_NOCONFIG "libftxui-screen.so.5.0.0"
  )

list(APPEND _cmake_import_check_targets ftxui::screen )
list(APPEND _cmake_import_check_files_for_ftxui::screen "${_IMPORT_PREFIX}/lib/libftxui-screen.so.5.0.0" )

# Import target "ftxui::dom" for configuration ""
set_property(TARGET ftxui::dom APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ftxui::dom PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libftxui-dom.so.5.0.0"
  IMPORTED_SONAME_NOCONFIG "libftxui-dom.so.5.0.0"
  )

list(APPEND _cmake_import_check_targets ftxui::dom )
list(APPEND _cmake_import_check_files_for_ftxui::dom "${_IMPORT_PREFIX}/lib/libftxui-dom.so.5.0.0" )

# Import target "ftxui::component" for configuration ""
set_property(TARGET ftxui::component APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ftxui::component PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libftxui-component.so.5.0.0"
  IMPORTED_SONAME_NOCONFIG "libftxui-component.so.5.0.0"
  )

list(APPEND _cmake_import_check_targets ftxui::component )
list(APPEND _cmake_import_check_files_for_ftxui::component "${_IMPORT_PREFIX}/lib/libftxui-component.so.5.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
