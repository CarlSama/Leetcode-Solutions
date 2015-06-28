#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int res = nums[0];
			for(int i=1;i<nums.size();++i) 
				res ^= nums[i];
			return res;
		}
};

int main(){
	int arr[5] = {1,1,2,3,2};
	vector<int> v(arr,arr+5);

	Solution s;
	cout<<s.singleNumber(v)<<endl;
}
