# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_kf_solve_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED kf_solve_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(kf_solve_FOUND FALSE)
  elseif(NOT kf_solve_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(kf_solve_FOUND FALSE)
  endif()
  return()
endif()
set(_kf_solve_CONFIG_INCLUDED TRUE)

# output package information
if(NOT kf_solve_FIND_QUIETLY)
  message(STATUS "Found kf_solve: 0.0.0 (${kf_solve_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'kf_solve' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${kf_solve_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(kf_solve_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${kf_solve_DIR}/${_extra}")
endforeach()
