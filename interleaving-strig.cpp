#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
	int len1,len2,len3;
	public:
		bool isInterleave(string s1, string s2, string s3) {
			len1=s1.size(); len2=s2.size(); len3=s3.size();
			if(len1+len2 != len3)	return false;
			if(len1 == 0)	return s2 == s3;
			if(len2 == 0)	return s1 == s3;

			vector<vector<bool> > dp(len1+1,vector<bool>(len2+1,false));

			dp[0][0] = 1;
			for(int i=1;i<=len1;++i)
				dp[i][0] = (s1[i-1]==s3[i-1]) && dp[i-1][0];
			for(int i=1;i<=len2;++i)
				dp[0][i] = (s2[i-1]==s3[i-1]) && dp[0][i-1];

			for(int i=1;i<=len1;++i){
				for(int j=1;j<=len2;++j){
					if((s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1]&&dp[i][j-1]))
						dp[i][j] = true;
				}
			}
			return dp[len1][len2];
		}
};
int main(){
	Solution s;
	cout<<s.isInterleave("aabcc","dbbca","aadbbcbcac")<<endl;
	cout<<s.isInterleave("aabcc","dbbca","aadbbbaccc")<<endl;
}
