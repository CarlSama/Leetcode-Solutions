#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		int searchInsert(vector<int>& nums, int target) {
			len = nums.size();
			int left=0,right=len-1;
			while(left <= right){
				int mid = left + (right - left) /2;
				if(nums[mid] == target)	return mid;
				if(nums[mid] > target){
					right = mid - 1;
				}else{
					left = mid + 1;
				}
			}
			//not found, now left 
			return left;
		}
};
int main(){
	int arr[4] = {1,3,5,6};
	vector<int> v(arr,arr+4);
	Solution s;
	cout<<s.searchInsert(v,5)<<endl;
	cout<<s.searchInsert(v,2)<<endl;
	cout<<s.searchInsert(v,7)<<endl;
	cout<<s.searchInsert(v,0)<<endl;
}
