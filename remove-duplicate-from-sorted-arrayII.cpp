#include<iostream>
#include<vector>
#include"print.h"

using namespace std;
class Solution {
	int len;
	public:
		int removeDuplicates(vector<int>& nums) {
			len = nums.size();
			int prev = -1;
			int newLen = 0;
			for(int i=0;i<len;++i){
				if(i <= 1){
					++newLen;
					++prev;
				}else if(nums[i] != nums[prev] || nums[i] != nums[prev-1]){ // 0 ~ 2 times
					nums[++prev] = nums[i];
					++newLen;
				}else{//more than 2
				}
			}
			return newLen;
		}
};
int main(){
	int arr[6] = {1,2,2,2,3,4};
	vector<int> v(arr,arr+4);
	Solution s;
	cout<<s.removeDuplicates(v)<<endl;
	Freeman::print(v);
}

