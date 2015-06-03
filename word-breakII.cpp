#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
#include"print.h"
#include<climits>
using namespace std;
class Solution {
	int len;
	vector<string> vs;
	vector<string> path;
	public:
		void genPath(string& s,int currIdx,vector<vector<int> > &dp){
			if(currIdx == 0){
				//从tmp中生成
				string str;
				for(int i=path.size()-1;i>=0;--i){
					str += path[i];
					str += ' ';
				}
				str.pop_back();
				
				vs.push_back(str);
				return ;
			}

			for(int i = 0 ; i < dp[currIdx].size() ; ++i){
				string part =  s.substr(dp[currIdx][i]-1 , currIdx - dp[currIdx][i] + 1);
				path.push_back(part);
				genPath(s, dp[currIdx][i]-1,dp);
				path.pop_back();
			}
		}

		vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
			len = s.size();
			if(len ==0 || wordDict.size() ==0 )	return vs;

			vector<vector<int> > dp(len+1,vector<int>());
			dp[0].push_back(-1);

			for(int i=0;i<len;++i){
				for(int j=0;j<=i;++j){
					if(wordDict.find(s.substr(j,i-j+1)) != wordDict.end() && dp[j].size() != 0){
						dp[i+1].push_back(j+1);
					}
				}
			}

			genPath(s,len,dp);
			return vs;
		}
};
int main(){
	string str("catsanddog"); 
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats"); 
	dict.insert("and");
	dict.insert("sand"); 
	dict.insert("dog"); 
	Solution s;
	vector<string> res = s.wordBreak(str,dict);
	Freeman::print(res);
}
