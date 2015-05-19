#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include"print.h"
using namespace std;

class Solution {
	private:
		int len1,len2;
	public:
		int minDistance(string word1, string word2) {
			len1 = word1.size();	len2 = word2.size();
			if(len1==0)	return len2;
			if(len2==0)	return len1;

			vector<vector<int> > dp(len1+1,vector<int>(len2+1,INT_MAX));
			dp[0][0] = 0;
			for(int i=1;i<=len1;++i)
				dp[i][0] = i;
			for(int i=1;i<=len2;++i)
				dp[0][i] = i;
			for(int i=1;i<=len1;++i){
				for(int j=1;j<=len2;++j){
					if(word1[i-1] == word2[j-1])
						dp[i][j] = dp[i-1][j-1];
					dp[i][j] = min(dp[i][j], min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1)));
				}
			}
			return dp[len1][len2];
		}
};
int main(){
	Solution s;
	cout<<s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis","ultramicroscopically")<<endl;
}
