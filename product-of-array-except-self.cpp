#include<iostream>
#include<vector>

using namespace std;

class Solution {
	int len;
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			len = nums.size();
			vector<int> result(len,1);

			//先计算左侧的乘积
			result[0] = 1;
			for(int i=1; i<len ;++i)
				result[i] = result[i-1] * nums[i-1];

			//再计算右侧对的乘积
			int rightProduct = 1;
			for(int i=len-1; i>=0; --i) {
				result[i] *= rightProduct;
				rightProduct *= nums[i];
			}

			return result;
		}

	void show(vector<int>& res) {
		for(int i=0;i<res.size();++i)
			cout<<res[i]<<" ";
	}
};


int main() {
	int arr[4] = {1,2};
	vector<int> v(arr,arr+2);
	Solution s;
	vector<int> res = s.productExceptSelf(v);
	s.show(res);
}
