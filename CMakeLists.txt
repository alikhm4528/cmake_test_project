cmake_minimum_required(VERSION 3.19.1)
project("test_project" VERSION 1.2.0)

add_subdirectory(calculator)
add_subdirectory(common)
#add_subdirectory(new_test_lib)
find_package(new_test_lib REQUIRED)

set(external_libs)
set(external_libs_definitions)

add_executable(${PROJECT_NAME} main.cpp)

option(enable_name "Do you want to use name of the project?" off)
option(use_super_calc "Do you want to use super calc lib?" off)
if(use_super_calc)
  add_subdirectory(super_calc)
  list(APPEND external_libs super_calc)
  list(APPEND external_libs_definitions USE_SUPER_CALC)
endif()

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    calculator
    common
    new_test_lib
    ${external_libs}
)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    ${external_libs_definitions}
)

configure_file(config.h.in ${CMAKE_SOURCE_DIR}/config.h)

#install target
install(TARGETS ${PROJECT_NAME})

#uninstall target
if(NOT TARGET uninstall)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall_rule.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall_rule.cmake
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND}
      -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall_rule.cmake)
endif()

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "alikhm4528@hotmail.com")

#cpack addition
include(InstallRequiredSystemLibraries)
include(CPack)






