////
//// Created by Nabil Alhafez on 30.10.2022.
////
//
//// A C++ program to find if a given undirected Graph7 is
//// biconnected
//#include<iostream>
//#include <list>
//
//#define NIL -1
//using namespace std;
//
////    An undirected Graph7 is called Biconnected if there are two vertex-disjoint paths between any two vertices.
////    In a Biconnected Graph7, there is a simple cycle through any two vertices.
////    By convention, two nodes connected by an edge form a biconnected Graph7,
////    but this does not verify the above properties.
////    For a Graph7 with more than two vertices, the above properties must be there for it to be Biconnected.
////    Or in other words:
////    A Graph7 is said to be Biconnected if:
////    It is connected, i.e. it is possible to reach every vertex from every other vertex, by a simple path.
////    Even after removing any vertex the Graph7 remains connected.
//
////    How to find if a given Graph7 is Biconnected or not?
////    A connected Graph7 is Biconnected if it is connected and doesn’t have any Articulation Point.
////    We mainly need to check two things in a Graph7.
////    1- The Graph7 is connected.
////    2- There is no articulation point in Graph7.
////    We start from any vertex and do DFS traversal. In DFS traversal, we check if there is any articulation point.
////    If we don’t find any articulation point, then the Graph7 is Biconnected.
////    Finally, we need to check whether all vertices were reachable in DFS or not.
////    If all vertices were not reachable, then the Graph7 is not even connected.
//
//// A class that represents an undirected Graph7
//class Graph7 {
//    int V; // No. of vertices
//    list<int> *adj; // A dynamic array of adjacency lists
//    bool isBCUtil(int v, bool visited[], int disc[], int low[],
//                  int parent[]);
//
//public:
//    Graph7(int V); // Constructor
//    void addEdge(int v, int w); // to add an edge to Graph7
//    bool isBC(); // returns true if Graph7 is Biconnected
//};
//
//Graph7::Graph7(int V) {
//    this->V = V;
//    adj = new list<int>[V];
//}
//
//void Graph7::addEdge(int v, int w) {
//    adj[v].push_back(w);
//    adj[w].push_back(v); // Note: the Graph7 is undirected
//}
//
//// A recursive function that returns true if there is an articulation
//// point in given Graph7, otherwise returns false.
//// This function is almost same as isAPUtil() here ( http://goo.gl/Me9Fw )
//// u --> The vertex to be visited next
//// visited[] --> keeps track of visited vertices
//// disc[] --> Stores discovery times of visited vertices
//// parent[] --> Stores parent vertices in DFS tree
//bool Graph7::isBCUtil(int u, bool visited[], int disc[], int low[], int parent[]) {
//    // A static variable is used for simplicity, we can avoid use of static
//    // variable by passing a pointer.
//    static int time = 0;
//
//    // Count of children in DFS Tree
//    int children = 0;
//
//    // Mark the current node as visited
//    visited[u] = true;
//
//    // Initialize discovery time and low value
//    disc[u] = low[u] = ++time;
//
//    // Go through all vertices adjacent to this
//    list<int>::iterator i;
//    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
//        int v = *i; // v is current adjacent of u
//
//        // If v is not visited yet, then make it a child of u
//        // in DFS tree and recur for it
//        if (!visited[v]) {
//            children++;
//            parent[v] = u;
//
//            // check if subGraph7 rooted with v has an articulation point
//            if (isBCUtil(v, visited, disc, low, parent))
//                return true;
//
//            // Check if the subtree rooted with v has a connection to
//            // one of the ancestors of u
//            // so here after going to the latest connected child of this subtree
//            // rooted with v we change the value of the current lowest cost of vertex u
//            // to be minimum between the lowest of u and lowest of v this means that one of its descendant
//            // of this subtree rooted with v has a connection to one of the ancestor of u,
//            // so we have a smaller value, and we have to updated
//            low[u] = min(low[u], low[v]);
//
//            // u is an articulation point in following cases:
//
//            // (1) u is root of DFS tree and has two or more children.
//            if (parent[u] == NIL && children > 1)
//                return true;
//
//            // (2) If u is not root and low value of one of its child is
//            // more than discovery value of u.
//            if (parent[u] != NIL && low[v] >= disc[u])
//                return true;
//        }
//
//            // Update low value of u for parent function calls.
//            // we check if the current parent of u is not this adjacent neighbour v
//            // then surly this is a back edge from current vertex u to one of the ancestor of its parent which is v
//            // so we have to update the lowest cost of the current vertex u between two ancestor desc v time and
//            // lowest value of the current vertex u.
//        else if (v != parent[u])
//            low[u] = min(low[u], disc[v]);
//    }
//    return false;
//}
//
//// The main function that returns true if Graph7 is Biconnected,
//// otherwise false. It uses recursive function isBCUtil()
//bool Graph7::isBC() {
//    // Mark all the vertices as not visited
//    bool *visited = new bool[V];
//    int *disc = new int[V];
//    int *low = new int[V];
//    int *parent = new int[V];
//
//    // Initialize parent and visited, and ap(articulation point)
//    // arrays
//    for (int i = 0; i < V; i++) {
//        parent[i] = NIL;
//        visited[i] = false;
//    }
//
//    // Call the recursive helper function to find if there is an articulation
//    // point in given Graph7. We do DFS traversal starting from vertex 0
//    if (isBCUtil(0, visited, disc, low, parent) == true)
//        return false;
//
//    // Now check whether the given Graph7 is connected or not. An undirected
//    // Graph7 is connected if all vertices are reachable from any starting
//    // point (we have taken 0 as starting point)
//    for (int i = 0; i < V; i++)
//        if (visited[i] == false)
//            return false;
//
//    return true;
//}
//
//// Driver program to test above function
//int main7() {
//    // Create Graph7s given in above diagrams
//    Graph7 g1(2);
//    g1.addEdge(0, 1);
//    g1.isBC() ? cout << "Yes\n" : cout << "No\n";
//
//    Graph7 g2(5);
//    g2.addEdge(1, 0);
//    g2.addEdge(0, 2);
//    g2.addEdge(2, 1);
//    g2.addEdge(0, 3);
//    g2.addEdge(3, 4);
//    g2.addEdge(2, 4);
//    g2.isBC() ? cout << "Yes\n" : cout << "No\n";
//
//    Graph7 g3(3);
//    g3.addEdge(0, 1);
//    g3.addEdge(1, 2);
//    g3.isBC() ? cout << "Yes\n" : cout << "No\n";
//
//    Graph7 g4(5);
//    g4.addEdge(1, 0);
//    g4.addEdge(0, 2);
//    g4.addEdge(2, 1);
//    g4.addEdge(0, 3);
//    g4.addEdge(3, 4);
//    g4.isBC() ? cout << "Yes\n" : cout << "No\n";
//
//    Graph7 g5(3);
//    g5.addEdge(0, 1);
//    g5.addEdge(1, 2);
//    g5.addEdge(2, 0);
//    g5.isBC() ? cout << "Yes\n" : cout << "No\n";
//
//    return 0;
//}
