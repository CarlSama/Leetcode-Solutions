#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	public:
		bool isScramble(string s1, string s2) {
			if(s1.size() != s2.size())	return false;
			if(s1.size()==1)
				return s1[0] == s2[0];

			char hash[256] = {0};
			for(int i=0;i<s1.size();++i)
				++hash[s1[i]];
			for(int i=0;i<s2.size();++i){
				if(hash[s2[i]] > 0)
					--hash[s2[i]];
				else{
					return false;
				}
			}//s1 and s2 have same nums of characters

			for(int i=1;i<s1.size();++i){
				if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(i,s2.size()-i)))
					return true;
				if(isScramble(s1.substr(0,i),s2.substr(s1.size()-i,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(0,s1.size()-i)))
					return true;
			}
			return false;
		}
};
int main(){
	Solution s;
	cout<<s.isScramble("abcd","bdac")<<endl;
}
