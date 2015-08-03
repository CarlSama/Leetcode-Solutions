#include<iostream>
#include<vector>
using namespace std;

class Solution {
	int  len;
	public:
		vector<int> majorityElement(vector<int>& nums) {
			len = nums.size();
			int cand1,cand2;
			int num1=0,num2=0;

			for(int i = 0;i < len; ++i) {
				if(nums[i] == cand1 || num1 == 0) {
					++num1;
					cand1 = nums[i];
				}else if(nums[i] == cand2 || num2 == 0) {
					++num2;
					cand2 = nums[i];
				}else {
					--num1;		
					--num2;
				}
			}
			cout<<cand1<<" "<<cand2<<endl;

			//需要检查cand1和cand2真实的数目 111223344
			num1 = num2 = 0;
			for(int i=0;i<len;++i) {
				if(nums[i] == cand1)
					++num1;
				else if(nums[i] == cand2)
					++num2;
			}

			vector<int> result;
			if(num1 > len / 3) result.push_back(cand1);
			if(num2 > len / 3) result.push_back(cand2);

			return result;
		}
};

int main() {
	int arr[8] = {1,1,1,2,2,2,3,3};
	vector<int> v(arr,arr+8);
	Solution s;
	vector<int> res = s.majorityElement(v);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
}
