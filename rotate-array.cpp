#include<iostream>
#include"print.h"
#include<vector>

using namespace std;

class Solution {
	int len;
	public:
		void rangeRotate(vector<int>& nums,int from,int to){
			int tmp;
			while(from < to){
				tmp = nums[from];
				nums[from] = nums[to];
				nums[to] = tmp;

				++from;	--to;
			}
		}

		void rotate(vector<int>& nums, int k) {
			len = nums.size();
			k = k % len;
			if(k == 0)	return ;

			//1)	Use auxilary array,O(n), O(k) ?
			//2)	Two rotate !

			rangeRotate(nums,0,len-1);
			rangeRotate(nums,0,k-1);
			rangeRotate(nums,k,len-1);
		}
};
int main(){
	int arr[7] = {1,2,3,4,5,6,7};
	vector<int> v(arr,arr+7);
	Solution s;
	s.rotate(v,3);
	Freeman::print(v);
}
