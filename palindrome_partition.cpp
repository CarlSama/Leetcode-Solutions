#include<iostream>
#include<vector>
#include<string>
#include"print.h"
using namespace std;

class Solution {
	private:
		vector<vector<string> >res;
		vector<string> path;
		string fragment;
	public:
		bool isPalindromic(string s){
			if(s.size()==0)	return false;
			int front=0,back=s.size()-1;
			while(front < back){
				if(s[front]!=s[back])
					return false;
				++front;	--back;
			}
			return true;
		}
		void btrack(vector<vector<string> >&res,vector<string>&path,string& fragment,string& s,int currIdx){
			if(currIdx==s.size()){
				if(isPalindromic(fragment)){
					path.push_back(fragment);
					res.push_back(path);
					path.pop_back();
				}
				return;
			}
			if(isPalindromic(fragment)){//Not using s[currIdx]
				string backup(fragment);
				path.push_back(fragment);
				fragment = s[currIdx];

				cout<<"Not using :";
				cout<<fragment<<"  "<<backup<<endl;
				for(int i=0;i<path.size();++i)
					cout<<path[i]<<"  ";
				cout<<endl;
				btrack(res,path,fragment,s,currIdx+1);
				fragment = backup;
				path.pop_back();
			}
			fragment.push_back(s[currIdx]);
			cout<<"Using :"<<fragment<<endl;
			for(int i=0;i<path.size();++i)
				cout<<path[i]<<"  ";
			cout<<endl;
			btrack(res,path,fragment,s,currIdx+1);
			fragment.pop_back();
		}

		vector<vector<string>> partition(string s) {
			btrack(res,path,fragment,s,0);
			return res;
		}
};
int  main(){
	string str("aab");
	Solution s;
	vector<vector<string> > res = s.partition(str);
	Freeman::print(res);
}
