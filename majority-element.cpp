#include<iostream>
#include<vector>
using namespace std;

struct RES{
	int num;
	int times;
	RES(int n,int t):num(n),times(t){}
};

class Solution {
	public:
		RES dac(vector<int>& nums,int left,int right){
			if(left > right){
				return RES(0,-1);
			}
			if(left == right){
				return RES(nums[left],1);
			}

			int mid = (left + right) >> 1;
			RES l = dac(nums,left,mid);
			RES r = dac(nums,mid+1,right);

			if(l.times == -1)
				return r.num;
			if(r.times == -1)
				return l.num;


			



		int majorityElement(vector<int>& nums) {
			RES left = 


		int majorityElement_array(vector<int>& nums) {
			int currNum = nums[0];
			int times = 1;
			for(int i=1;i<nums.size();++i){
				if(times == 0){
					currNum = nums[i];	times = 1;
				}else{
					if(currNum == nums[i])
						++times;
					else
						--times;
				}
			}
			return currNum;
		}
};
int main(){
	int arr[6] = {1,2,3,2,2,3};
	Solution s;
	vector<int> nums(arr,arr+6);
	cout<<s.majorityElement(nums)<<endl;
}
