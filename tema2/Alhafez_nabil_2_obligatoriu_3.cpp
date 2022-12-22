//#include <iostream>
//#include <list>
//#include <vector>
//#include <stack>
//#include <algorithm>
//#include <queue>
//#include <fstream>
//#include <cmath>
//#include <limits.h>
//// C++ Program to find Dijkstra's shortest path using
//// priority_queue in STL
//#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);
//
//using namespace std;
//
//
//#define MAXN 2011
//#define point pair<double, double>
//#define costul first
//#define loc second
//#define INF 2000000000.0
//
//using namespace std;
//
//// LUI DIJ O( N * LOG N ) PROB
//class Solution {
//public:
//    typedef pair<double, int> pdi;
//    double *prob;
//
//    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
//        double destProb, maxim = double(INT_MIN);
//        vector<vector<pair<int, double>>> adjList(n);
//        int i, j, src, dest;
//        priority_queue<pdi, vector<pdi>> pq;
//
//        for (i = 0; i < edges.size(); i++) {
//            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
//            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
//        }
//        prob = new double[n];
//        for (i = 0; i < n; i++) prob[i] = maxim;
//
//        pq.push({1, start});
//        prob[start] = 1;
//        while (!pq.empty()) {
//            src = pq.top().second;
//            pq.pop();
//
//            for (j = 0; j < adjList[src].size(); j++) {
//                dest = adjList[src][j].first;
//                destProb = adjList[src][j].second;
//                if (prob[src] != maxim && (prob[src] * destProb) > prob[dest]) {
//                    prob[dest] = prob[src] * destProb;
//                    pq.push({prob[dest], dest});
//                }
//            }
//        }
//
//        return prob[end] == maxim ? 0 : prob[end];
//    }
//};