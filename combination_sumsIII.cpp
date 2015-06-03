#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
class Solution {
	public:
		void btrack(vector<vector<int> >& res,vector<int> & path,int curr,int resK,int resSum){
			if(resSum == 0){
				if(resK == 0)
					res.push_back(path);
				return ;
			}
			if(resK == 0 || curr > 9 || resSum < 0)	return ;

			path.push_back(curr);
			btrack(res,path,curr+1,resK-1,resSum-curr);//use
			path.pop_back();
			btrack(res,path,curr+1,resK,resSum);//not use
		}
		vector<vector<int> > combinationSum3(int k, int n) {
			vector<vector<int> > res;
			vector<int> path;
			btrack(res,path,1,k,n);
			return res;
		}
};
int main(){
	Solution s;
	vector<vector<int> > res = s.combinationSum3(3,9);
	Freeman::print(res);
}
