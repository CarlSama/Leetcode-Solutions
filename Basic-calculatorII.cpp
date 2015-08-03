#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
	public:
		int calculate(string s) {
			if(s.size() == 0)	return 0;
			stack<int> num;
			stack<char> oper;

			s += '+';
			s += '0';//添加这个尾部处理，避免对xxx + a / b的特殊处理

			int tepNum = 0;
			for(int i=0;i<s.size();++i) {
				if(s[i] == ' ')
					continue;
				if(s[i]<='9' && s[i]>='0') {
					tepNum *= 10;
					tepNum += (s[i] - '0');
				}else{
					if(!oper.empty() && (oper.top()=='*'|| oper.top()=='/')) {
						//需要在计算好第二个值之后才能获取* /的结果
						int first = num.top();
						num.pop();

						if(oper.top()=='*')
							first *= tepNum;
						else
							first /= tepNum;
						oper.pop();

						num.push(first);
					}else{
						oper.push(s[i]);
						num.push(tepNum);
					}
					tepNum = 0;
				}
			}
			num.push(0);

			while( !oper.empty()) {
				int second = num.top();
				num.pop();
				int first = num.top();
				num.pop();

				char op = oper.top();
				oper.pop();

				if(op=='+') 
					first += second;
				else 
					first -= second;
				
				num.push(first);
			}

			return num.top();
		}
};

int main(){
	string s("3+5/2");
	Solution so;
	cout<<so.calculate(s)<<endl;
}
