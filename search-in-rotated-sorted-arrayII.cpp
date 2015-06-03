#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		int search(vector<int>& nums, int target) {
			len = nums.size();
			int left=0,right=len-1;
			while(left <= right){
				int mid = left + (right - left) /2;
				if(nums[mid] == target)	return true;
				if(nums[mid]==nums[left]&&nums[mid]==nums[right]){
					++left;		--right;
				}else if(nums[mid] >= nums[left]){
					if(target >= nums[left] && target < nums[mid])
						right = mid - 1;
					else 
						left = mid + 1;
				}else{
					if(target <= nums[right] && target > nums[mid])
						left = mid + 1;
					else 
						right = mid - 1;
				}
			}
			return false;
		}

};
int main(){
	int arr[6] = {1,4,0,1,1,2};
	vector<int> v(arr,arr+1);
	Solution s;
	cout<<s.search(v,0)<<endl;
}
