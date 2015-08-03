#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<climits>
#include"print.h"
using namespace std;

/*
 * (1) 是遍历每一位a-z　还是　直接在字典中寻找只想差１个char的？
 * (2) 深度搜索会超时
 * (3) 能否修改传入的dict ?
 */
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

				//没有存储内容　或　存储的长度与路径长度相同
				if(res.size() == 0 || res[0].size() == path.size())
					res.push_back(path);	

				//路径长度更短
				if( res[0].size() > path.size())
					res.clear();

				//路径长度更长，则不过考虑

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
