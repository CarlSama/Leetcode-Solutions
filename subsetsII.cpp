#include<iostream>
#include<vector>
#include<algorithm>
#include"print.h"

using namespace std;

class Solution {
	private:
		vector<vector<int> > res;
		vector<int> path;

	public:
		void btrack(vector<vector<int> >& res, vector<int>& path,vector<int>& nums,int currIdx){
			if(currIdx == nums.size()){
				res.push_back(path);	return ;
			}
			int nextIdx = currIdx;
			while(nextIdx<nums.size() && nums[nextIdx]==nums[currIdx])
				++nextIdx;

			//we have nextIdx-currIdx same elem, so there are nextIdx-currIdx+1 situation
			for(int count=nextIdx-currIdx;count>=0;--count){
				for(int i=0;i<count;++i)
					path.push_back(nums[currIdx]);
				btrack(res,path,nums,nextIdx);
				for(int i=0;i<count;++i)
					path.pop_back();
			}
		}
		vector<vector<int> > subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			btrack(res,path,nums,0);
			return res;
		}
};

int main(){
	int arr[3] = {2,1,2};
	vector<int> num(arr,arr+3);

	Solution s;
	vector<vector<int> > res = s.subsetsWithDup(num);
	Freeman::print(res);
}


