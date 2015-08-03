#include<iostream>
#include<vector>
#include"print.h"

using namespace std;
class Solution {
	int len;
	public:
		int removeDuplicates(vector<int>& nums) {
			len = nums.size();
			int prev = 0;
			int newLen = 0;
			for(int i=0;i<len;++i){
				if(i==0){
					++newLen;
				}else if(nums[i] != nums[prev]){
					nums[++prev] = nums[i];
					++newLen;
				}else{
					;//do nothing
				}
			}
			return newLen;
		}
};
int main(){
	int arr[6] = {1,1,2,2,3,4};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.removeDuplicates(v)<<endl;
	Freeman::print(v);
}

