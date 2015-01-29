#include<iostream>

using  namespace std;
/*
 * 霸道的*号
 */

/*
 * Recurssion
 * Time complexity : O(m * n!) or O(m! * n!)
 * momo optimize ? hard
 */
/*
 * isMatch(s,p) means from s and p to end, is it match ?
 */
bool isMatch_recurr(const char* s,const char *p){
	if(*s=='\0'){
		while(*p == '*')
			p++;
		return *p=='\0';
	}

	if(*p=='\0')
		return *s=='\0';

	if(*p == *s || *p == '?')
		return isMatch_recurr(s+1,p+1);

	if(*p == '*'){		
		while(*p == '*') //  ASK !!!
			p++;;//p向前移动,跳过重复的*
		//while(*p++ == '*') //  ASK !!!
			//;//p向前移动,跳过重复的*
		if(*p == '\0')
			return true;
		else{
			while(*s && !isMatch_recurr(s,p))
				s++;//s向前移动,跳过不相等的项
			return *s!='\0';//如果*s=='\0', 代表走到最后都没有匹配
		}
	}
	return false;
}


/*
 * Iteration time O(n*m)
 * 标记先前的位置,为之后失败时的回溯提供条件
 * 注意: p串中每次在遇到*号时,都可以前移的原因时*的极大的匹配能力 :)
 */

bool isMatch(const char*s, const char* p){
	bool hasStar = false;
	char *sptr = s;
	char *pptr = p;
	for(;sptr!='\0';sptr++,pptr++){
		if(*pptr == '?' || *pptr==*sptr){
			;
		}else if(*pptr == '*'){
			hasStar = true;
			s = sptr;
			p = pptr;
			while(*p == '*')
				p++;
			if(*p == '\0')
				return true;
			pptr = p - 1;
			sptr = s - 1;
		}else{
			if(!hasStar)
				return false;
			s++;
			pptr = p-1;
			sptr = s-1;
		}
	}

	while(*pptr == '*')
		pptr++;
	return *pptr=='\0';
}

int main(){
	cout<<(isMatch("a", "*")== true)<<endl;
	cout<<(isMatch("aa", "a*")== true)<<endl;
	cout<<(isMatch("aa","a")== false)<<endl;
	cout<<(isMatch("aa","aa")==true)<<endl;
	cout<<(isMatch("aaa","aa")== false)<<endl;
	cout<<(isMatch("ab", "?*")== true)<<endl;
	cout<<(isMatch("aab", "c*a*b")== false)<<endl;
	cout<<(isMatch("ab", "*a")== false)<<endl;

	//ASK !
	char *c = "*";
	char *a = "b";
	cout<<*c<<"  "<<*a<<endl;
	cout<<(*(c + 1))<<"  "<<a<<endl;
	cout<<(*c++)<<endl;
	cout<<*c<<endl;
	return 0;
}
