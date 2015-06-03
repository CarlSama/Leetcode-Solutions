#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		void calcFrontMax(vector<int>& frontMax,vector<int>& prices){
			int frontMinPrice = prices[0];
			frontMax[0] = 0;
			for(int i=1;i<len;++i){
				frontMinPrice = min(frontMinPrice, prices[i]);
				frontMax[i] = max(frontMax[i-1], prices[i] - frontMinPrice);
			}
		}
		void calcBackMax(vector<int>& backMax,vector<int>& prices){
			int backMaxPrices = prices[len-1];
			backMax[len-1] = 0;
			for(int i=len-2;i>=0;--i){
				backMaxPrices = max(backMaxPrices, prices[i]);
				backMax[i] = max(backMax[i+1], backMaxPrices - prices[i]);
			}
		}
		int maxProfit(vector<int>& prices) {
			len = prices.size();
			if(len == 0)	return 0;
			vector<int> frontMax(len,0);//在第i天卖掉股票的最大获益
			vector<int> backMax(len,0);//在第i天开始买股票的最大收益
			calcFrontMax(frontMax,prices);
			calcBackMax(backMax,prices);

			int maxP = 0;
			for(int i=0;i<len;++i)
				maxP = max(maxP, frontMax[i] + backMax[i]);
			return maxP;
		}
};
int main(){
	int arr[6] = {3,2,6,5,0,3};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.maxProfit(v)<<endl;
}
