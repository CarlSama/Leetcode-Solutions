#include<iostream>
#include<algorithm>
#include"print.h"
using namespace std;
class Solution {
	int len;
	public:
		void putZero(vector<int>& nums){
			int prev = -1;
			for(int i=0;i<len;++i){
				if(nums[i] == 0)
					swap(nums[i],nums[++prev]);
			}
		}
		void putTwo(vector<int>& nums){
			int back = len;
			for(int i=len-1;i>=0;--i){
				if(nums[i] == 2)
					swap(nums[i], nums[--back]);
			}
		}

		void sortColors(vector<int>& nums) {
			len = nums.size();

	Freeman::print(nums);
			putZero(nums);
	Freeman::print(nums);
			putTwo(nums);
	Freeman::print(nums);
		}
};
int main(){
	int arr[6] = {0,1,2,1,2,0};
	vector<int> nums(arr,arr+6);
	Solution s;
	s.sortColors(nums);
	Freeman::print(nums);
}
