#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	public:
		int resovle(vector<int>& dp,int num,int n){
			if(dp[num])
				return dp[num];

			for(int i=1;i<=num;++i){//we use i as root seprately
				dp[num] += resovle(dp ,i-1 ,n) * resovle(dp ,num-i, n); 
			}

			return dp[num];
		}

		int numTrees(int n) {
			vector<int> dp(n+1,0);//memo
			dp[0] = 1;	dp[1] = 1;

			resovle(dp,n,n);
			return dp[n];
		}
};
int main(){
	Solution s;
	cout<<s.numTrees(3)<<endl;
}
