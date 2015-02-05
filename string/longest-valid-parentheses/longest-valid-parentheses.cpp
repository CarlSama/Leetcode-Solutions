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
int longestValidParentheses_mix(string s){
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

	int maxLen = 0;
	int subLen = 0;
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

/*
 * Stack
 * In stack+visited, we use vector to indicate the match.But can we calculating while move, that is finishing in only one pass ?
 * Here is a situation we need to be careful, "()()()",each time we match '(' and ')',the length we get is more than just 2.
 * How can we manage this situation ?
 * We need a indication, which implies the front position of continus '(' and ')'.
 * If the stack is not empty, that means we have more '(' than ')' , then the front is continus. we can use i-st.top() to calculate.
 * If the stack is empty, that emas we have more ')' now, let's move indication.
 */
int longestValidParentheses(string s){
	stack<int> st;
	int last = -1;//the lasts occurance of unmatched ')'
	int maxLen = 0;

	for(int i=0;i<s.size();i++){
		if(s[i] == '(')
			st.push(i);
		else{
			if(st.empty()){
				last = i;
			}else{
				st.pop();

				if(st.empty()){
					maxLen = max(maxLen, i-last);
				}else{
					maxLen = max(maxLen, i-st.top());
				}
			}
		}
	}

	return maxLen;
}

int main(){
	string s = "(()()";
	cout<<longestValidParentheses(s)<<endl;
	return 0;
}
