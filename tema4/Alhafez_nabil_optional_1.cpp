////#include <bits/stdc++.h>
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//using namespace std;
//
//
//
//const int N = 250000;
//
//vector<pair<int, pair<int, int>>> cost;
//
//int n, m, x, y, cost_muchie, cost_cerut, parante[N], rang[N];
//
//int find(int x)
//{
//    while (x != parante[x])
//        x = parante[x];
//    return x;
//}
//
//void unite(int x, int y)
//{
//    x = find(x);
//    y = find(y);
//
//    if (rang[x] >= rang[y])
//    {
//        parante[y] = x;
//        rang[x] += rang[y];
//    }
//    else
//    {
//        parante[x] = y;
//        rang[y] += rang[x];
//    }
//}
//
//void kruskal()
//{
//    sort(cost.begin(), cost.end(),greater<pair<int,pair<int,int>>>());
//
//    for (auto it : cost)
//    {
//        if (find(1) == find(n))
//            break;
//        else if (find(it.second.first) != find(it.second.second))
//        {
//            // apm.push_back(it.second);
//            unite(it.second.first, it.second.second);
//            cost_cerut = it.first;
//        }
//    }
//}
//
//int main()
//{
//    ifstream cin("transport2.in");
//    ofstream cout("transport2.out");
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++)
//    {
//        cin >> x >> y >> cost_muchie;
//        cost.push_back(make_pair(cost_muchie, make_pair(x, y)));
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        parante[i] = i;
//        rang[i] = 1;
//    }
//
//    kruskal();
//
//    cout << cost_cerut;
//
//    return 0;
//}