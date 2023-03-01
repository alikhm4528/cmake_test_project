project("calculator")

cmake_minimum_required(VERSION 3.19.1)

include(config.cmake)

add_library(${PROJECT_NAME} SHARED
    ${source_files}
    ${public_header_files}
    ${private_header_files}
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        include/private/
    PUBLIC
        include/public/
)

install(TARGETS ${PROJECT_NAME})
install(FILES ${public_header_files} DESTINATION include/calculator/)
