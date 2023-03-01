file(GLOB source_files
    src/*.cpp
)
file(GLOB public_header_files
    include/public/calculator/*.h
)
file(GLOB private_header_files
    include/private/calculator/*.h
)

source_group("Source files"
    FILES
    ${source_files}
)
source_group("APIs"
    FILES
    ${public_header_files}
)
source_group("Private headers"
    FILES
    ${private_header_files}
)
