#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

enum GraphType {
    WEIGHTED_DIRECTED, WEIGHTED_UNDIRECTED, UNWEIGHTED_DIRECTED, UNWEIGHTED_UNDIRECTED,
    TEST
};


class Graph {
public:
    map<int, string> nodeMap;


    GraphType type;
    int V; // Number of vertices
    int E; // Number of Edges
    vector<vector<pair<int, int>>> adj; // Adjacency list (for weighted graphs)
    vector<vector<int>> adj_unw; // Adjacency list (for unweighted graphs)


    Graph(int V, int E, GraphType type) : V(V), E(E), type(type) {

        if (type == WEIGHTED_DIRECTED || type == WEIGHTED_UNDIRECTED) {
            adj.resize(V);
        } else {
            adj_unw.resize(V);
        }

        nodeMap[WEIGHTED_DIRECTED] = "WEIGHTED_DIRECTED";
        nodeMap[WEIGHTED_UNDIRECTED] = "WEIGHTED_UNDIRECTED";
        nodeMap[UNWEIGHTED_DIRECTED] = "UNWEIGHTED_DIRECTED";
        nodeMap[UNWEIGHTED_UNDIRECTED] = "UNWEIGHTED_UNDIRECTED";
        nodeMap[TEST] = "TEST";
    }

    void addEdge(int u, int v, int w = 0) {
        if (type == WEIGHTED_DIRECTED) {
            adj[u].push_back({v, w});
        } else if (type == WEIGHTED_UNDIRECTED) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        } else if (type == UNWEIGHTED_DIRECTED) {
            adj_unw[u].push_back(v);
        } else {
            adj_unw[u].push_back(v);
            adj_unw[v].push_back(u);
        }
    }

    void readFromFile(const string &fileName) {
        ifstream input_stream(fileName);
        if (!input_stream) cerr << "Can't open input file!";
        bool isDone = false;
        string line;
        while (getline(input_stream, line) && !isDone) {
            if (line.find(nodeMap[type]) != string::npos) {
                while (getline(input_stream, line) && !isDone) {
                    if (line.find("start") != string::npos) {
                        if (type == WEIGHTED_DIRECTED || type == WEIGHTED_UNDIRECTED) {
                            while (getline(input_stream, line)) {
                                cout << "1 temp " << line << endl;
                                if (line.find("end") != string::npos) {
                                    isDone = true;
                                    break;
                                }
                                addEdge(line[0] - '0', line[2] - '0', line[4] - '0');
                            }

                        } else {
                            while (getline(input_stream, line)) {
                                cout << "2 temp " << line << endl;
                                if (line.find("end") != string::npos) {
                                    isDone = true;
                                    break;
                                }
                                addEdge(line[0] - '0', line[2] - '0');
                            }

                        }
                    }

                }
            }

        }
        input_stream.close();
    }

    void printGraph() {
        if (type == WEIGHTED_DIRECTED || type == WEIGHTED_UNDIRECTED) {
            for (int i = 0; i < V; i++) {
                cout << i << ": ";
                for (auto edge: adj[i]) {
                    cout << edge.first << "(" << edge.second << ") ";
                }
                cout << endl;
            }
        } else {
            for (int i = 0; i < V; i++) {
                cout << i << ": ";
                for (auto neighbor: adj_unw[i]) {
                    cout << neighbor << " ";
                }
                cout << endl;
            }
        }
    }

    void updateEdgesLen(int e) {
        this->E = e;
    }
};

int main() {
    Graph g(5, 4, WEIGHTED_DIRECTED);
    string fileName = "/Users/nabil.alhafez/Univeristetea/Anul_2/algo_fund/Content/test-cases/edges.txt";
    g.readFromFile(fileName);
    g.printGraph();

    return 0;
}