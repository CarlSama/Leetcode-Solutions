#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
class Solution {
	private:
		int slen,tlen;
	public:
		int numDistinct(string s, string t) {
			slen = s.size();	tlen = t.size();
			if(slen < tlen)	return 0;
			if(tlen==0)	return slen;
			vector<vector<int> > dp(slen+1,vector<int>(tlen+1,0));
			for(int i=1;i<=slen;++i){
				dp[i][1] = dp[i-1][1];
				if(s[i-1]==t[0])
					++dp[i][1];
			}

			for(int j=2;j<=tlen;++j){
				for(int i=j;i<=slen;++i){
					dp[i][j] += dp[i-1][j];
					if(s[i-1] == t[j-1])
						dp[i][j] += dp[i-1][j-1];
				}
			}
			Freeman::print(dp);
			return dp[slen][tlen];
		}
};
int main(){
	Solution s;
	cout<<s.numDistinct("aacaacca","ca")<<endl;
}
