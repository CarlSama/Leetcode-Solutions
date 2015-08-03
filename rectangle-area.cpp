#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int getArea(int lx,int ly,int rx,int ry) {
			return (rx - lx) * (ry - ly);
		}
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int leftArea = getArea(A,B,C,D);
			int rightArea = getArea(E,F,G,H);
			int overlap = 0;

			int lx = max(A,E);
			int ly = max(B,F);
			int rx = min(C,G);
			int ry = min(D,H);
			if(rx > lx && ry > ly) 
				overlap = getArea(lx,ly,rx,ry);

			return leftArea - overlap + rightArea;
		}
};
int main() {
	Solution s;
	cout<<s.computeArea(0, 0, 0, 0, -1, -1, 1, 1)<<endl;
}
