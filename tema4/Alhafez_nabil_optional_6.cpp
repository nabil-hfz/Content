//#include <bits/stdc++.h>
//#define inf INT_MAX
//#define dim 1505
//using namespace std;
//ifstream f("dbz.in");
//ofstream o("dbz.out");
//int n, m, nod, distanta;
//map<int, vector<pair<int, int>>> la;
//vector<int> d(dim), tata(dim);
//void dijkstra(int start) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coada;
//    for (int i = 1; i <= n; i++) {
//        d[i] = inf;
//        tata[i] = 0;
//    }
//    d[start] = 0;
//    for (auto vecin: la[start]) {
//        //bagam vecinii intai in coada
//        coada.push(make_pair(vecin.second, vecin.first));
//        tata[vecin.first] = vecin.first;
//        d[vecin.first] = vecin.second;
//    }
//    while (!coada.empty()) {
//        auto front = coada.top();
//        coada.pop();
//
//        nod = front.second;
//        distanta = front.first;
//
//        if (distanta > d[nod]) continue;
//
//        for (auto vecin: la[nod])
//            if (d[vecin.first] > d[nod] + vecin.second) {
//                d[vecin.first] = d[nod] + vecin.second;
//                coada.push(make_pair(d[vecin.first], vecin.first));
//                tata[vecin.first] = tata[nod];
//            }
//    }
//    int minim = inf;
//
//    for (int i = 1; i <= n; i++)
//        for (auto vecin: la[i])
//            if (tata[i] != tata[vecin.first] && (tata[i] != i || vecin.first != start) && (tata[vecin.first] != vecin.first || i != start))
//                minim = min(minim, d[i] + d[vecin.first] + vecin.second);
//
//    if (minim == inf)
//        o << -1 << " ";
//    else
//        o << minim << " ";
//}
//
//int main() {
//    f >> n >> m;
//    for (int i = 0; i < m; i++) {
//        int x, y, c;
//        f >> x >> y >> c;
//        la[x].push_back(make_pair(y, c));
//        la[y].push_back(make_pair(x, c));
//    }
//    for (int i = 1; i <= n; i++)
//        dijkstra(i);
//
//    return 0;
//}
///*
//
//  facem dijkstra din fiecare nod doar ca plecam din primul rand de
//  vecini ca sa lasam libere muchiile care
//  pleaca din start ca sa inchidem ciclu cu ele la final
//  */