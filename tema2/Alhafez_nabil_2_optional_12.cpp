#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <fstream>
#include <cmath>
#include <limits.h>
#include <set>

#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);

using namespace std;


#define point pair<double, double>
#define costul first
#define loc second
const int INF = 2000000000;

class Solution {
public:
    //The optimal way for i have tasted is bellman with k+1 iterations ( Stops ).
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {

        vector<int> c(n, INF);
        c[src] = 0;

        for (int z = 0; z <= k; z++) {
            vector<int> cons(c);
            for (auto data: flights)
                cons[data[1]] = min(cons[data[1]], c[data[0]] + data[2]);
            c = cons;
        }
        return c[dst] == INF ? -1 : c[dst];
    }
};