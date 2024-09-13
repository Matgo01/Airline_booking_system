cmake_minimum_required(VERSION 3.14)

project(Airline booking system VERSIONE 1.0 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Sql)

include_directories(${PROJECT_SOURCE_DIRE}/include)

set(SOURCE
src/prenotation.cpp
src/prenotationWindow.cpp
src/registration.cpp
src/user.cpp
src/visualizePrenotation.cpp
src/login.cpp
src/main.cpp
src/mainWindow.cpp
)

set(HEADERS
    include/user.h
    include/prenotation.h
    include/prenotationWindow.h
    include/registration.h
    include/visualizePrenotation.h
    include/login.h
    include/mainWindow.h
)

add_executable(Airline booking system ${SOURCES} ${HEADERS})

target_link_libraries(Airline booking system Qt6::Widgets Qt6::Sql)

set_target_properties(Airline booking system PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)