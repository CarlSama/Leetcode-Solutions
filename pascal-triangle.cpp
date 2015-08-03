#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			vector<vector<int> > res;
			if(numRows == 0)	return res;

			vector<int> level;
			level.push_back(1);
			for(int i=1;i<=numRows;++i){
				res.push_back(level);

				for(int idx=level.size()-1 ; idx>0 ; --idx)
					level[idx] = level[idx] + level[idx-1];
				level.push_back(1);
			}
			return res;
		}
};

int main(){
	Solution s;
	vector<vector<int> > res = s.generate(5);
	Freeman::print(res);
}
