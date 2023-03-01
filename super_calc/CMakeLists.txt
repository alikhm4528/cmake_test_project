project("super_calc")

cmake_minimum_required(VERSION 3.19.1)

file(GLOB source_files
    src/*.cpp
)
file(GLOB header_files
    include/super_calc/*.h
)

add_library(${PROJECT_NAME} SHARED
    ${source_files}
    ${header_files}
)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include/
)

install(TARGETS ${PROJECT_NAME})
install(FILES ${public_header_files} DESTINATION include)
