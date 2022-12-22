//
// Created by Nabil Alhafez on 30.10.2022.
//
//

//    Given a grapth, the task is to find the articulation points in the given graph.
//    Note: A vertex in an undirected connected graph is an articulation point (or cut vertex)
//    if removing it (and edges through it) disconnects the graph.
//    Articulation points represent vulnerabilities in a connected network – single points
//    whose failure would split the network into 2 or more components.
//    They are useful for designing reliable networks.
//    For a disconnected undirected graph, an articulation point is a vertex removal
//    which increases the number of connected components.

//    The idea is to use DFS (Depth First Search). In DFS, follow vertices in a tree form called the DFS tree.
//    In the DFS tree, a vertex u is the parent of another vertex v, if v is discovered by u.
//    In DFS tree, a vertex u is an articulation point if one of the following two conditions is true.
//    u is the root of the DFS tree, and it has at least two children.
//    u is not the root of the DFS tree, and it has a child v such that no vertex in
//    the subtree rooted with v has a back edge to one of the ancestors in DFS tree of u.

//    Follow the below steps to Implement the idea:
//
//    Do DFS traversal of the given graph
//    In DFS traversal, maintain a parent[] array where parent[u] stores the parent of vertex u.
//    To check if u is the root of the DFS tree and it has at least two children. For every vertex, count children. If the currently visited vertex u is root (parent[u] is NULL) and has more than two children, print it.
//    To handle a second case where u is not the root of the DFS tree and it has a child v such that no vertex in the subtree rooted with v has a back edge to one of the ancestors in DFS tree of u maintain an array disc[] to store the discovery time of vertices.
//    For every node u, find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from the subtree rooted with u. So we maintain an additional array low[] such that:
//    low[u] = min(disc[u], disc[w]) , Here w is an ancestor of u and there is a back edge from some descendant of u to w.

// C++ program to find articulation points in an undirected graph
#include <bits/stdc++.h>

using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum discovery time) that can be reached
// from subtree rooted with current vertex.
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points

void APUtil(vector<int> adj[], int u, bool visited[],
            int discovery[], int low[], int &time, int parent,
            bool isAP[]) {
    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    discovery[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    for (auto v: adj[u]) {
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v]) {
            children++;
            APUtil(adj, v, visited, discovery, low, time, u, isAP);

            // Check if the subtree rooted with v has
            // a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If u is not root and low value of one of
            // its child is more than discovery value of u.
            if (parent != -1 && low[v] >= discovery[u])
                isAP[u] = true;
        }

            // Update low value of u for parent function calls.
        else if (v != parent)
            low[u] = min(low[u], discovery[v]);
    }

    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void AP(vector<int> adj[], int V) {
    int *discovery = new int[V]{0};
    int low[V];

    bool *visited = new bool[V]{false};
    bool *isAP = new bool[V]{false};
    int time = 0, parent = -1;

    // Adding this loop so that the
    // code works even if we are given
    // disconnected graph
    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, discovery, low,
                   time, parent, isAP);

    // Printing the APs
    for (int u = 0; u < V; u++)
        if (isAP[u] == true)
            cout << u << " ";
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main6() {
    // Create graphs given in above diagrams
    cout << "Articulation points in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    AP(adj1, V);

    cout << "\nArticulation points in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 1, 3);
    addEdge(adj2, 2, 3);
    AP(adj2, V);

    cout << "\nArticulation points in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    AP(adj3, V);

    return 0;
}
