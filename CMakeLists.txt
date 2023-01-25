cmake_minimum_required(VERSION 3.23)
project(Content)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(tema2)

add_executable(Content
        codes/curs_9_9/ford_fulkerson_method.cpp

        tema2/Alhafez_nabil_2_obligatoriu_1.cpp
        tema2/Alhafez_nabil_2_obligatoriu_2.cpp
        tema2/Alhafez_nabil_2_obligatoriu_3.cpp
        tema2/Alhafez_nabil_2_obligatoriu_4.cpp
        tema2/Alhafez_nabil_2_obligatoriu_5.cpp

        tema3/Alhafez_nabil_3_obligatoriu_1.cpp
        tema3/Alhafez_nabil_3_obligatoriu_2.cpp
        tema3/Alhafez_nabil_3_obligatoriu_3.cpp
        tema3/Alhafez_nabil_3_obligatoriu_4.cpp
        tema3/Alhafez_nabil_3_obligatoriu_5.cpp
        tema3/Alhafez_nabil_3_optional_6.cpp
        tema4/Alhafez_nabil_optional_1.cpp
        tema4/Alhafez_nabil_optional_2.cpp
        tema4/Alhafez_nabil_optional_3.cpp

        codes/curs_6_7/bellman_ford.cpp
        codes/graph.cpp
        )
