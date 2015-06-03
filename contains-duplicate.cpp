#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
	public:
		bool containsDuplicate(vector<int>& nums) {
			unordered_set<int> us;
			for(int i=0;i<nums.size();++i){
				if(us.find(nums[i]) == us.end())
					us.insert(nums[i]);
				else
					return true;
			}
			return false;
		}
};
int main(){
	int arr[5] = {1,2,3,4,5};
	vector<int> v(arr,arr+5);
	Solution s;
	cout<<s.containsDuplicate(v)<<endl;
}
