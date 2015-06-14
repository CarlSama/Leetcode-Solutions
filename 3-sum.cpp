#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	int len;
	vector<vector<int> >res;
	public:
		vector<vector<int> > threeSum(vector<int>& nums) {
			len = nums.size();
			sort(nums.begin(),nums.end());

			for(int first=0;first<len && nums[first] <= 0;++first) {
				if(first>0 && nums[first] == nums[first-1])
					continue;

				int second=first+1,third=len-1;

				while(second < third) {
					if(nums[second] + nums[third] > (-1)*nums[first]) 
						--third;
					else if(nums[second] + nums[third] < (-1) * nums[first])
						++second;
					else {
						vector<int> tmp;
						tmp.push_back(nums[first]);	
						tmp.push_back(nums[second]);
						tmp.push_back(nums[third]);
						res.push_back(tmp);
						--third;	++second;
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



