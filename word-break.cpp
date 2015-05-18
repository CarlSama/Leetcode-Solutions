#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
/*
 * 最优子结构：问题的一个最优解中包含了自问题的最优解； dp[i] 以来于dp[j] (j < i)
 * 子问题重叠：对于［i~j]的判断，dp[i]可能有多重组合方式
 * 无后效性：下一时刻的状态至于当前状态相关，与当前状态之前的状态无关，当前状态是对之前状态的总结
 * 使用dp[i]表示string[1~i]存在于字典中，如果j>i&&string[i,j]也存在于字典中时,dp[j]=true;
 *
 * dp[0] = true;
 * dp[i] = dp[j] && inDict(s.substr(j,i)) j<=i
 */
class Solution {
	public:
		bool wordBreak(string s, unordered_set<string>& wordDict) {
			vector<bool> dp(s.size()+1,false);//dp[i] -> [0,i-1]
			dp[0] = true;
			for(int i=0;i<s.size();++i){
				for(int j=i;j>=0;--j){//[j,i]
					if(dp[j+1-1]){//[0,j-1] == true;
						string subStr = s.substr(j,i-j+1);
						if(wordDict.find(subStr)!=wordDict.end()){
							dp[i+1] = true;
							break;
						}
					}
				}
			}
			return dp[s.size()];
	    }
};
int main(){
	string str = "leetcode";
	string str1 = "leecode";
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	Solution s;
	cout<<s.wordBreak(str,dict)<<endl;
	cout<<s.wordBreak(str1,dict)<<endl;
}
