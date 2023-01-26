//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int n, m;
//vector<vector<int>> graph;
//vector<vector<int>> graph_t;
//vector<vector<int>> graph_rezult;
//vector<int> viz;
//vector<int> dis;
//stack<int> st;
//vector<int> componenta;
//vector<vector<int>> componente_tari;
//
//void dfs(int node) {
//    viz[node] = 1;
//    for (int i = 0; i < graph[node].size(); i++) {
//        if (viz[graph[node][i]] == 0) {
//            dfs(graph[node][i]);
//
//        }
//    }
//    st.push(node);
//}
//
//void dfs_t(int node) {
//    componenta.push_back(node);
//    viz[node] = 1;
//    for (int i = 0; i < graph_t[node].size(); i++) {
//        if (viz[graph_t[node][i]] == 0) {
//            dfs_t(graph_t[node][i]);
//
//        }
//    }
//}
//
//void dfs_dis(int node) {
//    viz[node] = 1;
//    for (int i = 0; i < graph_rezult[node].size(); i++) {
//        if (viz[graph_rezult[node][i]] == 0) {
//
//            dis[graph_rezult[node][i]] = dis[node] + 1;
//            dfs_dis(graph_rezult[node][i]);
//        }
//    }
//}
//
//int main() {
////    ifstream cin("graf.in");
//    cin >> n >> m;
//    graph.resize(n + 1);
//    graph_t.resize(n + 1);
//    graph_rezult.resize(n + 1);
//    viz.resize(n + 1, 0);
//    dis.resize(n + 1, 0);
//
//    for (int i = 0; i < m; i++) {
//        int x, y;
//        cin >> x >> y;
//        graph[x].push_back(y);
//        graph[y].push_back(x);
//
//        graph_t[y].push_back(x);
//        graph_t[x].push_back(y);
//
//        graph_rezult[y].push_back(x);
//        graph_rezult[x].push_back(y);
//
//    }
//
//    for (int i = 1; i <= n; i++) {
//        if (viz[i] == 0) {
//            dfs(i);
//        }
//    }
//    fill(viz.begin(), viz.end(), 0);
//
//
//    while (!st.empty()) {
//        int node = st.top();
//        st.pop();
//        if (viz[node] == 0) {
//            dfs_t(node);
//            componente_tari.push_back(componenta);
//            componenta.clear();
//        }
//
//    }
//    /*
//6 4
//1 3
//1 5
//3 5
//2 4
//6
//     */
////    for (int i = 1; i <= n; ++i) {
////        if (!viz[i]) {
////            dfs_t(i);
////            componente_tari.push_back(componenta);
////            componenta.clear();
////        }
////    }
//
////    cout << "Componente tari conexe gasite - " << componente_tari.size() << ":" << endl;
////    for (auto &comp: componente_tari) {
////        cout << '\n';
////        for (auto &i: comp)
////            cout << i << ' ';
////    }
//
//    for (int i = 1; i < componente_tari.size(); ++i) {
//        int x = componente_tari[0][0];
//        int y = componente_tari[i][0];
//
//        graph_rezult[x].push_back(y);
//        graph_rezult[y].push_back(x);
//        cout << x << ' ' << y << endl;
//
//    }
//
//
//    int s;
//    cin >> s;
//    fill(viz.begin(), viz.end(), 0);
//    fill(dis.begin(), dis.end(), 0);
//
//    dfs_dis(s);
//
//    int max = *max_element(dis.begin(), dis.end());
//
//    cout << max;
//    return 0;
//}
//
