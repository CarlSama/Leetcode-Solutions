#include<iostream>
#include<vector>
#include<cstdlib>
#include<sys/times.h>
#include"print.h"

using namespace std;

class Solution {
	public:
		int partition(vector<int>& nums,int begin,int end){
			int prev = begin - 1;
			for(int i=begin;i<end;++i){
				if(nums[end]<=nums[i]){//将大于等于nums[end]的值放置在其左侧
					swap(nums[++prev], nums[i]);
				}
			}
			swap(nums[++prev],nums[end]);
			return prev + 1;
		}
		int findKthLargest(vector<int>& nums, int k) {
			srand(time(0));

			int begin = 0,end = nums.size()-1;
			while(begin <= end){
				int pivot = partition(nums,begin,end);
				if(pivot == k)
					return nums[pivot-1];
				else if(pivot < k){
					begin = pivot;
//					k -= pivot ;
				}else{
					end = pivot - 2;
				}
			}
			return 0;
		}
};
int main(){
	int arr[3] = {-1,2,0};
	vector<int> v(arr,arr+3);
	Solution s;
	cout<<s.findKthLargest(v ,3)<<endl;;
}
