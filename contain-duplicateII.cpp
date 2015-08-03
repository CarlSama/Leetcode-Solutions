#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
	int len;
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_set<int> us;
			len = nums.size();
			if(len ==0 || k < 0)	return false;

			for(int idx=0;idx<len;++idx) {
				/*
				 * it's smart that we only matain k elems in set
				 */
				if( idx > k ) 
					us.erase(nums[idx - k + 1]);

				if(us.find(nums[idx]) != us.end())
					return true;
				us.insert(nums[idx]);
			}
			return false;
		}
};

int main(){
	int arr[9] = {1,1,3,4,1,6,7,8,9};
	vector<int> v(arr,arr+2);
	Solution s;
	cout<<s.containsNearbyDuplicate(v,1);
}
