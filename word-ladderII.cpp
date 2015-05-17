#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<climits>
#include"print.h"
using namespace std;
class Solution {
	private:
		vector<vector<string> >res;
		vector<string> path;
		unordered_set<string> myDict;
		string endStr;
		int currLeastLen;
	public:
		void btrack(string str){
			if(str == endStr){
				path.push_back(endStr);
				if(res.size() > 0 && res[0].size() > path.size())
					res.clear();
				if(res.size() == 0 || res[0].size() >= path.size())
					res.push_back(path);	
				path.pop_back();
				currLeastLen = res[0].size();
				return ;
			}
			if(myDict.size() == 0 || currLeastLen <= path.size())	return ;

			for(int i=0;i<str.size();++i){
				for(char ch='a';ch<='z';++ch){
					string tmp = str;
					tmp[i] = ch;
					if(ch != str[i] && myDict.find(tmp) != myDict.end()){
						path.push_back(str);
						myDict.erase(tmp);
						btrack(tmp);
						myDict.insert(tmp);
						path.pop_back();
					}
				}
			}
		}
		vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
			currLeastLen = INT_MAX;
			myDict = dict;
			myDict.insert(end);
			endStr = end;
			btrack(start);
			return res;
		}
};
int main(){
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	Solution s;
	vector<vector<string> > res = s.findLadders(string("hit"),string("cog"),dict);
	Freeman::print(res);
}
