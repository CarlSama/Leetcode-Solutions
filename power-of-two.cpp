#include<iostream>
using namespace std;

class Solution {
	public:
		bool isPowerOfTwo(int n) {
			while(n) {
				if(n < 2)
					return (n == 1);

				if(n % 2) {
					return false;
				}else{
					n = n / 2;
				}
			}
			return false;
		}
};

int main() {
	Solution s;
	cout<<s.isPowerOfTwo(0)<<endl;
	cout<<s.isPowerOfTwo(1)<<endl;
	cout<<s.isPowerOfTwo(2)<<endl;
	cout<<s.isPowerOfTwo(3)<<endl;
	cout<<s.isPowerOfTwo(4)<<endl;
}
