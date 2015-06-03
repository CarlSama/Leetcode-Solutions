#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		int maxProfit(vector<int>& prices) {
			len = prices.size();
			if(len == 0)	return 0;

			int minPrices = prices[0];
			int maxGap = 0;
			for(int i=1;i<len;++i){
				minPrices = min(minPrices,prices[i]);
				maxGap = max(maxGap,prices[i] - minPrices);
			}
			return maxGap;
		}
};
int main(){
	int arr[4] = {9,1,3,9};
	vector<int> prices(arr,arr+4);
	Solution s;
	cout<<s.maxProfit(prices)<<endl;
}
