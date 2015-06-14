#include<iostream>
#include<vector>
using namespace std;

class Solution {
		int len;
	public:
		int jump(vector<int>& nums) {
			len = nums.size();
			vector<int> steps(len,len);

			steps[0] = 0;
			for(int idx=0;idx<len-1;++idx) {
				//our jump range is [idx+1, idx+nums[idx]]
				//which would takes us steps[idx] + 1
				for(int affect=idx+1;affect <len && affect<=idx+nums[idx];++affect) {
					steps[affect] = min(steps[affect], steps[idx] + 1);
				}
			}

			return steps[len-1];
	}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.jump(v)<<endl;
}
