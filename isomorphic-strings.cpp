#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/*
 * ASCII码足够吗？　256可以处理
 */
class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			unordered_map<char,char> replaceTo;
			unordered_set<char> isUsed;

			for(int i=0;i<s.size();++i) {
				if(replaceTo.find(s[i]) == replaceTo.end()) {
					if(isUsed.find(t[i]) == isUsed.end()) {
						replaceTo.insert(pair<char,char>(s[i],t[i]));
						isUsed.insert(t[i]);
					}else
						return false;
				}else{
					if(replaceTo.find(s[i])->second != t[i])
						return false;
				}
			}
			return true;
		}
};

int main(){
	Solution s;
	cout<<s.isIsomorphic("egg","add")<<endl;
	cout<<s.isIsomorphic("foo","bar")<<endl;

}
