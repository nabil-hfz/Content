//#include <bits/stdc++.h>
//using namespace std;
//#define f cin
//#define g cout
//// #define int long long
//const int Max = 2e5 + 1;
//void nos()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//}
//int n,k;
//vector < string > strs;
//int id = 0;
//map < string , int > nodes;
//vector < int > graph[Max];
//string who[Max];
//void read()
//{
//    f >> n >> k;
//    strs.resize(n);
//    for(auto &it : strs)
//        f>>it;
//}
//
//vector < int > sol;
//void dfs(int nod)
//{
//    while(!graph[nod].empty())
//    {
//        int vec = graph[nod].back();
//        graph[nod].pop_back();
//        dfs(vec);
//    }
//    sol.push_back(nod);
//}
//map < int , int > indeg,outdeg;
//void solve()
//{
//    if(k == 1)
//    {
//        for(auto it : strs)
//            cout<<it;
//        return;
//    }
//    auto get_id = [&](const string &s)
//    {
//        if(nodes.find(s) == nodes.end()){
//            nodes[s] = ++id;
//            who[id] = s;
//        }
//        return nodes[s];
//    };
//
//    for(auto it : strs)
//    {
//        int fst_val = get_id(it.substr(0,k-1));
//        int snd_val = get_id(it.substr(1,k-1));
//        graph[fst_val].push_back(snd_val);
//        outdeg[fst_val]++;
//        indeg[snd_val]++;
//    }
//    int start = 1;
//    int startcnt = 0;
//    int endcnt = 0;
//    for(int i=1;i<=id;i++)
//    {
//        if(outdeg[i] - indeg[i] == 1){
//            startcnt ++;
//            start = i;
//        }
//        if(outdeg[i] - indeg[i] == -1)
//            endcnt ++;
//    }
//    if(startcnt > 1 or endcnt > 1)
//    {
//        cout<<-1;
//        return;
//    }
//    dfs(start);
//    reverse(sol.begin(),sol.end());
//    if(sol.size() != n + 1)
//    {
//        cout<<-1;
//        return;
//    }
//
//    cout<<who[sol[0]];
//    for(int i=1;i<sol.size();i++)
//        cout<<who[sol[i]].back();
//}
//void restart()
//{
//
//}
//int32_t main()
//{
//    nos();
//    {
//        read();
//        solve();
//        restart();
//    }
//    return 0;
//}