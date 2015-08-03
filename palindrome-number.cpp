#include<iostream>
#include<climits>

using namespace std;

/*
 * 要询问对正负数的定义
 * 
 * Oh no. 负数不算回文范文
 */
class Solution {
	public:
		bool isPalindrome(int x) {
			if(x < 0)	return false;
			
			long reverse = 0;
			long orig = x;
			while(orig) {
				reverse *= 10;
				reverse += (orig % 10);
				
				orig /= 10;
			}
			orig = x;
			return orig == reverse;
		}
};

int main() {
	Solution s;
	cout<<s.isPalindrome(1321)<<endl;
	cout<<s.isPalindrome(12321)<<endl;
	cout<<s.isPalindrome(-12321)<<endl;
	cout<<INT_MAX<<endl;
	cout<<INT_MIN<<endl;
}
