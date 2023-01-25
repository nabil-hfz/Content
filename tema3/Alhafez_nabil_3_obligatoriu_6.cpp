class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[1001][1001] = {};
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[m][n];
    }
};



//=========================================================

//This problem is ans extension of LCS(longest common subsequence)
//first we will find what is the common longest subsequence present in both the strings.
//then from LCS table we will trace backward in order to get the string. ifat any index the
// string character matches then we we will take it once bcz it is the common charater in both
// the string. otehrwise we will take go to the maximium cell from wehere we have arrived either
// dp[i-1][j] or dp[i][j-1] and before going we will add the charcter in ans. Our string is ready but in reverse order.

class Solution {
public:
    vector<vector<int>> createLCS(string &s1,string &s2){
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 1 + dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp;
    }

    string getStringFromLcsTable(vector<vector<int>>&dp,string &s1,string &s2){
        string ans="";
        int i=s1.size();
        int j=s2.size();
        while(i>0 && j>0){

            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else{
                int maxi=max(dp[i][j-1] ,dp[i-1][j]);
                if(dp[i][j-1]==maxi){
                    ans+=s2[j-1];
                    j--;
                }
                else{
                    ans+=s1[i-1];
                    i--;
                }
            }
        }

        while(i>0)
        {
            ans+= s1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+= s2[j-1];
            j--;
        }
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp= createLCS(str1,str2);
        string ans= getStringFromLcsTable(dp,str1,str2);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};