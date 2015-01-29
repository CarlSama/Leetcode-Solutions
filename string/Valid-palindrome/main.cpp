#include<iostream>

using namespace std;
/*
 * Iteration
 * Using two pointer
 */
bool isValid(char &c){
	if((c>='a'&&c<='z') || (c>='0'&&c<='9')){
		return true;
	}else if(c>='A'&&c<='Z'){
		c -= ('A' - 'a');
		return true;
	}else
		return false;
}

bool isPalindrome(string s){
	int len = s.size();

	int front = 0,back = len-1;
	while(front <= back){
		while(!isValid(s[front]) && front <= back)
			front++;
		while(!isValid(s[back]) && front <= back)
			back--;
		if(front <= back && s[front] != s[back]){
			return false;
		}else{
			front++;
			back--;
		}
	}

	return true;
}

/*
 * Recursion
 * 小心++与--的后效性!
 * 会MLE 
 */
bool checkValid(string s,int front,int back){
	if(front <= back){
		if(!isValid(s[front]))
			return checkValid(s,front+1,back);
		else if(!isValid(s[back]))
			return checkValid(s,front,back-1);
		else if(s[front] != s[back])
			return false;
		else
			return checkValid(s,front+1,back-1);
	}
	return true;
}
			
bool isPalindrome_recur(string s){
	return checkValid(s,0,s.size()-1);
}
int main(){
	cout<<isPalindrome_recur("A man, a plan, a canal: Panama")<<endl;
	cout<<isPalindrome_recur("race a car")<<endl;
	cout<<isPalindrome_recur(" ")<<endl;
	cout<<isPalindrome_recur("0k.;r0.k;")<<endl;

	return 0;
}
