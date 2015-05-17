#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include"print.h"

using namespace std;
class Solution {
	private:
		vector<vector<int> >res;
		vector<int> path;
		unordered_map<int,int> map;
	public:
		void btrack(vector<int>& nums,int currIdx){
			if(currIdx == nums.size()){
				res.push_back(path);
				return ;
			}
			for(auto iter = map.begin();iter!=map.end();++iter){
				if(iter->second){
					path.push_back(iter->first);
					--iter->second;
					btrack(nums,currIdx+1);
					++iter->second;
					path.pop_back();
				}
			}
		}
		void initMap(vector<int>& nums){
			for(int i=0;i<nums.size();++i){
				++map[nums[i]];
			}
		}
		vector<vector<int> > permuteUnique(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			initMap(nums);
			btrack(nums,0);
			return res;
		}
};
int main(){
	int arr[7]={1,1,3,3};
	vector<int> nums(arr,arr+4);
	Solution s;
	vector<vector<int> > res = s.permuteUnique(nums);
	Freeman::print(res);
}

