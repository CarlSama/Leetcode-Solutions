#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
	public:
		int getFactorial(int n){
			int res = 1;
			for(int i=1;i<=n;++i)	res *= i;
			return res;
		}
		int getNum(int idx,int n,vector<bool> &isUsed){
			for(int i=0;i<n;++i){
				if(!isUsed[i]) --idx;
				if(idx == 0){
					isUsed[i] = true;
					return i+1;
				}
			}
		}

		string getPermutation(int n, int k) {
		   vector<bool> isUsed(n,false);
		   string res;

		   for(int i=0;i<n-1;++i){
			   int fact = getFactorial(n-i-1);
			   int idx = (k-1)/fact;
			   res += getNum(idx+1,n,isUsed) + '0';
			   k = k - idx * fact;
		   }
		   cout<<endl;
		   res += getNum(1,n,isUsed) + '0';
		   return res;
		}
};
int main(){
	Solution s;
	for(int i=1;i<7;++i)
		cout<<s.getPermutation(3, i)<<endl;;
}
