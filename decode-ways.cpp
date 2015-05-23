#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
	int len;
	public:
		int numDecodings(string s) {
			len = s.size();
			if(len == 0)	return 0;
			vector<int> dp(len,0);

			int begin = len - 1;
			if(s[begin] == '0'){
				while(begin >= 0 && s[begin] == '0'){
					if(begin-1<0||(s[begin-1]!='1'&&s[begin-1]!='2'))
						return 0;
					begin -= 2;
				}
				if(begin >= 0){
					dp[begin] = dp[begin+1] = 1;
				}else{
					return 1;
				}
			}else{
				dp[begin] = 1; 
			}

			for(int i=begin-1;i>=0;--i){
				if(s[i] == '0'){
					int back = i+1;
					while(i>= 0 && s[i] == '0'){
						if(i-1<0||(s[i-1]!='1'&&s[i-1]!='2'))
							return 0;
						i -= 2;
					}
					if(i>= 0){
						dp[i] = dp[i+1] = dp[back];
					}else{
						return dp[back];
					}
				}else if(s[i] > '2'){
					dp[i] = dp[i+1];
				}else if(s[i] == '2'){
					if(s[i+1] <= '6'){
						if(i+2<=begin)
							dp[i] = dp[i+1] + dp[i+2];
						else
							dp[i] = dp[i+1] + 1;
					}else{
						dp[i] = dp[i+1];
					}
				}else{
					if(i+2<=begin){
						dp[i] = dp[i+1] + dp[i+2];
					}else{
						dp[i] = dp[i+1] + 1;
					}
				}
			}
			return dp[0];
		}
};
int main(){
	Solution s;
	cout<<s.numDecodings("")<<endl;
	cout<<s.numDecodings("1")<<endl;
	cout<<s.numDecodings("19")<<endl;
	cout<<s.numDecodings("26")<<endl;
	cout<<s.numDecodings("27")<<endl;
	cout<<s.numDecodings("127")<<endl;
	cout<<s.numDecodings("12926")<<endl;
	cout<<s.numDecodings("012926")<<endl;
	cout<<s.numDecodings("101")<<endl;
	cout<<s.numDecodings("101")<<endl;
	cout<<s.numDecodings("12109")<<endl;
	cout<<s.numDecodings("1010")<<endl;
	cout<<s.numDecodings("221010")<<endl;
	cout<<s.numDecodings("010101")<<endl;
	cout<<s.numDecodings("3101")<<endl;
	cout<<s.numDecodings("0")<<endl;
}
