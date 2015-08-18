//LeetCode, Edit Distance
//time complexity O(mn)，space complexity O(mn)
//dynamic programing
//edited by fan xu

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int i = 0; i <= m; i++) dp[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=m; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    int temp = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = 1 + min(temp, dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution solution;
    string w1, w2;
    
    cout <<"input word1" <<endl;
    cin >>w1;
    cout <<"input word2" <<endl;
    cin >>w2;
     
    cout <<"edit distance is: " <<solution.minDistance(w1, w2) <<endl;

    return 0;
}


