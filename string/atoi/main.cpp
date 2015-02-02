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

/*
 * Use double :)
 */
int atoi_double(const char *str) {
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


/*
 * Use careful method
 * Because neg int is "bigger" than int for 1, so we use neg int to store.
 * This can help us combine two situations.
 */
int atoi(const char* str){
	int res = 0;

	while(*str==' ')
		str++;

	bool isUnNeg = true;
	if(*str=='-'){
		isUnNeg = false;
		str++;
	}else if(*str=='+'){
		str++;
	}

	while(*str>='0' && *str<='9'){
		//we need to check over here.
		// 1).This is neg
		int lastBeforeMin = INT_MIN / 10;
		int lastFollowMin = INT_MIN % 10;
		if(!isUnNeg && (res < lastBeforeMin || (res == lastBeforeMin && '0' - *str <= lastFollowMin))){
			return INT_MIN;
		}

		// 2).This is positive
		int lastBeforeMax = (-1)*(INT_MAX / 10);
		int lastFollowMax = (-1)*(INT_MAX % 10);
		if(isUnNeg && (res < lastBeforeMax || (res == lastBeforeMax &&  '0' - *str <=  lastFollowMax))){
			return INT_MAX;
		}

		res *= 10;
		res += ('0' - *str);
		str++;
	}

	if(isUnNeg)
		return -1*res;
	else
		return res;
}

int main(){
	cout<<atoi("    -1  ")<<endl;
	cout<<atoi("    9999999999999999  ")<<endl;
	cout<<atoi("    -9999999999999999  ")<<endl;
	cout<<endl;
	cout<<atoi(" 2147483646")<<endl;
	cout<<atoi(" 2147483647")<<endl;
	cout<<atoi(" 2147483648")<<endl;
	cout<<endl;
	cout<<atoi(" -2147483647")<<endl;
	cout<<atoi(" -2147483648")<<endl;
	cout<<atoi(" -2147483649")<<endl;


	return 0;
}
