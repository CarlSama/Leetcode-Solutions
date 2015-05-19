#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution {
	private:
		vector<int> candidate;
		int totalLevel;
		int solutions;
	public:
		bool isValid(int currLevel,int position){
			if(currLevel==0)	return true;
			for(int i=0;i<currLevel;++i){//check previous level
				if(position==candidate[i] || abs(position - candidate[i])==abs(i - currLevel))
					return false;
			}
			return true;
		}
		void btrack(int currLevel){
			if(currLevel == totalLevel){
				++solutions; return ;
			}
			for(int i=0;i<totalLevel;++i){
				if(isValid(currLevel,i)){
					candidate.push_back(i);
					btrack(currLevel+1);
					candidate.pop_back();
				}
			}
		}
		int totalNQueens(int n) {
			totalLevel = n;
			btrack(0);
			return solutions;
		}
};
int main(){
	Solution s;
	cout<< s.totalNQueens(4)<<endl;;
}
