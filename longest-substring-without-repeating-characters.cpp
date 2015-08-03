#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
 * 询问字符的范围
 */

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			vector<int> isSeen(256, -1);

			int maxLen = 0,begin =0;
			for(int i=0 ; i < s.size() ; ++i) {
				if(isSeen[s[i]] >= begin) {
					// [ begin, isSeen[si]] , i]
					maxLen = max(maxLen, max(i-isSeen[s[i]], isSeen[s[i]] - begin + 1));
					begin = isSeen[s[i]] + 1;
				}
				isSeen[s[i]] = i;
			}
			maxLen = max(maxLen, (int)s.size() - begin);

			return maxLen;
		}
};

int main() {
	Solution s;
	cout<<s.lengthOfLongestSubstring("cdd")<<endl;
	cout<<s.lengthOfLongestSubstring("abc")<<endl;
	cout<<s.lengthOfLongestSubstring("bbb")<<endl;
	cout<<s.lengthOfLongestSubstring("bbbbbb")<<endl;
	cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
}
