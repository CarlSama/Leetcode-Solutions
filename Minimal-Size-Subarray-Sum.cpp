#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	int len;
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			len = nums.size();

			int sum=0;
			int minLen = -1;
			int start;
			for(int i=0;i<len;++i){
				sum += nums[i];
				if(sum >= s){//the sum from 0 to i
					start = i;
					minLen = i - 0 + 1;
					break;
				}
			}
			if(minLen == -1)	return 0;

			bool isUpdate = false;
			for(int i=1;i<len;++i){
				sum -= nums[i-1];
				if(sum >= s){
					isUpdate = true;
					minLen = min(minLen,start-i+1);
				}else{
					for(int j=start+1;j<len;++j){
						sum += nums[j];
						if(sum >= s){
							isUpdate = true;
							start = j;
							minLen = min(minLen, j-i+1);
							break;
						}
					}
				}
				if(!isUpdate)
					break;
			}
			return minLen;
		}
};
int main(){
	int arr[14] = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
	vector<int> v(arr,arr+14);
	Solution s;
	cout<<s.minSubArrayLen(80,v)<<endl;
}
