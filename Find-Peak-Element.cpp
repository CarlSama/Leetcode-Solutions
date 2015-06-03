#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class Solution {
	int len;
	public:
		int findPeakElement(vector<int>& nums) {
			len = nums.size();
			if(len == 0)	return -1;
			if(len == 1)	return 0;
			for(int i=1;i<len;++i){
				if(i+1 < len){
					if(nums[i-1] < nums[i] && nums[i+1] < nums[i])
						return i;
				}
			}
			return nums[0] > nums[len-1] ? 0 : len-1;
		}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	vector<int> v(arr,arr+3);
	Solution s;
	cout<<s.findPeakElement(v)<<endl;
}
