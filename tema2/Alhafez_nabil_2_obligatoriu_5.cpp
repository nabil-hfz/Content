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
//
//#define MAXN 2011
//#define point pair<double, double>
//#define costul first
//#define loc second
//#define INF 2000000000;
//// http://infoarena.ro/problema/catun
//
//
//using namespace std;
//
//
//const int MAXSIZE = 36001;
//const int oo = 0x3f3f3f3f;
//
//ifstream in("easygraph.in");
//ofstream out("easygraph.out");
//
//int t, n, m, cost[15001];
//bool viz[15001];
//
//vector<int> G[15001];
//long long dist_mx[15001], mx = LLONG_MIN;
///// Dacă o anumită submulțime de noduri formează o secvență continuă în
///// sortarea topologică, asta nu înseamnă că formează și lanț  *_*.
////  O( V + E )
//void dfs(int s) {
//    viz[s] = true;
//    dist_mx[s] = cost[s];
//    for (int i = 0; i < (int)G[s].size(); i++) {
//        int vecin = G[s][i];
//        if (!viz[vecin])
//            dfs(vecin);
//        //castigul pentru a merge in vecin este calculat astfel
//        //val nodului curent + valoarea maxima curenta pornid din vecin
//        dist_mx[s] = max(dist_mx[s], dist_mx[vecin] + cost[s]);
//    }
//    mx = max(mx, dist_mx[s]);
//}
//
//int main() {
//    in >> t;
//    for (int i = 1; i <= t; i++) {
//        in >> n >> m;
//        int x, y;
//        for (int j = 1; j <= n; j++) {
//            viz[j] = false;
//            dist_mx[j] = 0;
//            G[j].clear();
//            in >> x;
//            cost[j] = x;
//        }
//        for (int j = 1; j <= m; j++) {
//            in >> x >> y;
//            G[x].push_back(y);
//        }
//        for (int j = 1; j <= n; j++)
//            if (!viz[j])
//                dfs(j);
//        out << mx << '\n';
//        mx = LLONG_MIN;
//    }
//    return 0;
//}