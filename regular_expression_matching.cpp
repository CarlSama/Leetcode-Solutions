#include<iostream>
using namespace std;

class Solution {
	private:
		int slen;
		int plen;
	public:
		inline bool isSame(char c1,char c2){
			return c2=='.'||c1==c2;
		}
		bool btrack(string& s,int sidx,string p,int pidx){
			if(sidx==slen && pidx==plen)	return true;
			if(sidx==slen){
				while(pidx+1<plen && p[pidx+1]=='*')
					pidx += 2;
				return pidx == plen;
			}
			if(pidx==plen)	return false;

			if(pidx+1<plen && p[pidx+1] == '*'){
				if(btrack(s,sidx,p,pidx+2))//match none
					return true;
				int incr = 0;//match at least 1
				while(sidx+incr<slen && isSame(s[sidx+incr],p[pidx])) {
					if( btrack(s,sidx+incr+1,p,pidx+2))
						return true;
					else
						++incr;
				}
				return false;
			}else{
				if(isSame(s[sidx],p[pidx])){
					return btrack(s,sidx+1,p,pidx+1);
				}else{
					return false;
				}
			}
		}
		bool isMatch(string s, string p) {
			slen = s.size();	plen = p.size();
			return btrack(s,0,p,0);
		}
};

int main(){
	Solution s;
	cout<<s.isMatch("aa","a")<<endl; 
	cout<<s.isMatch("aa","aa")<<endl; 
	cout<<s.isMatch("aaa","aa")<<endl;
	cout<<s.isMatch("aa", "a*")<<endl;
	cout<<s.isMatch("aa", ".*")<<endl;
	cout<<s.isMatch("ab", ".*")<<endl;
	cout<<s.isMatch("aab", "c*a*b")<<endl;
}
