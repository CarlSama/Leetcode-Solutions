#include<iostream>
#include<vector>

using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {


		}
};
int main(){
	int arr[6] = {100,101,1,2,3,102,4};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.longestConsecutive(v)<<endl;
}
