#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using  namespace std;

/*
 * Method 1 ：　使用unordered_map来标记所有长度为10的子串的重复性
 *				MLE 
 * Method 2 :   使用unordered_set　－》　TLE
 *
 * 考虑是因为string太长的原因，所以使用四进制存储
 */
class Solution {
	const int subLen = 10;
	public:
		long charToLong(char c){
			switch(c) {
				case 'A':
					return 0;
				case 'C':
					return 1;
				case 'G':
					return 2;
				case 'T':
					return 3;
			}
		}
		long getValue(string str) {
			long value = 0;
			for(int i=str.size()-1 ; i>=0 ; --i) {
				value *= 4;
				value += charToLong(str[i]);
			}
			return value;
		}

		vector<string> findRepeatedDnaSequences(string s) {
			vector<string> result;
			unordered_set<long> sequenceOnce;
			unordered_set<long> sequenceMoreThanOnce;

			int endIdx = s.size() - subLen + 1;
			for(int i = 0 ; i < endIdx ; ++i) {
				string subStr = s.substr(i,subLen);
				long currValue = getValue(subStr);
				if(sequenceMoreThanOnce.find(currValue) == sequenceMoreThanOnce.end()) {
					auto iter = sequenceOnce.find(currValue);
					if(iter == sequenceOnce.end()) {
						sequenceOnce.insert(currValue);
					}else{
						result.push_back(subStr);
						sequenceOnce.erase(iter);
						sequenceMoreThanOnce.insert(currValue);
					}
				}
			}
			return result;
		}
};

int main() {
	string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution s;
	vector<string> vs = s.findRepeatedDnaSequences(str); 
	for(string str : vs)
		cout<<str<<endl;
}
