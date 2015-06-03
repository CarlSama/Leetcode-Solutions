#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Solution {
	public:
		/*
		double myPow(double x, int n) {
			if(abs(x) < 1e-9)	return 0;
			if(n == 0)	return 1;

			bool isRo = false;
			long long newN = n;
			if(n < 0){//注意n为负数的情况
				//Oh..no.. n==INT_MIN
				isRo = true;	
				newN = -1 * newN;
			}
			int len = sizeof(int) * 8;
			double res = 1;
			for(int i=len-1;i>=0;++i){
				if(newN & (1<<i)){
					res *= (x
					*/


		double myPow_bs(double x, int n) {
			if(abs(x) < 1e-9)	return 0;
			if(n == 0)	return 1;

			bool isRo = false;
			long long newN = n;
			if(n < 0){//注意n为负数的情况
				//Oh..no.. n==INT_MIN
				isRo = true;	
				newN = -1 * newN;
			}

			double res1 =x,res2 = 1;
			while(newN > 1){
				if(newN % 2 == 0){
					res1 *= res1;
					newN = newN/2;
				}else{
					res2 *= res1;
					newN -= 1;
				}
			}
			if(isRo)
				return (1/(res1*res2));
			else
				return res1*res2;
		}
};

int main(){
	Solution s;
//	cout<<(1.2<<1)<<endl;
//	Pity, 浮点没有移位操作
	cout<<s.myPow(-1,-2147483648)<<endl;
	cout<<s.myPow(8.88023,3)<<endl;
	cout<<s.myPow(2,1)<<endl;
	cout<<s.myPow(2,3)<<endl;
	cout<<s.myPow(2,2)<<endl;
}
