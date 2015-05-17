#include<iostream>
#include<vector>
#include<algorithm>
#include"print.h"

using  namespace std;
class Solution {
	private:
		vector<vector<int> > res;
		vector<int> path;
	public:
		void btrack(vector<vector<int> >&res,vector<int>&path,int target,vector<int>&candidates,int currIdx){
			if(target == 0){
				res.push_back(path);
				return;
			}
			if(target < 0 || currIdx >= candidates.size())	return; 
			int usedTimes = 0;
			while(target - usedTimes * candidates[currIdx] >= 0){
				for(int i=0;i<usedTimes;++i)
					path.push_back(candidates[currIdx]);
				btrack(res,path,target - usedTimes * candidates[currIdx],candidates,currIdx+1);
				for(int i=0;i<usedTimes;++i)
					path.pop_back();
				++usedTimes;
			}
		}

		vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
			if(target != 0)	{
				sort(candidates.begin(),candidates.end());
				btrack(res,path,target,candidates,0);
			}
			return res;
		}
};
int main(){
	int arr[4] ={2,3,6,7};
	vector<int> candidates(arr,arr+4);
	Solution s;
	vector<vector<int> > res=s.combinationSum(candidates,7);
	Freeman::print(res);
}
