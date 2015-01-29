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
		while(*p && *(p+1) == '*')
			p += 2;
		return *p == '\0';
	}
	if(*p == '\0')
		return *s == '\0';

	if(*(p+1) == '*'){
		return (isMatch(s,p+2) || (valid(*s,*p) && isMatch(s+1,p)));
	}

	return valid(*s,*p) && isMatch(s+1,p+1);
}

/*
 * Let's Recursion with memo
 * We can find the isMatch(s,p+2) and isMatch(s+1,p) would leads to many overlapping sub-question
 * So, lets memo
 */
/*
 * When DP,think is different order with recurssion
 * if j isn't *
 *		[i][j] = [i-1][j-1] && valid(i-1,j-1);
 * else
 *		[i][j] = [i-1][j] or (valid(i-1,j-1) && [i][j-1])
 */
bool isMatch(const char*s,const char*p){
	vector<bool> va;
	int len = strlen(s);

	va[0] = true;

	while(*p){
		char ch = *p++;
		bool hasStar = (*p=='*');
		if(hasStar)
			p++;

		if(!hasStar){
			for(int j=len;j>0;j--){
				va[j] = va[j-1] && valid(ch,s[j-1]);
				va[0] = false;
			}else{
				for(int j=1;j<=len;j++){
					va[j] = va[j] || (va[j-1] && valid(ch,s[j-1]));
				}
			}
		}
	}
	return va[n];
}



			
int main(){
	cout<<(isMatch("aa","a")==false)<<endl;
	cout<<(isMatch("aa","aa")==  true)<<endl;
	cout<<(isMatch("aaa","aa")==  false)<<endl;
	cout<<(isMatch("aa", "a*")==  true)<<endl;
	cout<<(isMatch("aa", ".*")==  true)<<endl;
	cout<<(isMatch("ab", ".*")==  true)<<endl;
	cout<<(isMatch("aab", "c*a*b")==  true)<<endl;
	cout<<(isMatch("a", "ab*")==  true)<<endl;
	return 0;
}
