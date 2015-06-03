#include<iostream>
#include<vector>

using namespace std;
class Solution {
	int len;
	public:
		int maxProduct(vector<int>& nums) {
			len = nums.size();
			if(len == 0)	return 0;

			int begin = 0;
			for(;begin<len && nums[begin] == 0;++begin){}
			if(begin == len)	return 0;

			int dp[2], maxPro = nums[begin];
			if(nums[begin] > 0){
				dp[0] = nums[begin];	dp[1] = 0;
			}else{
				dp[0] = 0;	dp[1] = nums[begin];
			}
			for(++begin;begin<len;++begin){
				if(nums[begin] > 0){
					if(dp[0]==0)
						dp[0] = nums[begin];
					else
						dp[0] *= nums[begin];
					dp[1] *= nums[begin];
				}else{
					int oldDp = dp[1];
					if(dp[0] == 0)
						dp[1] = nums[begin];
					else
						dp[1] = dp[0] * nums[begin];
					dp[0] = oldDp * nums[begin];
				}
				maxPro = max(maxPro, dp[0]);
			}
			return maxPro;
		}
};
int main(){
	int arr[4] = {-19,-3,-4,4};
	Solution s;
	vector<int> v(arr,arr+4);
	cout<<s.maxProduct(v)<<endl;
}
