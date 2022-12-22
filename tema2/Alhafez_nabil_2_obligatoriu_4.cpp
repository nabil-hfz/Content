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
// http://infoarena.ro/problema/catun
#include <fstream>
#include <queue>

using namespace std;


const int MAXSIZE = 36001;
const int oo = 0x3f3f3f3f;

ifstream in("catun.in");
ofstream out("catun.out");

int nodes, cities, edges;
int father[MAXSIZE];
vector<int> dist(MAXSIZE, oo);
vector<pair<int, int> > graph[MAXSIZE];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > nodesQueue;
// LUI DIJ O(M *log N)
void dijkstra() {
    vector<pair<int, int> >::iterator it, end;
    pair<int, int> node;

    while (!nodesQueue.empty()) {
        node = nodesQueue.top();
        cout << node.first << " " << node.second << endl;
        nodesQueue.pop();

        //out << "In node: " << node.loc << "\n";

        //out << "Neighbours:\n";
        end = graph[node.loc].end();
        for (it = graph[node.loc].begin(); it != end; ++it)
            if ((dist[it->loc] > dist[node.loc] + it->costul) ||
                (dist[it->loc] == dist[node.loc] + it->costul && father[node.loc] < father[it->loc])) {
                //out << " " << it->loc << "\n";
                //out << " Current costul: " << dist[it->loc] << "\n";
                dist[it->loc] = dist[node.loc] + it->costul;
                //out << " New costul: " << dist[it->loc] << "\n";
                father[it->loc] = father[node.loc];
                nodesQueue.push(make_pair(dist[it->loc], it->loc));
            }
    }
}

int main() {
    cin >> nodes >> edges >> cities;

    int indexx;
    for (int i = 1; i <= cities; i++) {
        cin >> indexx;
        dist[indexx] = 0;
        father[indexx] = indexx;

        nodesQueue.push(make_pair(0, indexx));
    }

    int from, to, length;
    for (int i = 1; i <= edges; i++) {
        cin >> from >> to >> length;
        graph[from].emplace_back(length, to);
        graph[to].emplace_back(length, from);
    }

    dijkstra();

    for (int i = 1; i <= nodes; i++)
        if (i == father[i])
            cout << "0 ";
        else
            cout << father[i] << " ";
    cout << "\n";

    return 0;
}
