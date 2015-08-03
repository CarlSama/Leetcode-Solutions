#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


class Solution {
	public:
		int countPrimes(int n) {
			vector<bool> isPrime(n+1,true);

			int end = sqrt(n);
			for(int i=2;i<=end;++i) {
				if(isPrime[i]) {
					for(int j = i * i ; j< n; j += i) 
						isPrime[j] = false;
				}
			}

			int count = 0;
			for(int i=2;i<n;++i) {
				if(isPrime[i])
					++count;
			}

			return count;
		}
};

int main(){
	Solution s;
	cout<<s.countPrimes(40)<<endl;
}
