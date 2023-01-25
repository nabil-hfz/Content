//#include <iostream>
//#include <list>
//#include <vector>
//#include <stack>
//#include <algorithm>
//#include <queue>
//#include <fstream>
//#include <cmath>
//#include <limits.h>
//#include <set>
//
//#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);
//
//using namespace std;
//
//int find(vector<int> &parent, int i) {
//    while (parent[i] != i)
//        i = parent[i];
//    return i;
//}
//
//void union1(vector<int> &parent, int i, int j) {
//    int a = find(parent, i);
//    int b = find(parent, j);
//    parent[a] = b;
//}
//
//class Solution {
//public:
////    O(N * N)
//    int minCostConnectPoints(vector<vector<int>> &points) {
//        vector<int> parent;
//        vector<pair<int, pair<int, int>>> v;
//        int ans = 0;
//        for (int i = 0; i < points.size(); i++) {
//            parent.push_back(i);
//            for (int j = i + 1; j < points.size(); j++) {
//                int add = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                v.push_back({add, {i, j}});
//            }
//        }
//        sort(v.begin(), v.end());
//
//        for (int i = 0; i < v.size(); i++) {
//            int x = v[i].second.first;
//            int y = v[i].second.second;
//            if (find(parent, x) == find(parent, y))
//                continue;
//            union1(parent, x, y);
//
//            ans += v[i].first;
//        }
//        return ans;
//    }
//};