#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
	int len;
	public:
		int maxArea(vector<int>& height) {
			len = height.size();
			int left=0,right = len -1;
			int result = 0;
			while(left < right) {
				result = max(result, (right - left) * min(height[left], height[right]));
				if(height[left] < height[right]) {
					++left;
				}else{
					--right;
				}
			}
			return result;
		}
};
int main(){
	int arr[6] = {1,2,3,4,5,6};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.maxArea(v)<<endl;
}
