#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
	public:
		void buildInfo(vector<string>& words,unordered_map<string,int>& info) {
			for(string str : words) {
				 ++info[str];
			}
		}

		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> result;
			if(words.size() == 0 || s.size() == 0)
				return result;

			int eachLen = words[0].size();
			int wordNum = words.size();

			unordered_map<string,int> info;
			buildInfo(words,info);


			//why ?
			int end = s.size() - eachLen * wordNum;
			for(int idx=0 ; idx <=  end; ++idx) {
				unordered_map<string,int> remainingWords = info;

				int subIdx = idx;
				int subEnd = idx + eachLen * wordNum;
				for(; subIdx < subEnd ; subIdx += eachLen) {
					string str = s.substr(subIdx, eachLen);

					if(remainingWords[str] > 0) {
						--remainingWords[str];
					}else{
						break;
					}
				}

				if(subIdx >= subEnd)
					result.push_back(idx);
			}

			return result;
		}
};

int main() {
	vector<string> v;
	v.push_back("a");
	v.push_back("a");

	Solution s;
	vector<int> vi = s.findSubstring("a",v);
	for(int i:vi) {
		cout<<i<<endl;
	}
}
