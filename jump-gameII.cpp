#include<iostream>
#include<vector>
using namespace std;

class Solution {
		int len;
	public:
		int jump(vector<int>& nums) {
			len = nums.size();

			int steps = 0;
			int front = 0;
			/*
			 * 第一次能达到的都是最小跳数
			 */
			for(int idx=0;idx<len;++idx) {
				if(front < nums[idx] + idx) {
					++steps;
					front = nums[idx] + idx;
				}
				if(front >= len-1)
					break;
			}

			return steps;
	}
};
int main(){
	int arr[15] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	vector<int> v(arr,arr+15);
	Solution s;
	cout<<s.jump(v)<<endl;
}
