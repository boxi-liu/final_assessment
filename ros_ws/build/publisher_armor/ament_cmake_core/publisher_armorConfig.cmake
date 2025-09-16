# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_publisher_armor_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED publisher_armor_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(publisher_armor_FOUND FALSE)
  elseif(NOT publisher_armor_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(publisher_armor_FOUND FALSE)
  endif()
  return()
endif()
set(_publisher_armor_CONFIG_INCLUDED TRUE)

# output package information
if(NOT publisher_armor_FIND_QUIETLY)
  message(STATUS "Found publisher_armor: 0.0.0 (${publisher_armor_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'publisher_armor' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${publisher_armor_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(publisher_armor_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${publisher_armor_DIR}/${_extra}")
endforeach()
