////#include <bits/stdc++.h>
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <cmath>
//#include <climits>
//#include <queue>
//
//using namespace std;
//
//const int MAX = 1e6;
//#define  ll long long
//
//
////vector <vector<int>> capacitate;
////
////int path[MAXI];
////bool vizitat[MAXI];
////
////int M, N;
////ll pathLength;
//
///// ======================== Bellmanford  O(V * E^2)
///// https://www.youtube.com/watch?v=LdOnanfc5TM&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=33
//// DFS, BFS, DIJKSTRA
////int getPath(int startNode, int targetNode, int curLen, int maxCap) {
////    path[curLen] = startNode;
////
////    if (startNode == targetNode) {
////        pathLength = curLen + 1;
////        return maxCap;
////    }
////
////    int res = 0;
////    vizitat[startNode] = true;
////
////    for (int i = 0; i < N; ++i) {
////        if (vizitat[i] || capacitate[startNode][i] <= 0) continue;
////        res = getPath(i, targetNode, curLen + 1, min(maxCap, capacitate[startNode][i]));
////        if (res > 0) break;
////    }
////
////    return res;
////}
////
////ll maxFlow(int startNode, int endNode) {
////    ll totalFlow = 0;
////
////    while (true) {
////        memset(vizitat, false, sizeof (vizitat));
////        int newFlow = getPath(startNode, endNode, 0, INT_MAX);
////
////        if (newFlow <= 0)break; // once there is no paths anymore stop the algo
////
////        for (int i = 1; i < pathLength; ++i) {
////            int m = path[i - 1];
////            int n = path[i];
////            capacitate[m][n] -= newFlow;
////            capacitate[n][m] += newFlow;
////        }
////        totalFlow += newFlow;
////    }
////
////    return totalFlow;
////}
//
//
///// ======================== Capacity Scaling   O(E^2 * Log(U)) or O(E * V Log(U)) if SHORTEST PATH
//// U = MAXI Value ( Capacities)
//// delta = smallest power of 2 less than or equal to U.
//// https://www.youtube.com/watch?v=1ewLrXUz4kk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=40
//// repeatedly delta = delta / 2
//vector<vector<ll>> capacitate;
//vector<vector<int>> graph;
//vector<int> parent;
//int remainingCapacity = 0;
//int M, N;
//
//vector<pair<int, int>> taieturaMinima;
//
//
///// TLE
////ll dfs(int s, int t, int flow) {
////
////
////    if (s == t) return flow;
////
////    visited[s] = true;
////    for (int i = 0; i < capacitate[s].size(); ++i) {
////        int cap = capacitate[s][i];
////        if (cap >= delta && !visited[i]) {
////            parent[i] = s;
////            ll bottleNeck = dfs(i, t, min(cap, flow));
////            if (bottleNeck > 0) {
////                return bottleNeck;
////            }
////        }
////
////    }
////
////
////    return 0;
////}
//
//// OPTIMIZARATA
//bool bfs(int s, int t) {
//    cout << "BFS" << endl;
//    vector<bool> visited(N + 1);
//    queue<int> q;
//    q.push(s);
//    visited[s] = true;
//    parent[s] = -1;
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
////        cout << "while BFS " <<endl;
//        for (auto v: graph[u]) {
//            ll weight = capacitate[u][v];
//            if (!visited[v] && weight > 0) {
//                parent[v] = u;
//                if (v == t)
//                    return true;
//                visited[v] = true;
//                q.push(v);
//            } else if (!visited[v] && capacitate[u][v] == 0)
//                taieturaMinima.emplace_back(u, v);
//        }
//    }
//    return false;
//}
////4 5
////1 2 3
////1 3 5
////2 4 6
////3 4 4
////3 2 3
//ll maxFlow(int s, int t) {
//    ll flow = 0;
//
//
//    bool result = false;
//    do {
//        result = bfs(s, t);
//        for (auto node: graph[N]) {
//            if (parent[node]) { // daca nodului i-a fost setat un parinte (adica daca a fost luat in considerare in BFS)
//                parent[N] = node; // se seteaza nodul curent ca fiind parintele nodului destinatie
//
//                ll newFlow = LLONG_MAX;
//
//                for (int v = t; v != s; v = parent[v]) {
//                    int u = parent[v];
//                    newFlow = min(newFlow, capacitate[u][v]);
//                }
//
//                for (int v = t; v != s; v = parent[v]) {
//                    int u = parent[v];
//                    capacitate[u][v] -= newFlow;
//                    capacitate[v][u] += newFlow;
//
//                }
//
//                flow += newFlow;
//            }
//        }
//    } while (result);
//
//
//    return flow;
//}
//
////4 5
////1 2 3
////1 3 5
////2 4 6
////3 4 4
////3 2 3
//int main() {
////    ifstream cin("maxflow.in");
////    ofstream cout("maxflow.out");
//
//    cin >> N >> M;
//
//    capacitate.resize(N + 1, vector<ll>(N + 1));
//
//    graph.resize(N + 1);
//    parent.resize(N + 1, 0);
//
//    for (int i = 0; i < M; ++i) {
//        int x, y;
//        ll z;
//        cin >> x >> y >> z;
//        graph[x].push_back(y);
//        graph[y].push_back(x);
//        capacitate[x][y] = z;
//    }
//
//    cout << maxFlow(1, N);
//
//    //for(auto x:taietura_minima)
//    //    cout<<x.first<<" "<<x.second<<'\n';
////
//
////
////    cin >> N >> M;
////    capacitate.resize(N + 1, vector<ll>(N + 1));
////
////    graph.resize(N + 1);
////    parent.resize(N + 1);
////    visited.resize(N + 1);
////
////    for (int i = 0; i < M; ++i) {
////        int x, y;
////        ll z;
////        cin >> x >> y >> z;
////        graph[x].push_back(y);
////        graph[y].push_back(x);
////        capacitate[x][y] = z;
////    }
////    cout << maxFlow(1, N);
//
//
//    return 0;
//}