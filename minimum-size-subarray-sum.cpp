#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
	public:
		int minSubArrayLen_n(int s, vector<int>& nums) {
			int minLen = INT_MAX;
			int begin=0,end=0;
			int sum = 0;
			int nLen = nums.size();
			while(begin < nLen && end < nLen) {
				sum += nums[end];

				while(sum >= s) {
					minLen = min(minLen, end - begin + 1);
					sum -= nums[begin];
					++begin;
				}

				++end;
			}

			if(minLen == INT_MAX)
				return 0;
			return minLen;
		}

};

int main() {
	int arr[6] = {2,3,1,2,4,3};
	vector<int> v;
	Solution s;
	cout<<s.minSubArrayLen(7,v)<<endl;
}

