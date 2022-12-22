#include <iostream>
#include <vector>
#include <queue>

//#define HURRY_UP ios_base::sync_with_stdio(0) , cin .tie(0) , cout.tie(0);

using namespace std;
//  COLORING PROBLEM
class Solution {


public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        if (dislikes.empty())return true;

        vector<vector<int>> items(n);

        for (auto dislike: dislikes)
            items[dislike[0] - 1].push_back(dislike[1] - 1),
                    items[dislike[1] - 1].push_back(dislike[0] - 1);

        vector<int> col(n, -1);
        queue<pair<int, int> > q;


        for (int i = 0; i < n; i++) {

             if (col[i] == -1) {

                 q.push({ i, 0 });
                col[i] = 0;

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                     int v = p.first;
                     int c = p.second;

                     for (int j : items[v]) {


                        if (col[j] == c)
                            return 0;

                         if (col[j] == -1) {
                             col[j] = (c) ? 0 : 1;
                            q.push({ j, col[j] });
                        }
                    }
                }
            }
        }

        return 1;
    }
    vector<vector<int>> possibleBipartitionPartion(int n, vector<vector<int>> &dislikes) {
        if (dislikes.empty())return dislikes;

        vector<vector<int>> items(n);

        for (auto dislike: dislikes)
            items[dislike[0] - 1].push_back(dislike[1] - 1),
                    items[dislike[1] - 1].push_back(dislike[0] - 1);

        vector<int> col(n, -1);
        queue<pair<int, int> > q;

        vector<vector<int>> grupe(n);

        for (int i = 0; i < n; i++) {

             if (col[i] == -1) {

                 q.push({ i, 0 });
                col[i] = 0;
                grupe[col[i]].push_back(i);
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                     int v = p.first;
                     int c = p.second;

                     for (int j : items[v]) {


                        if (col[j] == c)
                            return dislikes;

                         if (col[j] == -1) {

                            col[j] = (c) ? 0 : 1;
                            grupe[col[j]].push_back(j);
                            q.push({ j, col[j] });
                        }
                    }
                }
            }
        }

        return grupe;
    }
};

int main() {
    int n = 4;

    vector<vector<int>> list = {{1, 2},
                                {1, 3},
                                {2, 4}};
    Solution s;
    bool result = s.possibleBipartition(n, list);
    cout << "result: " << result << endl;
    if(result){
        auto grupe = s.possibleBipartitionPartion(n, list);
        for(auto primulGrup : grupe[0])cout << primulGrup + 1 << " " ;
        cout << endl;
        for(auto alDoilea : grupe[1])cout << alDoilea + 1<< " " ;
    }

    return 0;


}