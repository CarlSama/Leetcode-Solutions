#include<iostream>
#include<climits>

using namespace std;

/*
 * Careful
 * 1)leading and following blank
 * 2)+/-
 * 3)leading 0
 * 4)bigger than max_int or smaller than min_in
 */

int atoi(const char *str) {
	double res = 0.0;
	bool negative = false;

	// jumpBlank
	while(*str == ' ')
		str++;

	// leading modifier
	if(*str == '-'){
		negative = true;
		str++;
	}else if(*str == '+'){
		negative = false;
		str++;
	}

	while(*str>='0' && *str<='9'){
		if(*str == '0' && res < 1){
			str++;//leading 0
		}else{
			res *= 10;
			res += (*str-'0');
			str++;
		}
	}

	if(negative)
		res *= -1;

	if(res > INT_MAX)
		return INT_MAX;
	if(res < INT_MIN)
		return INT_MIN;

	return (int)(res);
}

int main(){
	cout<<atoi("    -1  ")<<endl;
	cout<<atoi("    9999999999999999  ")<<endl;
	cout<<atoi("    -9999999999999999  ")<<endl;

	return 0;
}
