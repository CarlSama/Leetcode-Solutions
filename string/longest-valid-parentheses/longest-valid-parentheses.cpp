#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

/*
 * DP
 * When we come into '(', just ignore and move on.
 * Whe we comes into ')', try to match previous ')' and far previous '('.
 *	WARNING : always remember to pick up the info before '(', that is check if previous matich is linked with this one.
 * Time compliexity : O(n * n)
 */
int longestValidParentheses_dp(string s){
	int size = s.size();
	
	//dp[i] repmaxLenents the max length which contains the s[i]
	vector<int> dp(size,0);
	
	int maxLen = 0;
	//always consider the '(' follow by valid junck
	for(int i=1;i<size;i++){
		if(s[i] == ')'){
			if(s[i-1] == '('){
				if(i >= 2)
					dp[i] = 2 + dp[i-2];
				else
					dp[i] = 2;
			}
			if(i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '('){
				if(i-1-dp[i-1]-1 >= 0)
					dp[i] = max( dp[i] , 2+dp[i-1] + dp[i-1-dp[i-1]-1]);
				else
					dp[i] = max( dp[i] , 2+dp[i-1] );
			}
			maxLen = max(maxLen,dp[i]);
		}
	}
	return maxLen;
}
/*
 * Stack + visited
 * We use an array to indicate wether one position has been match. After one pass, accumulate continuous 1 for ans.
 * Time compliexity : O(n) but two pass.
 */
int longestValidParentheses(string s){
	stack<int> st;
	vector<bool> visited(s.size(),false);

	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			st.push(i);
		}else{
			if(!st.empty()){
				visited[i] = visited[st.top()] = true;
				st.pop();
			}
		}
	}

	int maxLen = 0,int subLen = 0;
	for(int i=0;i<visited.size();i++){
		if(visited[i])
			subLen++;
		else{
			subLen = 0;
		}
		maxLen = max(subLen,maxLen);//compare each time to avoid forgeting the last continous 1 till end of visited :(
	}

	return maxLen;
}

int main(){
	string s = "(()()";
	cout<<longestValidParentheses(s)<<endl;
	return 0;
}
