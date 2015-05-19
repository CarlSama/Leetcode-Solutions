#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			if(nums.size() == 0)	return 0;
			int curr = nums[0];
			int max = nums[0];
			for(int i=1;i<nums.size();++i){
				if(curr > 0){
					curr += nums[i];
				}else{
					curr = nums[i];
				}
				max = max > curr ? max : curr;
			}
			return max;
		}
};
int main(){
	int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v(arr,arr+9);
	Solution s;
	cout<<s.maxSubArray(v)<<endl;
}
