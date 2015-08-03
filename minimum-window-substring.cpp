#include<iostream>
#include<string>
#include<climits>

using namespace std;

class Solution {
	public:
		string minWindow(string s, string t) {
			if(s.empty() || t.empty())
				return "";

			//出现的次数　＋　存在性
			int times[256] = {0};
			bool isSeen[256] = {false};
			for(int i=0;i<t.size();++i) {
				++times[t[i]];
				isSeen[t[i]] = true;
			}

			int begin=0,end=-1;
			int count = t.size();
			int minLen = INT_MAX; 
			int minBegin = -1;
			//这里需要考虑当最后一个元素满足count==0，可是无法被处理的情况【if上面被处理后，不会进入下面】
			//首先，考虑在s后面插入辅助字符，这样必须选择t中没有出现过的字符，不具有扩展性
			//其次，考虑将end后移一位。
			int slen = s.size();
			while(begin < slen && end < slen) {
				if(count) {
					++end;
					//count只受t中元素影响
					if(isSeen[s[end]] && times[s[end]] > 0)
						--count;
					--times[s[end]];
				}else{
					if(end - begin + 1 < minLen) {
						minBegin = begin;
						minLen = end - begin + 1;
					}

					++times[s[begin]];
					if(isSeen[s[begin]] && times[s[begin]] > 0)
						++count;
					++begin;
				}
			}

			if(minLen == INT_MAX)
				return "";
			return s.substr(minBegin,minLen);
		}
};

int main() {
	Solution s;
	cout<<s.minWindow("ADOBECODEBANC","ABC")<<endl;
}
