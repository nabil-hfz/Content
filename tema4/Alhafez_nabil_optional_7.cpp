//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <pair <int, int> > v[100005];
long long sol[100005], d[100005], h[100005];

void dfs(int nod, int tata) {

    for (auto it : v[nod]) {
        if (it.first == tata)
            continue;

        h[it.first] = h[nod] + it.second;
        dfs (it.first, nod);
        d[nod] = max (d[nod], d[it.first] + it.second);
    }

    long long x = 0;
    for (auto it : v[nod]) {
        if (it.first == tata)
            continue;

        x = max (x, min (d[it.first] + it.second, h[nod]));
        sol[nod] = sol[nod] + sol[it.first] + it.second + min (d[it.first] + it.second, h[nod]);
    }
    sol[nod] -= x;
    // cout << nod << " " << h[nod] << " " << d[nod] << " " << sol[nod] << "\n";
}

int main () {
    ifstream cin("riremito.in");
    ofstream cout("riremito.out");

    cin >> n;

    int i, x, y, z;
    for (i = 1; i < n; i ++) {
        cin >> x >> y >> z;
        v[x].push_back (make_pair (y, z));
        v[y].push_back (make_pair (x, z));
    }

    int t;
    cin >> t;
    while (t --) {
        int r;
        cin >> r;
        memset (d, 0, sizeof (d));
        memset (sol, 0, sizeof (sol));
        memset (h, 0, sizeof (h));
        dfs (r, 0);
        cout << sol[r] << "\n";
    }
}