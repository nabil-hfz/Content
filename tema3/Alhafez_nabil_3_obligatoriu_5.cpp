////// 1-  In order to find shortest path in any problem we essentially use queue, Put differently it helps to visualise every steps easily.
////// 2- Since Constraints is <=12, we will explore every possible path (i.e total 2^n path) and we will use bitmask to make sure that we are not travelling the same path again.
//////3- we will start from every node and take the best possible answer.
//class Solution {
//public:
//    int shortestPathLength(vector<vector<int>>& graph) {
//        queue<vector<int>>q;
//        set<pair<int,int>>vis;
//        int n=graph.size();
//        vector<int>vec(3,0);
//        for(int i=0;i<n;i++)
//        {
//            vec[0]=i,vec[1]=(1<<i);
//            q.push(vec);
//        }
//        while(!q.empty())
//        {
//            auto x=q.front();
//            q.pop();
//            if(x[1]==(1<<n)-1) return x[2]; // As we travelled all the node return the distance you took the reach out the last node in that particular path
//            vis.insert({x[0],x[1]});
//            for(auto y:graph[x[0]])   {
//                int msk=x[1]|(1<<y);
//                if(vis.find({y,msk})==vis.end())  {
//                    q.push({y,msk,x[2]+1});
//                    vis.insert({y,msk});
//                }
//            }
//        }
//        return INT_MAX;
//    }
//};