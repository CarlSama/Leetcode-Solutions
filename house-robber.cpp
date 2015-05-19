#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	public:
		int rob(vector<int>& nums) {
			if(nums.size() == 0)	return 0;

			//dp[i] means at most use to nums[i]
			vector<int> dp(nums.size(),0);
			dp[0] = nums[0];
			dp[1] = max(nums[0],nums[1]);

			for(int i=2;i<nums.size();++i){
				dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
			}
			return dp[nums.size()-1];
		}
};
int main(){
	Solution s;
	int arr[4] = {1,3,4,4};
	vector<int> v(arr,arr+4);
	cout<<s.rob(v)<<endl;
}
