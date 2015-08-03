#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	int len;
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target) {
			len = nums.size();
			sort(nums.begin(),nums.end());
			vector<vector<int> > res;
			
			for(int i=0;i<len-3;++i){
				if(i>0 && nums[i] == nums[i-1]) 	
					continue;
					
				for(int j=i+1;j<len-2;++j){
					if(j>i+1 && nums[j] == nums[j-1])
						continue;
					int left = j+1,right = len-1;
					while(left < right) {
						if(nums[i] + nums[j] + nums[left] + nums[right] == target){
							vector<int> tmp;
							tmp.push_back(nums[i]);tmp.push_back(nums[j]);tmp.push_back(nums[left]);tmp.push_back(nums[right]);
							res.push_back(tmp);
							++left;	--right;
							while(left < right && nums[left] == nums[left-1]) ++left;
							while(left < right && nums[right] == nums[right+1]) --right;
						}else if(nums[i] + nums[j] + nums[left] + nums[right] > target){
							--right;
						}else{
							++left;
						}
					}
				}
			}
			return res;
		}
};
int main(){
	int arr[8] = {0,0,0,0};
	vector<int> v(arr,arr+4);
	Solution s;
	vector<vector<int > > res = s.fourSum(v,0);
	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}

