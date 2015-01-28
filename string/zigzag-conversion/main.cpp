#include<iostream>

using  namespace std;

string  convert(string s,int nRows){
	if(nRows < 2)
		return s;

	string res;

	int len = s.size();
	int incr = 2*(nRows-1);
	for(int i=0;i<nRows;i++){
		int j=0;

		if(i==0 || i == nRows-1){
			while(i + j*incr < len){
				res += s[i + j*incr];
				j++;
			}
		}else{
			while(i + j*incr < len){
				res += s[i + j*incr];
				if(2*(j*incr+nRows-1) - (i+j*incr) < len){
					res += s[2*(j*incr+nRows-1) - (i+j*incr)];
				}
				j++;
			}
		}
	}

	return res;
}

int main(){
	cout<<(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")<<endl;
	return 0;
}
