project("new_test_lib")

cmake_minimum_required(VERSION 3.19.1)

file(GLOB source_files
  src/*.cpp)
file(GLOB private_header_files
  include/private/new_test_lib/*.h)
file(GLOB public_header_files
  include/public/new_test_lib/*.h)

add_library(${PROJECT_NAME}
  SHARED
    ${source_files}
    ${private_header_files}
    ${public_header_files}
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public/>
    $<INSTALL_INTERFACE:include/>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/private/>
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config)
install(EXPORT ${PROJECT_NAME}Config DESTINATION lib/cmake/${PROJECT_NAME})
install(FILES ${public_header_files} DESTINATION include/new_test_lib/)

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "alikhm4528@hotmail.com")
include(CPack)
