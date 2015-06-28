#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using  namespace std;

class Solution {
	const int subLen = 10;
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			vector<string> result;
			//the bool means wether this string is added to result
			unordered_map<string,bool> sequenceSeenTimes;

			int endIdx = s.size() - subLen + 1;
			for(int i = 0 ; i < endIdx ; ++i) {
				string subStr = s.substr(i,subLen);
				auto iter = sequenceSeenTimes.find(subStr);
				if(iter == sequenceSeenTimes.end())
					sequenceSeenTimes.insert(pair<string,bool>(subStr,false));
				else {
					//发现重复
					if(iter->second == false) {
						//如果还未添加
						result.push_back(subStr);
						iter->second = true;
					}
				}
			}
			return result;
		}
};

int main(){
	string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution s;
	vector<string> vs = s.findRepeatedDnaSequences(str); 
	for(string str : vs)
		cout<<str<<endl;
}
