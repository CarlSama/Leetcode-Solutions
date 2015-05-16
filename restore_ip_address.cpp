#include<iostream>
#include"print.h"
#include<vector>

using namespace std;

class Solution {
	private:
		vector<string> res;
		string path;
	public:
		inline bool checkNumRange(string s,int &begin){
			if(begin == s.size()) return false;
			int num = 0;
			while(s[begin] != '.'){
				num *= 10;
				num += s[begin] - '0';
				++begin;
			}
			++begin;//jump '.'
			return num > 0 && num <= 255;
		}
		bool isValidIpAddress(string s){
			int idx = 0, lastNum = 0;
			if(checkNumRange(s,idx) && checkNumRange(s,idx) && checkNumRange(s,idx)){
				if(idx == s.size()) return false;
				while(s[idx] != '\0'){
					lastNum *= 10;
					lastNum += s[idx] - '0';
					++idx;
				}
				return lastNum > 0 && lastNum <= 255;
			}	
			return false;
		}
		void btrack(vector<string>& res,string& path,int dotNum,string& s,int currIdx){
			if(dotNum == 3){
				//将后面的全部放入path中
				int len = path.size();
				path += s.substr(currIdx,s.size() - currIdx);
				if(isValidIpAddress(path))
					res.push_back(path);
				path = path.substr(0,len);
				return;
			}
			if(currIdx == s.size())
				return ;

			path.push_back('.');	path.push_back(s[currIdx]);
			btrack(res,path,dotNum+1,s,currIdx+1);
			path.pop_back();	path.pop_back();

			path.push_back(s[currIdx]);
			btrack(res,path,dotNum,s,currIdx+1);
			path.pop_back();
		}
		vector<string> restoreIpAddresses(string s) {
			if(s.size() < 4) return res;
			path.push_back(s[0]);//消除首部为'.'的情况
			btrack(res,path,0,s,1);
			return res;
		}
};

int main(){
	string s = "25525511135";
	Solution so;
	vector<string> res = so.restoreIpAddresses(s);
	Freeman::print(res);
}
