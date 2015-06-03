#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	public:
		int rangeRob(vector<int>& nums,int first,int last){
			if(first > last)	return 0;
			if(last - first  < 2)
				return max(nums[first],nums[last]);

			int dp[3];	dp[first%3] = nums[first];	dp[(first+1)%3] = max(nums[first], nums[first+1]);
			for(int i=first+2; i<=last; ++i){
				dp[i%3] = max(dp[(i-2)%3]+nums[i], dp[(i-1)%3]);
			}
			return max(dp[0],max(dp[1],dp[2]));
		}

		int rob(vector<int>& nums) {
			if(nums.size() == 1)	return nums[0];
			return max(rangeRob(nums,0,nums.size()-2), rangeRob(nums,1,nums.size()-1));
		}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.rob(v)<<endl;
}
