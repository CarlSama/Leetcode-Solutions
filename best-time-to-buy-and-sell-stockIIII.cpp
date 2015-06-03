#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len;
	public:
		void getRange(vector<vector<int> > & maxFromRange){
			for(int i=0;i<len;++i){
				for(int j=0;j<len;++j){

		int maxProfit(int k, vector<int>& prices) {
			len = prices.size();
			vector<vector<int> > maxFromRange(len,vector<int>(len,0));

			vector<vector<int> > front(k,vector<int>(len,0));
			vector<vector<int> > back(k,vector<int>(len,0));
			frontCalc(front);	backCalc(back);

		}
};
int main(){
}
