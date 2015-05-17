#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
class Solution {
	private:
		vector<string> res;
		string str;
	public:
		void btrack(vector<string>&res,string& str,int n,int left,int right){
			if(left > n || right > n || right > left)	return ;
			if(left == n && right == n){
				res.push_back(str);
				return;
			}
			str.push_back('(');
			btrack(res,str,n,left+1,right);
			str.pop_back();
			str.push_back(')');
			btrack(res,str,n,left,right+1);
			str.pop_back();
		}
		vector<string> generateParenthesis(int n) {
			btrack(res,str,n,0,0);
			return res;
		}
};
int main(){
	Solution s;
	vector<string> res = s.generateParenthesis(3);
	Freeman::print(res);
}

