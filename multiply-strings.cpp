#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		void add(string& num1,string& num2) {
			int incr = 0;
			for(int i=num1.size()-1 ; i>=0 ; --i) {
				int sum = (num1[i]-'0') + (num2[i]-'0') + incr;
				incr = sum / 10;
				num1[i] = sum % 10 + '0';
			}
		}

		string multiply(string num1, string num2) {
			if(num1.size() == 0)	return num2;
			if(num2.size() == 0)	return num1;
			if(num1[0]=='0' || num2[0]=='0')	return string(1,'0');

			string res(num1.size() + num2.size(), '0');

			for(int i=num1.size()-1 ; i>=0 ; --i) {

				string tmp(num1.size() + num2.size(), '0');
				int incr = 0, k = num2.size() + i;

				for(int j=num2.size()-1; j>=0; --j) {
					int sum = (num1[i] - '0') * (num2[j] - '0') + incr;
					incr = sum / 10;
					tmp[k--] = sum % 10 + '0';
				}
				if(incr)
					tmp[k] = incr + '0';

				add(res,tmp);
			}

			int front = 0;
			for( ; front<res.size() ; ++front)
				if(res[front]!= '0')
					break;

			return res.substr(front,res.size()-front);
		}
};

int main() {
	Solution s;
	cout<<s.multiply("11","22")<<endl<<endl;
	cout<<s.multiply("99","99")<<endl<<endl;
	cout<<s.multiply("1","99")<<endl<<endl;
	cout<<s.multiply("0","99")<<endl<<endl;
}
