#include<iostream>
#include<vector>
#include<climits>
#include"print.h"
using namespace std;
class Solution {
		int len;
	public:
		bool isPalindromic(vector<int>& span,int left,int right){
			return span[left + right] >= right - left + 1;
		}
		int getSpan(string &s,int left,int right){
			while(left >=0 && right < len && s[left] == s[right]){
				--left;	++right;
			}
			return right-left-1;
		}
		void initSpan(string &s,vector<int> &span){
			for(int i=0;i<len;++i){
				int left = i,right = i;//odd
				span[left + right] = getSpan(s,left,right);
				if((right = i + 1) < len)
					span[left + right] = getSpan(s,left,right);
			}
		}
		int minCut(string s) {
			len = s.size();
			if(len < 2)	return 0;

			vector<int> span(len<<1,0);
			initSpan(s, span);

			vector<int> dp(len+1,-1);
			for(int i=0;i<len;++i){
				dp[i+1] = i;
				for(int j = 0;j<=i;++j){
					if(isPalindromic(span,j,i))
						dp[i+1] = min(dp[i+1], dp[j] + 1);
				}
			}
			return dp[len];
		}
};
int main(){
	Solution s;
	cout<<s.minCut("abc")<<endl;
	cout<<s.minCut("aab")<<endl;
	cout<<s.minCut("abb")<<endl;
	cout<<s.minCut("aaa")<<endl;
}
