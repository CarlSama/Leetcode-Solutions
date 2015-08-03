#include<iostream>
#include<vector>
using namespace std;

class Solution {
	int len;
	public:
		bool canJump(vector<int>& nums) {
			len = nums.size();

			int maxFront = 1;
			for(int idx=0;idx<len;++idx)  {
				if(maxFront < idx + 1)	return false;
				maxFront = max(maxFront, idx+1+nums[idx]);
			}
			return true;
		}
};
int main(){
	int arr[5] = {2,3,1,1,4};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.canJump(v)<<endl;
	int arr1[5] = {3,2,1,0,4};
	vector<int> v1(arr1,arr1+5);
	cout<<s.canJump(v1)<<endl;
}
