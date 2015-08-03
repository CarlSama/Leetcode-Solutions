#include<iostream>
#include"print.h"
#include<vector>
using namespace std;

class Solution {
	int len;
	public:
		vector<int> plusOne(vector<int>& digits) {
			len = digits.size();
			for(int i=len-1;i>=0;--i){
				if(digits[i] == 9){
					digits[i] = 0;
				}else{
					++digits[i];
					return digits;
				}
			}
			digits[0] = 1;
			digits.push_back(0);//针对99...99的情况，10000
			return digits;
		}
};
int main(){
	int arr[3] = {9,9};
	vector<int> v(arr,arr+2);
	Solution s;
	vector<int> res = s.plusOne(v);
	Freeman::print(res);
}
