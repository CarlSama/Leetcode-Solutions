#include<iostream>
#include<vector>
#include<algorithm>
#include"print.h"

using namespace std;

class Solution {
	int len;
	public:
		void nextPermutation(vector<int>& nums) {
			len = nums.size();

			int prev = len -1;
			for( ; prev > 0; --prev){
				if(nums[prev] > nums[prev-1])
					break;
			}

			if(prev == 0) {
				reverse(nums.begin(),nums.end());
				return ;
			}
			--prev;

			int after = len -1;
			for( ; after > prev ; --after){
				if(nums[after] > nums[prev])
					break;
			}

			swap(nums[after], nums[prev]);
			int left = prev + 1, right = len-1;
			while(left < right){
				swap(nums[left], nums[right]);
				++left;	--right;
			}
		}
};
int main(){
	int arr[5] = {5,4,3,2,3};
	vector<int> v(arr,arr+5);
	Solution s;
	s.nextPermutation(v);
	Freeman::print(v);
}
