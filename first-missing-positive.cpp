#include<iostream>
#include<vector>
using namespace std;

class Solution {
	int len;
	public:
		int firstMissingPositive(vector<int>& nums) {
			len = nums.size();

			for(int idx=0;idx<len;++idx) {
				if(nums[idx] != idx+1 && nums[idx] > 0 && nums[idx] <= len) { //this can be placed
					int toBeArranged = nums[idx];//to be placed at toBeArranged-1
					nums[idx] = -1;//this position was abandened
					while(toBeArranged > 0 && toBeArranged <= len && toBeArranged != nums[toBeArranged-1]) {
						int oldVal = nums[toBeArranged-1];
						nums[toBeArranged-1] = toBeArranged;
						toBeArranged = oldVal;
					}
				}
			}

			for(int idx=0;idx<len;++idx){
				if(nums[idx] != idx+1)
					return idx+1;
			}
			return len+1;
		}
};
int main(){
	int arr[4] = {2,3,1,4};
	vector<int> v(arr,arr+4);
	Solution s;
	cout<<s.firstMissingPositive(v)<<endl;
}
