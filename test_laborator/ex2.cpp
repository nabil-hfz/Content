//#include <codes/graph.cpp>
//
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <queue>
//
//int N, M;
//GraphType graphType = GraphType::WEIGHTED_DIRECTED;
//
//int main2() {
//
//   string fileName = "../test-cases/ex2.txt";
////    ifstream cin("transport2.in");
////    ofstream cout("transport2.out");
//
//    cin >> N >> M;
//
//    Graph g(N, M, graphType);//    g.readFromFile(fileName);
//
//    for (int i = 0; i < M; ++i) {
//        int u, v, w;
//        if (graphType == WEIGHTED_DIRECTED || graphType == WEIGHTED_UNDIRECTED) {
//            cin >> u >> v >> w;
//            g.addEdge(u, v, w);
//        } else {
//            cin >> u >> v;
//            g.addEdge(u, v);
//        }
//    }
//
//    g.printGraph();
//
//    return 0;
//}
