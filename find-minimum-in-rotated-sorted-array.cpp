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
				if(nums[left] > nums[right]){
					int mid =  (left & right) + ((left ^ right) >> 1);
					//avoid overflow
					//小心，+的优先级高于>>
					if(nums[mid] >= nums[left])
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
	int arr[6] = {3,4,5,0,1,2};
	vector<int> v(arr,arr+3);
	Solution s;
	cout<<s.findMin(v);
}

