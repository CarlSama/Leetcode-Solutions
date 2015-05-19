#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include"print.h"
using namespace std;

class Solution {
	private:
		vector<vector<string> >res;
		vector<string> solution;
		vector<int> candidate;
		int totalLevel;
	public:
		void getSolution(){
			solution.clear();
			for(int i=0;i<totalLevel;++i){
				string tmp;
				for(int j=0;j<candidate[i];++j)
					tmp += '.';
				tmp += 'Q';
				for(int j=candidate[i]+1;j<totalLevel;++j)
					tmp += '.';
				solution.push_back(tmp);
			}
			res.push_back(solution);
		}
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
				getSolution(); return ;
			}
			for(int i=0;i<totalLevel;++i){
				if(isValid(currLevel,i)){
					candidate.push_back(i);
					btrack(currLevel+1);
					candidate.pop_back();
				}
			}
		}
		vector<vector<string> > solveNQueens(int n) {
			totalLevel = n;
			btrack(0);
			return res;
		}
};
int main(){
	Solution s;
	vector<vector<string> >res = s.solveNQueens(4);
	Freeman::print(res);
}
