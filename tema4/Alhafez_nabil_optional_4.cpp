//#include <bits/stdc++.h>
////#include<iostream>
////#include<vector>
////#include<queue>
////#include<algorithm>
//#define arrSize 2020
//
//using namespace std;
//int tata[arrSize], capacitate[arrSize][arrSize];
//vector<vector<int>> adj;
//int n, x;
//
//bool bfs() {
//    queue<pair<int, int>> q;
//    for (int i = 1; i <= 2 * n + 1; i++)
//        tata[i] = -1;
//    q.push({0, INT_MAX});
//    tata[0] = -2;
//    while (!q.empty()) {
//        int u = q.front().first;
//        int flow = q.front().second;
//        q.pop();
//        for (auto v: adj[u])
//            if (capacitate[u][v] > 0 and tata[v] == -1) {
//                int new_flow = min(flow, capacitate[u][v]);
//                q.push({v, new_flow});
//                tata[v] = u;
//                if (v == 2 * n + 1)
//                    return new_flow;
//            }
//    }
//    return 0;
//}
//
//int main() {
//    int total = 0, flow;
//    cin >> n;
//    adj.resize(10 * n + 10);
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> x;
//            if (x == 1) {
//                adj[i].push_back(n + j);
//                adj[n + j].push_back(i);
//                capacitate[i][n + j] = 1;
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        adj[0].push_back(i);
//        adj[i].push_back(0);
//        capacitate[0][i] = 1;
//
//        adj[n + i].push_back(2 * n + 1);
//        adj[2 * n + 1].push_back(n + i);
//        capacitate[n + i][2 * n + 1] = 1;
//    }
//
//
//    while (flow = bfs()) {
//        int v = 2 * n + 1;
//        while (v != 0) {
//            int prev = tata[v];
//            capacitate[prev][v] -= flow;
//            capacitate[v][prev] += flow;
//            v = prev;
//        }
//        total += flow;
//    }
//
//    vector<int> poz;
//    poz.resize(n + 1);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            if (capacitate[n + j][i] != 0)
//                poz[i] = j;
//    if (total == n) {
//        for (int i = 1; i <= n; i++) {
//            if (poz[i] == i)
//                continue;
//            int loc = find(poz.begin() + 1, poz.end(), i) - poz.begin();
//            cout << "R " << i << " " << loc;
//            swap(poz[i], poz[loc]);
//
//        }
//    } else
//        cout << -1;
//
//}