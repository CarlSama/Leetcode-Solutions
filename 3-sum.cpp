#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct OterTwo {
	int i,j;
	OterTwo(int ii,int jj) : i(ii),j(jj){}
};

class Solution {
	int len;
	vector<vector<int> >res;
	public:
		vector<vector<int> > threeSum(vector<int>& nums) {
			len = nums.size();

			sort(nums.begin(),nums.end());

			for(int i=0;i<len;++i) {
				if(i==0 || nums[i] != nums[i-1]) {
					int left = i+1,right = len-1;
					while(left < right) {
						if(nums[i] + nums[left] + nums[right] < 0){
							++left;
						}else if(nums[i] + nums[left] + nums[right] > 0){
							--right;
						}else{
							vector<int> tmp;
							tmp.push_back(nums[i]);	tmp.push_back(nums[left]);	tmp.push_back(nums[right]);	
							res.push_back(tmp);
							while(left < right && nums[left] == nums[left+1])	++left;
							while(left < right && nums[right] == nums[right-1])	--right;
							++left; --right;
						}
					}
				}
			}
			return res;
		}
};

int main(){
	int arr[6] = {-1,0,1,2,-1,-4};
	vector<int> v(arr,arr+6);
	Solution s;
	vector<vector<int> > vv = s.threeSum(v);
	for(int i=0;i<vv.size();++i){
		for(int j=0;j<vv[i].size();++j)
			cout<<vv[i][j]<<" ";
		cout<<endl;
	}
}



