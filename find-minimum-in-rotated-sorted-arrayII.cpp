#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int findMin(vector<int>& nums) {
			int len = nums.size();
			//if(len == 0)	return ?;
			int left = 0,right = len -1 ;
			while(left < right){
				if(nums[left] >= nums[right]){
					int mid = left + (right - left) /2;
					//avoid overflow
					if(nums[mid] == nums[left] && nums[mid] == nums[right]){
						++left ;	--right;
					}else if(nums[mid] >= nums[left])
						left = mid + 1;
					else
						right = mid;
				}else{
					break;
				}
			}
			return nums[left];
		}
};
int main(){
	int arr[6] = {5,5,5,5,0,5};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.findMin(v);
}

