//#include <iostream>
//#include <vector>
//#include <stack>
//#include <fstream>
//#include <cmath>
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
//#define INF 2000000000.0
//
//point centrale[MAXN], blocuri[MAXN];
//double D[MAXN];
//bool Ok[MAXN];
//double Ans, minim;
//int i, j, N, M, poz;
//
//inline double dist(const point &A, const point &B) {
//    return sqrt((A.costul - B.costul) * (A.costul - B.costul) + (A.loc - B.loc) * (A.loc - B.loc));
//}
//
///// LUI PRIM O(2 ^ N) -_-
//int main() {
//    freopen("retea2.in", "r", stdin);
//    freopen("retea2.out", "w", stdout);
////
//
//    cin >> N >> M;
//    for (i = 1; i <= N; ++i)
//        cin >> centrale[i].costul >> centrale[i].loc;
//
//    for (j = 1; j <= M; ++j)
//        cin >> blocuri[j].costul >> blocuri[j].loc;
//
//    for (i = 1; i <= M; ++i)
//        D[i] = INF;
//
//    for (i = 1; i <= M; ++i)
//        for (j = 1; j <= N; ++j)
//            D[i] = min(D[i], dist(centrale[j], blocuri[i]));
//
//    Ans = 0.0;
//    for (i = 1; i <= M; ++i) {
//        minim = INF;
//        poz = 0;
//        for (j = 1; j <= M; ++j) {
//            if (Ok[j]) continue;
//            if (minim > D[j]) {
//                poz = j;
//                minim = D[j];
//            }
//        }
//
//        Ok[poz] = 1;
//        Ans += minim;
//
//        for (j = 1; j <= M; ++j) {
//            if (Ok[j]) continue;
//            if (D[j] > dist(blocuri[poz], blocuri[j]))
//                D[j] = dist(blocuri[poz], blocuri[j]);
//        }
//    }
//
//    printf("%.6lf", Ans);
//
//    return 0;
//}