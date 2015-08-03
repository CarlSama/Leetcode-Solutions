#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

/*
 *　看到int时，时刻考虑INT_MIN 取正(abs, /-1)时溢出的问题
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
	    string result;
		if( (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
			result += '-';

		//不能直接用abs，小心INT_MIN
		long numeratorL = numerator > 0 ? numerator : (-1) * (long)numerator;
		long denominatorL = denominator > 0 ? denominator : (-1) * (long)denominator;

		int idx = 0;
	    long integer = numeratorL / denominatorL;
	    result += (integer > 0) ? to_string(integer) : "0";
	    numeratorL -= integer*denominatorL; 

		if(numeratorL) {
		    result += '.';

			//某个numeratorL出现时前段开始的位置
			unordered_map<int,int> isSeen;

			while(numeratorL) {
				if(isSeen.find(numeratorL) == isSeen.end()) {
						//当前这个numeratorL开始的位置是result.size()
						isSeen.insert(pair<int,int>(numeratorL,result.size()));

						numeratorL *= 10;
						integer = numeratorL / denominatorL;

						result += to_string(integer);

						numeratorL -= integer*denominatorL;
				}else{
						//在 重复串开头前加上'('号
						result.insert(isSeen[numeratorL],"(");
						result += ")";
						break;
				}
			}
		}

		return result;
    }
};

int main() {
	Solution s;
	cout<<s.fractionToDecimal(-2147483648, -1)<<endl;
	cout<<s.fractionToDecimal(-50, 8)<<endl;
}
