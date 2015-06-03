#include<iostream>
using namespace std;

class Solution {
	public:
		/*
		 * sorry... no....
		 * int mySqrt(int x) {
			int res = 0;
			int tmpX = x;
			for(int i=15;i>=0;--i){
				int tmp = 1 << i;
				if(tmp * tmp <= tmpX){
					cout<<i<<endl;
					res += (1 << i);
					tmpX /= (tmp * tmp);
				}
			}
			if(res * res == x)
				return res;
			return res-1;
		}*/

		int mySqrt1(int x) {
			long long newX = x;
			long long left=0,right=newX;
			long long multiply;
			while(left <= right){
				long long mid = left + (right - left)/2;
				multiply = mid * mid;
				if(multiply == newX)	return mid;
				if(multiply > newX)
					right = mid - 1;
				else 
					left = mid + 1;
			}
			if(left * left == x)
				return left;
			return left - 1;
		}
};
int main(){
	Solution s;
	cout<<s.mySqrt(8192)<<endl<<endl;;
}
