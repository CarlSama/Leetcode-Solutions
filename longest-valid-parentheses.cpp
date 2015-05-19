#include<iostream>
#include<vector>
using namespace std;
class Solution {
	private:
		int len;
	public:
		int longestValidParentheses(string s) {
			len = s.size();
			if(len ==0)	return 0;

			vector<int> dp(len,0);
			int maxLen = 0;
			for(int i=1;i<len;++i){
				if(s[i] == ')'){
					if(i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]]=='(')
						dp[i] = dp[i-1] + 2;
					if(i-dp[i] >= 0)
						dp[i] += dp[i-dp[i]];
				}
				maxLen = max(maxLen, dp[i]); 
			}
			return maxLen;
		}
};
int main(){
	Solution s;
	cout<<s.longestValidParentheses(")()()")<<endl;;
	cout<<s.longestValidParentheses("()(")<<endl;;
	cout<<s.longestValidParentheses("(())")<<endl;;

}
