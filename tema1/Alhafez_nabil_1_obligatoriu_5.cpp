
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <queue>
#include <list>

#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");


using namespace std;

void add_edge(vector<int> adj[], int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int v,
         int dist[]) {
    list<int> queue;

    bool visited[v];


    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }


    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);


    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                queue.push_back(adj[u][i]);

//                // We stop BFS when we find
//                // destination.
//                if (adj[u][i] == dest)
//                    return true;
            }
        }
    }

    return false;
}

void printShortestDistance(vector<int> adj[], vector<int> control, int v) {

    int dist[v];
    vector<int> res(v, 1e5);
    for (int i = 0; i < control.size(); i++) {
        BFS(adj, control[i], v, dist);
        for (int j = 0; j < v; j++) {
            res[j] = min(res[j], dist[j]);
        }
    }


    for (int j = 0; j < v; j++) cout << res[j] << ' ';


}

int main() {
    fin;

    int v, m;
    v = 8;
    m = 11;


    cin >> v >> m;
    vector<int> adj[v];
    vector<int> control(2, 0);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        add_edge(adj, x, y);

    }
    cin >> control[0] >> control[1];

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);

//    int source = 0, dest = 7;

    printShortestDistance(adj, control, v);
    fout;
    return 0;
}