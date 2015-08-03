#include<iostream>
#include<string>

using namespace std;

/*
 * 询问面试官，空串是不是有效的呢？
 */
class Solution {
	public:
		bool isAlpahNumeric(char c) {
			if(c >= '0' && c <= '9')
				return true;
			if(c >= 'a' && c <= 'z')
				return true;
			if(c >= 'A' && c <= 'Z')
				return true;
			return false;
		}
		char toLower(char c) {
			if(c >= 'A' && c <= 'Z')
				c = 'a' + c - 'A';
			return c;
		}
		bool isSame(char c1, char c2) {
			if(c1 >= '0' && c1 <= '9')
				return c1 == c2;
			return toLower(c1) == toLower(c2);
		}
		bool isPalindrome(string s) {
			int front = 0, back = s.size() - 1;
			while(front < back) {
				while( front <= back &&  !isAlpahNumeric(s[front]) ) // 注意边界检查
					++front;
				while( back >=  front  && !isAlpahNumeric(s[back]) )
					--back;

				if(front > back)
					return true;
				if(!isSame(s[front], s[back]))
					return false;
				++front;
				--back;
			}
			return true;
		}
};

int main() {
	Solution s;
	cout<<s.isPalindrome("!!")<<endl;
	cout<<s.isPalindrome("race a car")<<endl;
	cout<<s.isPalindrome("A man, a plan, a canal: Panama")<<endl;
}
