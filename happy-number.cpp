#include<iostream>
#include<unordered_set>

using  namespace std;

/*
 * 需要long来存储平方和? No need
 * 本问题的重点是在不是happy　number时查重的办法
 *
 * Oh fucking genius !
 * Use the though used int linked list cycle dectition !
 *
 * 在检测是否存在loop时可以借鉴链表中floyd cycle detection !
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
		bool isHappy_hashset(int n) {
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
		bool isHappy(int n) {
			int slow = n,fast = n;
			while(slow != fast) {
				slow = getSquareSum(n);
				fast = getSquareSum(n);
				fast = getSquareSum(n);

				if(slow == fast)
					return false;
			}
			return slow == 1;
		}
};

int main(){
	Solution s;
	cout<<s.isHappy(19)<<endl;
}
