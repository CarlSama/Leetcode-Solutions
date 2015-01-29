#include<iostream>
#include<stack>

using namespace std;

/*
 * pop 操作之前检查empty
 * string的不存在使用string::nops标示
 *
 */
bool isValid(string s){
	string left = "([{";
	string right = ")]}";
	stack<char> st;

	auto iter = right.begin();
	for(auto c : s){{
		if(left.find(c) != string::npos){
			st.push(c);
		}else if((iter = right.find(c) != right.end())){
			if(st.empty() || st.top() != left[iter])	
				return false;
			else
				st.pop();
		}
	}

	return st.empty();
}

