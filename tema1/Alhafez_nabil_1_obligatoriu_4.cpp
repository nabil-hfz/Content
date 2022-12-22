//#include "/usr/local/include/bits/stdc++.h"
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int siz = 1e5 + 9;


int n, m;
int id;
int visited[siz], low[siz];
bool visited2[siz];
stack<int> stiva;
vector<int> adj[siz];
vector<vector<int> > ctc;



void dfs(int node) {
    visited[node] = low[node] = ++id;
    visited2[node] = true;
    stiva.push(node);

    for (auto u: adj[node]) {
        if (!visited[u]) dfs(u);
        if (visited2[u]) low[node] = min(low[node], low[u]);

    }

    if (low[node] == visited[node]) {
        int top;
        vector<int> v;
        do {
            top = stiva.top();
            stiva.pop();
            visited2[top] = false;
            v.push_back(top);
        } while (top != node);
        ctc.push_back(v);
    }
}



 int main9() {
//    HURRY_UP;
    fin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++i) {
        fin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i);
    }
     fout << ctc.size() << "\n";

     for (auto v: ctc) {
         for (auto x: v)
             fout << x << " ";
         fout << "\n";
     }
    return 0;
}
