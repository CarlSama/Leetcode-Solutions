#include<iostream>
#include<vector>
#include"print.h"

using namespace std;
class Solution {
	private:
		vector<vector<int> >res;
		vector<int> path;
		int len;
	public:
		inline void swap(int& a,int& b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		void btrack(vector<vector<int> > &res,vector<int> &path,vector<int>& nums,int currIdx){
			if(currIdx == len){
				res.push_back(path);
				return ;
			}
			for(int i=currIdx; i<len; ++i){
				//use nums[i]
				path.push_back(nums[i]);
				swap(nums[i], nums[currIdx]);
				btrack(res,path,nums,currIdx+1);
				swap(nums[i], nums[currIdx]);
				path.pop_back();
			}
		}
		vector<vector<int> > permute(vector<int>& nums) {
			len = nums.size();
			vector<int> number = nums;
			btrack(res,path,number,0);
			return res;
		}
};
int main(){
	int arr[3]={1,2,3};
	vector<int> nums(arr,arr+3);
	Solution s;
	vector<vector<int> > res = s.permute(nums);
	Freeman::print(res);
}
