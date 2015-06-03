#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		bool isScramble(string s1, string s2) {
			if(s1.size() != s2.size())	return false;
			len = s1.size();
			if(len==0)	return true;
			if(len==1)	return s1[0] == s2[0];

			//dp[length][s1.start][s2.start]
			vector<vector<vector<bool> > > dp(len,vector<vector<bool> >(len,vector<bool>(len, false)));

			//length == 1
			for(int i=0;i<len;++i){
				for(int j=0;j<len;++j){
					dp[0][i][j] = (s1[i] == s2[j]);
				}
			}

			for(int k=2;k<=len;++k){//the length
				for(int i=0;i<=len-k;++i){
					for(int j=0;j<=len-k;++j){
						for(int m=1;m<k;++m){
							if(dp[m-1][i][j] && dp[k-m-1][i+m][j+m] || dp[m-1][i][j+k-m] && dp[k-m-1][i+m][j]){
								dp[k-1][i][j] = true;
								break;
							}
						}
					}
				}
			}
			return dp[len-1][0][0];
		}
};
int main(){
	Solution s;
	cout<<s.isScramble("aa","aa")<<endl;
}
