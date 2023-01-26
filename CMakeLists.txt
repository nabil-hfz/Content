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

        test_laborator/ex1.cpp
        test_laborator/ex2.cpp
        test_laborator/ex3.cpp

        codes/curs_6_7/bellman_ford.cpp
        codes/curs_6_7/dijkstra.cpp
        codes/graph.cpp
        codes/curs_2_3/detect_cycle_dfs_2.cpp
        codes/curs_2_3/kosaraju_scc_dfs.cpp
        codes/curs_2_3/detect_cycle_dfs.cpp
        codes/curs_2_3/topological_sorting.cpp
        codes/curs_2_3/biconnected_graph.cpp
        codes/curs_2_3/articulation_points_or_cut_vertices_in_graph.cpp
        codes/curs_2_3/biconnected_components.cpp
        Model_Colocviu/my_solve/ex1.cpp
        Model_Colocviu/my_solve/ex2.cpp
        Model_Colocviu/my_solve/ex3.cpp



        codes/sheets_algo/Bellman_Ford_2.cpp
        codes/sheets_algo/Componente_Tari_Conexe_Kosaraju_2.cpp
        codes/sheets_algo/Dijkstra_2.cpp
        codes/sheets_algo/Graf_Bipartit_2.cpp
        codes/sheets_algo/Kruskal_APM_2.cpp
        codes/sheets_algo/Muchii_Puncte_Critice_2.cpp
        codes/sheets_algo/Parcurgeri_Graf_Neorientat_2.cpp
        codes/sheets_algo/Parcurgeri_Graf_Orientat_2.cpp
        codes/sheets_algo/Sortare_Topologica_2.cpp


        )
