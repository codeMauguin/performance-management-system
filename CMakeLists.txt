cmake_minimum_required(VERSION 3.22)
project(QueryScore C)

set(CMAKE_C_STANDARD 99)
include_directories(src)
include_directories(src/pojo)
include_directories(src/sql)
include_directories(src/util)
include_directories(src/util/collection)
include_directories(src/service)
include_directories(src/service/show)
include_directories(src/util/scanf)

aux_source_directory(src/util/scanf SCANF)
aux_source_directory(src/service/show SHOW)
aux_source_directory(src/service SERVICE)
aux_source_directory(src/util/collection/ COLLECTION)
aux_source_directory(src/sql SQL)
aux_source_directory(src/pojo POJO)
add_executable(QueryScore
        ${POJO}
        ${SQL}
        ${COLLECTION}
        ${SERVICE}
        ${SHOW}
        ${SCANF}
        src/main.c)
