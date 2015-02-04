#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * Be carefule :
 * 1) 0
 * 2) 00
 */

class Solution {
	public:

	static int getLen(int x){
		int len=0;
		while(x){
			len++;
			x = x/10;
		}
		return len;
	}

	static bool isSmaller(int a, int b){
		//我们可以制造两个vector1=a+b vector2 = b+2
		//然后比较...
		if(a==0 && b==0){
			return true;
		}else if(a == 0){
			return true;
		}else if(b == 0){
			return false;
		}else{
			int lenA = getLen(a);
			int lenB = getLen(b);

			long ab = a * pow(10,lenB) + b;
			long ba = b * pow(10,lenA) + a;

			return ab < ba;
		}
	}

	string intToString(int i){
		if(i<=9)
			return string(1, (char)(i+'0'));
		else
			return intToString(i/10) + (char)(i%10+'0');
	}

	string largestNumber(vector<int> &num){
		string res;
		make_heap(num.begin(),num.end(),isSmaller);
		while( !num.empty()){
	/*		for(auto n : num)
				cout<<n<<" ";
			cout<<endl;*/
			res += intToString(num.front());
			pop_heap(num.begin(),num.end(),isSmaller);
			num.pop_back();
		}
		
		if(res[0] == '0')
			return string("0");
		else
			return res;
	}
};

int main(){
	vector<int> num;
/*	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(6);
	num.push_back(8);
	num.push_back(9);*/
	num.push_back(938);
	num.push_back(1399);
	num.push_back(5607);
	num.push_back(824);
	num.push_back(6973);
	num.push_back(5703);
	num.push_back(9609);
	num.push_back(4398);
	num.push_back(8247);
	Solution s;

	cout<<s.isSmaller(52,531)<<endl;
	cout<<s.isSmaller(53,531)<<endl;
	cout<<s.isSmaller(53,52)<<endl;
	cout<<(s.largestNumber(num) == "9609938824824769735703560743981399")<<endl;

	vector<int> num2;
	num2.push_back(121);
	num2.push_back(12);
	cout<<(s.largestNumber(num2))<<endl;

	vector<int> num3;
	num3.push_back(212);
	num3.push_back(21);
	cout<<s.largestNumber(num3)<<endl;

	return 0;
}

