
set(SOURCES 
    tinyexpr.c
)

add_library(tinyexpr STATIC ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(tinyexpr PUBLIC ./)