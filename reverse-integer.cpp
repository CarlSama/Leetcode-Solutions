#include<iostream>
#include<climits>
using namespace std;

/*
 * INT_MIN -> 转正溢出
 * 转正溢出
 */
class Solution {
	public:
		int reverse(int x) {
			long res = 0;
			bool isNeg = x < 0 ? true : false;
			long xl = x < 0 ? (-1)*(long)x : x;
			while(xl) {
				int digit = xl % 10;
				res *= 10;
				res += digit;
				xl /= 10;
			}

			if(isNeg)
				res *= -1;

			if(res < INT_MIN)	return 0;
			if(res > INT_MAX)	return 0;
			return res;
		}
};

int main() {
	Solution s;
	cout<<s.reverse(123)<<endl;
	cout<<s.reverse(-123)<<endl;
	cout<<s.reverse(0)<<endl;
	cout<<s.reverse(1000)<<endl;
	//overflow
	cout<<s.reverse(INT_MIN)<<endl;
	cout<<s.reverse(INT_MAX)<<endl;
	cout<<s.reverse(-2047489999)<<endl;
	cout<<s.reverse(1534236469)<<endl;
}
