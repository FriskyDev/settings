include_directories(${app_SOURCE_DIR}/app/src)
include_directories(${app_SOURCE_DIR}/lib/inc)

link_directories(${SOURCE_DIR}/lib/src)

set(SOURCES
    main.cpp
)

add_executable(app main.cpp)
target_link_libraries(app cex)
