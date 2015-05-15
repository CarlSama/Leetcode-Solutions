#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<cmath>
#include"print.h"
using namespace std;

/*
 * Be attention ..
 * We need give non-descending order
 */
class Solution {
	private:
		vector<vector<int> > res;
		vector<int> path;
		int currIdx;
	public:
		// Recurssion method
		// Time O(2^N)
		/*void btrack(vector<vector<int> >& res, vector<int> &path,vector<int>& nums,int currIdx){
			if(currIdx == nums.size()){
				res.push_back(path); return ;
			}
			btrack(res,path,nums,currIdx+1);
			path.push_back(nums[currIdx]);
			btrack(res,path,nums,currIdx+1);
			path.pop_back();
		}
		vector<vector<int> > subsets(vector<int>& nums) {
			currIdx = 0;
			sort(nums.begin(),nums.end());
			btrack(res,path,nums,currIdx);
			return res;
		}*/

		//Iteration
		//因为每个元素只有两种状态，选中（１）和不选（０）
		//可以使用Ｂｉｔ来模拟各种选择的状态
		//Time O(2^N * N)
		vector<vector<int> > subsets(vector<int>& nums) {//bit manipulation
			sort(nums.begin(),nums.end());

			int len = nums.size();
			long long stateNum = pow(2,len);
			vector<vector<int> > res(stateNum,vector<int>());
			for(long long i=0;i<stateNum;++i){
				for(int j=0;j<len;++j){
					if(i&(1<<j))
						res[i].push_back(nums[j]);
				}
			}
			return res;
		}
};
int main(){
	int arr[3] = {4,1,0};
	vector<int> nums(arr,arr+3);
	Solution s;
	vector<vector<int> > res = s.subsets(nums); 
	cout<<res.size();
	Freeman::print(res);
	
}

