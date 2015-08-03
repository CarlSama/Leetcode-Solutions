#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
class Solution {
	int len;
	public:
		int removeElement(vector<int>& nums, int val) {
			len = nums.size();
			int prev = 0;
			for(int i=0;i<len;++i){
				if(val != nums[i]){
					nums[prev++] = nums[i];
				}
			}
			return prev;
		}
};
int main(){
	int arr[5] = {1,1,1,1,1};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.removeElement(v,1)<<endl;;
	Freeman::print(v);

}


