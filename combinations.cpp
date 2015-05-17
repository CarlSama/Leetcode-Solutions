#include<iostream>
#include<vector>
#include"print.h"

using  namespace std;

class Solution {
	vector<vector<int> >res;
	vector<int> path;
	public:
		void btrack(vector<vector<int> >&res,vector<int>&path,int n,int curr,int k){
			if(k==0){
				res.push_back(path);
				return;
			}
			if(curr > n)	return;
			btrack(res,path,n,curr+1,k);//not use
			path.push_back(curr);//use
			btrack(res,path,n,curr+1,k-1);
			path.pop_back();
		}
		vector<vector<int> > combine(int n, int k) {
			btrack(res,path,n,1,k);
			return res;
		}
};
int main(){
	Solution s;
	vector<vector<int> >res = s.combine(4,2);
	Freeman::print(res);
}

