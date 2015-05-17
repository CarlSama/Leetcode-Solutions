#include<iostream>
#include<vector>
#include<algorithm>
#include"print.h"

using namespace std;
class Solution {
	private:
		vector<vector<int> >res;
		vector<int> path;
	public:
		void btrack(vector<vector<int> >&res,vector<int>&path,int target,vector<int>&candidates, int currIdx){
			if(target==0){
				res.push_back(path);	return;
			}
			if(currIdx >= candidates.size() || target < 0)	return ;

			// [currIdx, tail) are the same
			int  tail = currIdx;
			while(tail < candidates.size() && candidates[tail] == candidates[currIdx])
				++tail;
			for(int count = 0; count <= tail - currIdx; ++count){
				for(int i=0;i<count;++i)
					path.push_back(candidates[currIdx]);
				btrack(res,path,target - count*candidates[currIdx],candidates,tail);
				for(int i=0;i<count;++i)
					path.pop_back();
			}
		}
		vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			btrack(res,path,target,candidates,0);
			return res;
		}
};
int main(){
	int arr[7] = {10,1,2,7,6,1,5};
	vector<int> candidates(arr,arr+7);
	Solution s;
	vector<vector<int> >res = s.combinationSum2(candidates,8);
	Freeman::print(res);
}
