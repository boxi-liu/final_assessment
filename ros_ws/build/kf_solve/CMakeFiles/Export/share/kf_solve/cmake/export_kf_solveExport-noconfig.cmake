#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "kf_solve::kf_solve" for configuration ""
set_property(TARGET kf_solve::kf_solve APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(kf_solve::kf_solve PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkf_solve.so"
  IMPORTED_SONAME_NOCONFIG "libkf_solve.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS kf_solve::kf_solve )
list(APPEND _IMPORT_CHECK_FILES_FOR_kf_solve::kf_solve "${_IMPORT_PREFIX}/lib/libkf_solve.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
