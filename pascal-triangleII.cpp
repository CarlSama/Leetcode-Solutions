#include<iostream>
#include<vector>
#include"print.h"

using namespace std;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			vector<int> res;
			for(int i=0;i<=rowIndex;++i){
				for(int idx=res.size()-1;idx>0;--idx)
					res[idx] = res[idx] + res[idx-1];
				res.push_back(1);
			}
			return res;
		}
};
int main(){
	Solution s;
	vector<int> res = s.getRow(1);
	Freeman::print(res);
}
