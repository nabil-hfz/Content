cmake_minimum_required(VERSION 3.21)
project(codes)

set(CMAKE_CXX_STANDARD 14)

add_executable(codes detect_cycle_dfs_2.cpp kosaraju_scc_dfs.cpp detect_cycle_dfs.cpp topological_sorting.cpp biconnected_graph.cpp "articulation_points_or_cut_vertices_in_graph.cpp" biconnected_components.cpp)
