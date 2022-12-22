#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

class Solution {
public:
    bool dfs(int nod, vector<vector<int>> adj, vector<int> visited, vector<int> result) {
        visited[nod] = 1;
        for (int i = 0; i < adj[nod].size(); i++) {
        int vecin = adj[nod][i];
            if (visited[vecin] == 1)return false;// adica nevizitat dar inca nu e procesat
            if (visited[vecin] == 0) {// adica nevizitat
                if (!dfs(vecin, adj, visited, result))
                    return false;
            }
        }
        visited[nod] = 2; // adica nevizitat
        result.push_back(nod);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> result;
        bool ok = true;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, result)) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
            return vector<int>();
        return result;
    }
};