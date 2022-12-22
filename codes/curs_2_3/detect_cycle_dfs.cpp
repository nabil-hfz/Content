//
// Created by Nabil Alhafez on 29.10.2022.
//

// A C++ Program to detect cycle in a Graph1
#include<bits/stdc++.h>

using namespace std;

class Graph1 {
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[]); // used by isCyclic()
public:
    Graph1(int V); // Constructor
    void addEdge(int v, int w); // to add an edge to Graph1
    bool isCyclic(); // returns true if there is a cycle in this Graph1
};

Graph1::Graph1(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph1::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}
 bool *recStack;
// This function is a variation of DFSUtil() in
// https://www.geeksforgeeks.org/archives/18212
bool Graph1::isCyclicUtil(int v, bool visited[]) {
    if (visited[v] == false) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i, visited ))
                return true;
            else if (recStack[*i])
                return true;
        }

    }
//    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

// Returns true if the Graph1 contains a cycle, else false.
// This function is a variation of DFS() in
// https://www.geeksforgeeks.org/archives/18212
bool Graph1::isCyclic() {
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    recStack = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(i, visited))
            return true;

    return false;
}

int main1() {
    // Create a Graph1 given in the above diagram
    Graph1 g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph1 contains cycle";
    else
        cout << "Graph1 doesn't contain cycle";
    return 0;
}
