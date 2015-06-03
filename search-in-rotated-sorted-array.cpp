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
				if(nums[mid] == target)
					return mid;

				if(nums[mid] >= nums[left]){
					if(target >= nums[left] && nums[mid] > target)
						right = mid - 1;
					else
						left = mid + 1;
				}else{
					if(target <= nums[right] && nums[mid] < target)
						left = mid + 1;
					else
						right = mid - 1;
				}
			}
			return -1;
		}

};
int main(){
	int arr[6] = {5,1,3,0,1,2};
	vector<int> v(arr,arr+3);
	Solution s;
	cout<<s.search(v,3)<<endl;
}
