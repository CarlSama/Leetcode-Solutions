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

		bool isMatch(string s, string p){
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
		}
	
		/*int getFront(string& p){
			int idx = 0;
			while(idx < plen && p[idx] != '*')
				++idx;
			return idx;
		}
		int getBack(string& p){
			int idx = p.size()-1;
			while(idx >= 0 && p[idx] != '*')
				--idx;
			return idx;
		}
		bool isMatch(string s, string p){
			plen = p.size();	slen = s.size();

			if(slen == 0){
				int idx = 0;
				while(idx < plen && p[idx]=='*')
					++idx;
				return idx == plen;
			}

			if(plen == 0)	return slen == 0;
			int front = getFront(p);// front==0 indicate begin with '*'
			if(front == plen){
				int sidx=0,pidx=0;
				while(sidx<slen && pidx<plen && isSame(s[sidx],p[pidx])){
					++sidx;		++pidx;
				}
				return sidx==slen&&pidx==plen;
			}

			//at least one '*'
			int back = getBack(p);
			for(int i=0; i<front ;++i){// compare front
				if(i == slen) return false;
				if(	!isSame(s[i],p[i]))
					return false;
			}

			for(int j=0; j<plen-back; ++j){
				int sidx = slen - j;
				int pidx = plen - j;
				if(sidx < front) return false;
				if( !isSame(s[sidx],p[pidx]) )
					return false;
			}

			return true;
		}*/
};

int main(){
	Solution s;
	cout<<s.isMatch("aa","a")<<endl;  
	cout<<s.isMatch("aa","aa")<<endl;
	cout<<s.isMatch("aaa","aa")<<endl;
	cout<<s.isMatch("aa", "*")<<endl; 
	cout<<s.isMatch("aa", "a*")<<endl;
	cout<<s.isMatch("ab", "?*")<<endl;
	cout<<s.isMatch("aab", "c*a*b")<<endl;
	cout<<s.isMatch("b", "?*?")<<endl;

	cout<<endl;
	cout<<s.isMatch("abc","*abc");
	cout<<s.isMatch("abc","abc*");
	cout<<s.isMatch("abc","a*bc");
	cout<<s.isMatch("abc","a*b*c");
	cout<<s.isMatch("aaa","*aaaa*");

}
