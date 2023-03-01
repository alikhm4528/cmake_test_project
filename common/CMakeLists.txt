project(common)

file(GLOB header_files
  include/common/*.h)

add_library(${PROJECT_NAME} INTERFACE
  ${header_files}
)
target_include_directories(${PROJECT_NAME}
  INTERFACE
    include/
)

install(TARGETS ${PROJECT_NAME})
install(FILES ${header_files} DESTINATION include)
