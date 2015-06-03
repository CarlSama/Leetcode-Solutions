#include<iostream>
#include<vector>
#include<string>
#include"print.h"
using namespace std;

int count[8]={3,3,3,3,3,4,3,4};
vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
	private:
		vector<string> res;
		string path;
	public:
		void btrack(vector<string> &res,string& path,string& digits,int currIdx){
			if(currIdx==digits.size()){
				res.push_back(path);
				return ;
			}
			int idx = digits[currIdx]-'2';
			for(int i=0;i<count[idx];++i){
				path.push_back(map[idx][i]);
				btrack(res,path,digits,currIdx+1);
				path.pop_back();
			}
		}
		vector<string> letterCombinations(string digits) {
			if(digits.size()!=0)
				btrack(res,path,digits,0);
			return res;
		}
};
int main(){
	string dig="23";
	Solution s;
	vector<string> res = s.letterCombinations(dig); 
	Freeman::print(res);
}
