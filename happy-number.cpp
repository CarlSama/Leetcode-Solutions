#include<iostream>
#include<unordered_set>

using  namespace std;

/*
 * 需要long来存储平方和? No need
 * 本问题的重点是在不是happy　number时查重的办法
 */
class Solution {
	public:
		int getSquareSum(int n) {
			int squareSum = 0;
			while(n) {
				squareSum += ((n%10) * (n%10));
				n /= 10;
			}
			return squareSum;
		}
		bool isHappy(int n) {
			unordered_set<int> squareSumSeen;

			int squareSum = getSquareSum(n);
			while(squareSum != 1) {
				if(squareSumSeen.find(squareSum) != squareSumSeen.end())
					return false;
				squareSumSeen.insert(squareSum);
				squareSum = getSquareSum(squareSum);
			}
			return true;
		}
};

int main(){
	Solution s;
	cout<<s.isHappy(19)<<endl;
}
