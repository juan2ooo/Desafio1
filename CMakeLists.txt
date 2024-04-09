cmake_minimum_required(VERSION 3.5)

project(desafio1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(desafio1 main.cpp
    EstructuraM.cpp
    EstructuraX.cpp)

include(GNUInstallDirs)
install(TARGETS desafio1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
