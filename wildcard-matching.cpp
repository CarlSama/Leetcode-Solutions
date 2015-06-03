#include<iostream>
#include<vector>
#include<string>
#include"print.h"
using namespace std;

class Solution {
	private:
		int slen,plen;
	public:
		bool isSame(char c1,char c2){
			return c2=='?'||c1==c2;
		}

		/*
		 * TLE for case ""aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b" "
		 */
		/*bool btrackCheck(string& s,int sidx,string& p,int pidx){
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
		}*/

		/*
		bool isMatch_greedy(string s, string p){
			slen = s.size();	plen = p.size();

			// Yes, It's working
			//let's do a qucick check for cut leaf
			int pStrongLen = 0;
			for(int i=0;i<plen;++i){
				if(p[i] != '*')
					++pStrongLen;
			}
			if(pStrongLen > slen) return false;//even * all became empty,still longer

			int sidx=0,pidx=0;
			int currSIdx=-1,currPIdx=-1;
			while((sidx < slen && pidx < plen) || (currSIdx >= 0 && currSIdx < slen)){
				if(sidx == slen && pidx == plen)	return true;
				if(sidx == slen){
					while(pidx < plen && p[pidx] == '*')
						++pidx;
					if(pidx == plen)	
						return true;
					else{
						sidx = ++currSIdx;
						pidx = currPIdx;
						continue;
					}
				}
				if(pidx == plen){
					sidx = ++currSIdx;
					pidx = currPIdx;
					continue;
				}

				if(p[pidx] == '*'){
					currSIdx = sidx;
					currPIdx = ++pidx; 
				}else{
					if(isSame(s[sidx],p[pidx])){
						++sidx;		++pidx;
					}else if(currSIdx >= 0 && currSIdx < slen){
						sidx = ++currSIdx;
						pidx = currPIdx;
					}else{
						return false;
					}
				}
			}

			//currSIdx is used-up
			if(sidx == slen && pidx == plen)	return true;
			if(sidx == slen){
				while(pidx < plen && p[pidx] == '*')
					++pidx;
				return pidx == plen;
			}
			if(pidx == plen)	return false;
		}*/
	
		bool isMatch_dp(string s, string p){
			int m = s.size();
			int n = p.size();

			int numStar=0;
			for(int i=0;i<n;++i)
				if(p[i] == '*')
					++numStar;
			if(n - numStar > m)	return false;

			vector<vector<bool> > dp(2,vector<bool>(n+1,false));

			dp[0][0] = true;
			for(int i=1;i<=n && dp[0][i-1];++i){
				if(p[i-1] == '*')
					dp[0][i] = true;
			}


			for(int i=1;i<=m;++i){
				dp[i%2][0] = false;
				for(int j=1;j<=n;++j){
					if(p[j-1] != '*'){
						if(isSame(s[i-1], p[j-1]) && dp[(i-1)%2][j-1])
							dp[i%2][j] = true;
						else
							dp[i%2][j] = false;
					}else{
						if(dp[(i-1)%2][j] || dp[i%2][j-1])
							dp[i%2][j] = true;
						else
							dp[i%2][j] = false;
					}
				}
			}
			return dp[m%2][n];
		}
};

int main(){
	Solution s;
	cout<<s.isMatch_dp("aa","a")<<endl;  
	cout<<s.isMatch_dp("aa","aa")<<endl;
	cout<<s.isMatch_dp("aaa","aa")<<endl;
	cout<<s.isMatch_dp("aa", "*")<<endl; 
	cout<<s.isMatch_dp("aa", "a*")<<endl;
	cout<<s.isMatch_dp("ab", "?*")<<endl;
	cout<<s.isMatch_dp("aab", "c*a*b")<<endl;
	cout<<s.isMatch_dp("b", "?*?")<<endl;

	cout<<endl;
	cout<<s.isMatch_dp("a","*a");
	cout<<s.isMatch_dp("abc","abc*");
	cout<<s.isMatch_dp("abc","a*bc");
	cout<<s.isMatch_dp("abc","a*b*c");
	cout<<s.isMatch_dp("aaa","*aaaa*");
	cout<<endl<<endl;
	cout<<s.isMatch_dp("abcdefde","abc*def");
}
