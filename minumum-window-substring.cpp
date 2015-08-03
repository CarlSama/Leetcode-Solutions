#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		string minWindow(string s, string t) {
			int slen = s.size();
			int tlen = t.size();
			for(int front=0 ; front<slen ; ++front) {
				unordered_
				for(int back=front+tlen-1 ; back<slen ; ++back) {
		}
};

int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution s;
	cout<<s.minWindow(s,t)<<endl;
}
