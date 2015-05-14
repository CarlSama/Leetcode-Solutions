#include<iostream>
#include<string>
using namespace std;

class Solution {
	private:
		int slen,plen;
	public:
		bool isSame(char c1,char c2){
			return c2=='?'||c1==c2;
		}

		bool btrackCheck(string& s,int sidx,string& p,int pidx){
			if(sidx==slen && pidx==plen)	return true;
			if(sidx==slen){
				while(pidx<plen && p[pidx]=='*')
					++pidx;
				return pidx==plen;
			}
			if(pidx==plen)	return false;

			if(p[pidx]=='*'){// We may need to trace back
				int currSIdxBegin = sidx;//first match 0 elem
				while(currSIdxBegin <= slen){
					if(btrackCheck(s,currSIdxBegin,p,pidx+1) == false)
						++currSIdxBegin;
					else
						return true;
				}
				return false;
			}else{
				return isSame(s[sidx],p[pidx]) && btrackCheck(s,sidx+1,p,pidx+1);
			}
		}

		bool isMatch(string s, string p){
			slen = s.size();
			plen = p.size();
			return btrackCheck(s,0,p,0);
		}
};

int main(){
	Solution s;
/*	cout<<s.isMatch("aa","a")<<endl;  
	cout<<s.isMatch("aa","aa")<<endl;
	cout<<s.isMatch("aaa","aa")<<endl;
	cout<<s.isMatch("aa", "*")<<endl; 
	cout<<s.isMatch("aa", "a*")<<endl;
*/	cout<<s.isMatch("ab", "?*")<<endl;
	cout<<s.isMatch("aab", "c*a*b")<<endl;
}
