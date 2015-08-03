#include<iostream>
#include<string>
#include<climits>

using namespace std;

/*
 * 开头的空格
 * - / +　号
 */
class Solution {
	public:
		int myAtoi(string str) {
			int idx=0;
			while(str[idx] == ' ') {
				++idx;
			}
			bool isNeg = false;
			if(str[idx] == '-') {
				isNeg = true;
				++idx;
			}else if(str[idx] == '+') { 
				++idx;
			}

			long result = 0;
			long boundry = (long)(-1) * INT_MIN; 
			while(str[idx] <= '9' && str[idx] >='0') {
				result *= 10;
				result += (str[idx] - '0');
				++idx;
				if(result > boundry) {
					break;
				}
			}
			if(isNeg)
				result *= (-1);
			if(result >= INT_MAX)
				return INT_MAX;
			if(result <= INT_MIN)
				return INT_MIN;
			return result;
		}
};

int main() {
	Solution s;
	cout<<s.myAtoi("   -+9999  ")<<endl;
	cout<<s.myAtoi("   -9999  9")<<endl;
	cout<<s.myAtoi("   9999.2  9")<<endl;
	cout<<s.myAtoi("-2147483649")<<endl;
	cout<<INT_MAX<<endl;
}
