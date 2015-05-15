#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	private:
		vector<vector<int> > res;
		vector<int> path;
		int currIdx;
	public:
		void btrack(vector<vector<int> >& res, vector<int> &path,vector<int>& nums,int currIdx){
			if(currIdx == nums.size()){
				res.push_back(path); return ;
			}
			path.push_back(nums[currIdx]);
			btrack(res,path,nums,currIdx+1);
			path.pop_back();
			btrack(res,path,nums,currIdx+1);
		}
		vector<vector<int> > subsets(vector<int>& nums) {
			currIdx = 0;
			btrack(res,path,nums,currIdx);
			return res;
		}
};
int main(){
	int arr[3] = {1,2,3};
	vector<int> nums(arr,arr+3);
	Solution s;
	vector<vector<int> > res = s.subsets(nums); 
	cout<<res.size();
	Freeman::print(res);
	
}

