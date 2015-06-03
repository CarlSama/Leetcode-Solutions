#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

class Solution {
	public:
		int divide(int dividend, int divisor) {
			if(divisor == 0)	return INT_MAX;
			if(dividend == 0)	return 0;

			int flag = (dividend>0&&divisor<0 || dividend<0&&divisor>0)?-1:1;
			long long ldividend = abs((long long)dividend);//注意啊！无法使用int来接受
			long long ldivisor = abs((long long)divisor);
			if(ldividend < ldivisor)	return 0;
			if(ldividend == ldivisor)	return flag;

			long long result = 0;
			for(int i=31;i>=0;--i){
				if((ldivisor<<i) <= ldividend){
					result += ((long long)1)<<i;
					//需要使用(long long)1，
					//否则1<<i得到int后转换为long long 
					ldividend -= (ldivisor<<i);
				}
			}
			if(flag == -1){
				if(result >= -1 * (long long)(INT_MIN))
					return INT_MIN;
				else
					return flag * result;
			}else{
				if(result >= (long long)INT_MAX)
					return INT_MAX;
				else
					return flag *result;
			}
		}
		int divide1(int dividend, int divisor) {
			if(divisor == 0)	return INT_MAX;
			if(dividend == 0)	return 0;

			int flag = (dividend>0&&divisor<0 || dividend<0&&divisor>0)?-1:1;
			long long ldividend = abs((long long)dividend);//注意啊！无法使用int来接受
			long long ldivisor = abs((long long)divisor);
			if(ldividend < ldivisor)	return 0;
			if(ldividend == ldivisor)	return flag;

			long long result = 0;
			//在处理INT_MIN／１时会造成result（ｉｎｔ)溢出
			while(ldividend >= ldivisor){
				long long tmpRes = 1;
				long long moreDivisor = ldivisor;
				//这里需要使用long long,不然可能造成溢出后进入死循环!
				while((moreDivisor << 1) <= ldividend){
					moreDivisor <<= 1;	tmpRes <<= 1;
				}
				result += tmpRes;
				ldividend -= moreDivisor;
			}
			if(flag == -1){
				if(result >= -1 * (long long)(INT_MIN))
					return INT_MIN;
				else
					return flag * result;
			}else{
				if(result >= (long long)INT_MAX)
					return INT_MAX;
				else
					return flag *result;
			}
		}
};
int main(){
	Solution s;
	cout<<s.divide(5,2)<<endl;
	cout<<s.divide(-2147483648,-1)<<endl;
	cout<<s.divide(9,-2)<<endl;
	cout<<s.divide(2147483647,2)<<endl;
	cout<<s.divide(-1010369383,-2147483648)<<endl;

}
