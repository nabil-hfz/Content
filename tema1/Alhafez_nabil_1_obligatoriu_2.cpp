//#include "/usr/local/include/bits/stdc++.h"
#include <iostream>
#include <vector>
#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);
using namespace std;

const int N = 1e6;


bool eCurentDrumOk = true;
int undeAmAjunsPanaLaUrmaLaDrumul = 1;

vector <vector<int>> adj(N);
vector<bool> visited(N, false);
vector<int> per(N);
int n, m;


class Solution {

public:
    bool solve() {
        dfs(1);
        bool ok = true;
        for (int i = 1; i <= n && eCurentDrumOk; ++i) {
            if (!visited[i]) {
                ok = false;
                break;
            }
        }
        return (ok && eCurentDrumOk);
    }

    void dfs(int node) {
        if (!eCurentDrumOk)
            return;
        visited[node] = true;
        int i = 0;
        int laSfarsit = 0, ePosibil = 0;
        while (i < (int)adj[node].size()) {
            if (!visited[adj[node][i]]) { // verificam de la vecinul
                ++laSfarsit;
                if (adj[node][i] == per[undeAmAjunsPanaLaUrmaLaDrumul]) { // si daca vecinul nodului curent e la drum corect
                                                            // tot continuam la drumul ala si verificam
                    dfs(per[undeAmAjunsPanaLaUrmaLaDrumul++]);
                    i = -1;
                    ++ePosibil;
                }
            }
            ++i;
        }
        if (laSfarsit && !ePosibil) {
            eCurentDrumOk = false;
        }
    }

};

int main0() {
    HURRY_UP;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> per[i];
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    Solution stiva;
    bool result = stiva.solve();
    cout << result << endl;


    return 0;
}
