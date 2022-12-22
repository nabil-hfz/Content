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


#define MAXN 2011
#define point pair<double, double>
#define costul first
#define loc second
#define INF 2000000000;

ifstream in("disjoint.in");
ofstream out("disjoint.out");

int N, M;
int *t;
int *h;

int root(int nod) {
    if (t[nod] == 0)
        return nod;
    return t[nod] = root(t[nod]);

}

void unite(int x, int y) {
    int t_x = root(x);
    int t_y = root(y);

    if (h[t_x] > h[t_y]) {
        t[t_y] = t_x;
    } else if (h[t_x] < h[t_y]) {

        t[t_x] = t_y;
    } else {
        t[t_y] = t_x;
        h[t_x]++;
    }
}

int main() {
    in >> N >> M;

    t = new int[N + 10];
    h = new int[N + 10];

    for (int i = 0; i <= N; i++)
        t[i] = 0, h[i] = 1;


    for (int i = 1; i <= M; i++) {
        int cod, x, y;
        in >> cod >> x >> y;
        if (cod == 1) {
            unite(x, y);
        } else if (cod == 2) {
            if (root(x) == root(y))
                out << "DA\n";
            else
                out << "NU\n";
        }
    }

    return 0;
}