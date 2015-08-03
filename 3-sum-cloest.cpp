#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(),nums.end());

			int cloest = abs(nums[0] + nums[1] + nums[2] - target);
			for(int i=0;i<len;++i) {
				if(i==0 || nums[i] == nums[i-1]) {
					int left=i+1,right=len-1;
					while(left < right) {
						if(nums[i] + nums[left] + nums[right] 


		}
};
int main(){
}
