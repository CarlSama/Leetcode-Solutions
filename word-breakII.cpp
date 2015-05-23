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
	private:
		int len;
		int maxLen;
	public:
		void getMaxLen(unordered_set<string> &wordDict){
			maxLen = 0;
			for(auto str : wordDict)
				maxLen = maxLen > str.size() ? maxLen : str.size();
		}

		vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
			len = s.size();
			getMaxLen(wordDict);

			unordered_map<int,vector<string> > hashmap;
			vector<string> emptyVS;	emptyVS.push_back(string(""));
			hashmap.insert(pair<int,vector<string> >(-1,emptyVS));

			for(int i=0;i<len;++i){
				for(int j=i;i-j+1<=maxLen&&j>=0;--j){
					string subStr = s.substr(j,i-j+1);
					if(wordDict.find(subStr)!=wordDict.end()){
						auto hashIter =  hashmap.find(j-1);
						if(hashIter != hashmap.end()){
							vector<string> frontVS = hashIter->second;
							auto destIter = hashmap.find(i);
							if(destIter == hashmap.end()){
								vector<string> newVS;
								for(int i=0;i<frontVS.size();++i){
									string str;
									if(frontVS[i].size() > 0){
										str = frontVS[i];	str += ' ';
									}
									str += subStr;

									newVS.push_back(str);
								}
								hashmap.insert(pair<int,vector<string> >(i, newVS));
							}else{//已有记录
								string str;
								for(int i=0;i<frontVS.size();++i){
									if(frontVS[i].size() > 0){
										str = frontVS[i];	str += ' ';
									}
									str += subStr;
									(destIter->second).push_back(str);
								}
							}
						}
					}
				}
			}
			
			auto resIter = hashmap.find(len-1);
			if(resIter==hashmap.end())
				return vector<string>();
			else
				return resIter->second;
		}
};
int main(){
	string str("catsanddog"); 
	unordered_set<string> dict;
	/*dict.insert("cat");
	dict.insert("cats"); 
	dict.insert("and");
	dict.insert("sand"); 
	dict.insert("dog");*/
	Solution s;
	vector<string> res = s.wordBreak(str,dict);
	Freeman::print(res);
}
