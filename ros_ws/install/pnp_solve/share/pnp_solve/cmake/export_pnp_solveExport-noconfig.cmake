#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pnp_solve::pnp_solve" for configuration ""
set_property(TARGET pnp_solve::pnp_solve APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pnp_solve::pnp_solve PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpnp_solve.so"
  IMPORTED_SONAME_NOCONFIG "libpnp_solve.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pnp_solve::pnp_solve )
list(APPEND _IMPORT_CHECK_FILES_FOR_pnp_solve::pnp_solve "${_IMPORT_PREFIX}/lib/libpnp_solve.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
