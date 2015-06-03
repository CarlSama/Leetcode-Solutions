#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	int len;
	public:
		int lowerBoud(vector<int>&nums,int target){
			int left=0,right=len-1;
			while(left <= right){
				int mid = left + (right - left) /2;
				if(nums[mid] < target)
					left = mid + 1;
				else if(nums[mid] > target)
					right = mid - 1;
				else{
					if(mid==0 || nums[mid-1]!=target)
						return mid+1;
					else
						right = mid -1;
				}
			}
			return -1;
		}
		int upperBound(vector<int>&nums,int target){
			int left=0,right=len-1;
			while(left <= right){//need to have == here
			int mid = left + (right - left) /2;
				if(nums[mid] > target)
					right = mid - 1;
				else if(nums[mid] < target)
					left = mid + 1;
				else{
					if(mid == len-1 || nums[mid+1]!=target)
						return mid+1;
					else
						left = mid + 1;
				}
			}
			return -1;
		}
		vector<int> searchRange2(vector<int>& nums, int target) {
			len = nums.size();
			if(len == 0)	return vector<int>(2,-1);
			int low = lowerBoud(nums,target);
			int upp = upperBound(nums,target);
			vector<int> res;
			res.push_back(low);	res.push_back(upp);
			return res;
		}
		vector<int> searchRange1(vector<int>& nums, int target) {
			vector<int>::iterator lo = std::lower_bound(nums.begin(),nums.end(),target);//first elem not less than target
			vector<int>::iterator up = std::upper_bound(nums.begin(),nums.end(),target);//first elem great than target
			if(lo == nums.end() || *lo != target)
				return vector<int>(2,-1);
			vector<int> res;
			res.push_back(lo - nums.begin());	res.push_back(up - nums.begin() -1);
			return res;
		}
		vector<int> searchRange(vector<int>& nums, int target) {
			pair<vector<int>::iterator, vector<int>::iterator > bounds;
			bounds = std::equal_range(nums.begin(), nums.end(), target);
			if(bounds.first == nums.end() || *(bounds.first) != target)
				return vector<int>(2,-1);
			vector<int> res;
			res.push_back(bounds.first - nums.begin());	res.push_back(bounds.second - nums.begin() -1);
			return res;
		}
};
int main(){
	int arr[1] = {1};
	vector<int> v(arr,arr+1);
	Solution s;
	vector<int> res = s.searchRange(v,1);
	cout<<res[0]<<res[1]<<endl;
}
