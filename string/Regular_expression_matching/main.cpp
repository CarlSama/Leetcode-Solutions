#include<iostream>

using namespace std;

/*
 * Recurssion
 * isMatch(s,p) means the match of s to end && p to end
 */
bool valid(const char c,const char s){
	return (c==s)||(s=='.');
}
bool isMatch(const char*s,const char*p){
	if(*s == '\0'){
		while(*p == '*')
			p++;
		return *p == '\0';
	}
	if(*p == '\0')
		return *s == '\0';

	if(valid(*s,*p)){
		return isMatch(s+1,p+1);
	}else if(*p == '*'){
		return (isMatch(s,p+1) || (valid(*s,*(p-1)) && isMatch(s+1,p)));
	}else 
		return false;
}
			
int main(){


	cout<<(isMatch("aa","a")==false)<<endl;
	cout<<isMatch("aa","aa")==  true<<endl;
	cout<<isMatch("aaa","aa")==  false<<endl;
	cout<<isMatch("aa", "a*")==  true<<endl;
	cout<<isMatch("aa", ".*")==  true<<endl;
	cout<<isMatch("ab", ".*")==  true<<endl;
	cout<<isMatch("aab", "c*a*b")==  true<<endl;

	return 0;
}
