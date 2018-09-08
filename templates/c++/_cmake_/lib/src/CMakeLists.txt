include_directories(${app_SOURCE_DIR}/lib/inc)

set(SOURCES
    ../inc/cex/StringUtil.hpp
    StringUtil.cpp
)
add_library(cex STATIC ${SOURCES})

