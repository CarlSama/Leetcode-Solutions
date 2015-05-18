#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include"print.h"
using namespace std;
class Solution {
	private:
		string subStr,str;
		vector<string> res;
		unordered_set<string> myDict;
		int longestLen;
	public:
		void btrack(string s,int currIdx,string& subStr){
			if(currIdx == s.size()){
				if(subStr.size()==0){
					res.push_back(str);
				}else if(myDict.find(subStr)!=myDict.end()){
					string origStr(str);
					str+= ' ';
					str += subStr;
					res.push_back(str);

					str = origStr;
				}
				return ;
			}
			//not merge current -> subStr must be valid
			if(myDict.find(subStr)!=myDict.end()){
				string origStr(str);
				string origSubStr(subStr);

				str+= ' ';//always have a leading blank 
				str += subStr;
				subStr = s[currIdx];
				btrack(s,currIdx+1,subStr);
				subStr = origSubStr;
				str = origStr;
			}


			subStr.push_back(s[currIdx]);
			if(subStr.size() <= longestLen)//too long to discard 
				btrack(s,currIdx+1,subStr);
			subStr.pop_back();
		}
		void getLongestLen(){
			longestLen = 0;
			for(auto iter=myDct.begin();iter!=myDict.end();++iter){
				longestLen = max(longestLen, (int)(*iter).size());
			}
		}

		vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
			myDict = wordDict;
			getLongestLen();
			btrack(s,0,subStr);
			return res;
		}
};
int main(){
	string str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"); 
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("aa"); 
	dict.insert("aaa");
	dict.insert("aaaa"); 
	dict.insert("aaaaa");
	dict.insert("aaaaaa");
	dict.insert("aaaaaaa");
	dict.insert("aaaaaaaa");
	dict.insert("aaaaaaaaa");
	dict.insert("aaaaaaaaaa");
	Solution s;
	vector<string> res = s.wordBreak(str,dict);
	Freeman::print(res);
}
