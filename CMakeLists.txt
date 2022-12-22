cmake_minimum_required(VERSION 3.23)
project(Content)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(tema2)

add_executable(Content
        tema2/Alhafez_nabil_2_obligatoriu_1.cpp
        tema2/Alhafez_nabil_2_obligatoriu_2.cpp
        tema2/Alhafez_nabil_2_obligatoriu_3.cpp
        tema2/Alhafez_nabil_2_obligatoriu_4.cpp
        tema2/Alhafez_nabil_2_obligatoriu_5.cpp
        )
