#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	public:
		int minimumTotal(vector<vector<int> > &triangle) {
			if(triangle.size()==0)	return 0;

			int maxLen = triangle.size();
			vector<vector<int> > dp(2,vector<int>(maxLen,0));

			for(int i=0;i<maxLen;++i)
				dp[(maxLen-1)%2][i] = triangle[maxLen-1][i];
			for(int level=maxLen-2; level>=0;--level){
				for(int idx=0;idx<=level;++idx){
					dp[level%2][idx] = min(dp[(level+1)%2][idx],dp[(level+1)%2][idx+1]) + triangle[level][idx];
				}
			}
			return dp[0][0];
		}

};
int main(){
	vector<vector<int> > rect;
	int arr1[1] = {2};
	int arr2[2] = {3,4};
	int arr3[3] = {6,5,7};
	int arr4[4] = {4,1,8,3};

	rect.push_back(vector<int>(arr1,arr1+1));
	rect.push_back(vector<int>(arr2,arr2+2));
	rect.push_back(vector<int>(arr3,arr3+3));
	rect.push_back(vector<int>(arr4,arr4+4));
	Solution s;
	cout<<s.minimumTotal(rect)<<endl;

}
