////#include <bits/stdc++.h>
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int N = 4;
//vector<bool> viz(N, false);
//vector<int> tata(N);
//vector<vector<int>> adj(N);
//
//void dfs(int x) {
//    viz[x] = true;
//    for (auto y: adj[x]) {
//        if (!viz[y]) {
//            tata[y] = x;
//            dfs(y);
//        } else if (tata[y] != x) {//xy nu e muchie din arbore => este de intoarcere
//            // it should be in reversed order
//            int v = x;
//            cout << x << " => ";
//            while (v != y) {
//                cout << v << " => ";
//                v = tata[v];
//            }
//            cout << y;
//        }
//        cout << endl;
//        return;
//
//    }
//}
//
//int main2() {
//    std::cout << "it should be in reversed order" << std::endl;
//    adj[0].push_back(1);
//    adj[0].push_back(2);
//    adj[1].push_back(2);
//    adj[2].push_back(0);
//    adj[2].push_back(3);
//    adj[3].push_back(3);
//
//    for (int i = 0; i < N; ++i)
//        dfs(i);
//
//
//    return 0;
//}
