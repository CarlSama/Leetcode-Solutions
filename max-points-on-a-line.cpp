#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

/*
 * It's unable to use double-hashmap
 * So we have to think about two-level hash
 */
class Solution {
	public:
		int GCD(int a,int b) {
			if(b==0)	return a;
			return GCD(b, a%b);
		}
		int maxPoints(vector<Point>& points) {
			unordered_map<int,unordered_map<int,int> > map;

			int maxPoints = 0;
			for(int i=0 ; i<points.size() ; ++i) {
				map.clear();

				int overlapped = 0,localMaxPoints = 0;
				for(int j=i+1 ; j<points.size() ; ++j) {
					int detaX = points[i].y - points[j].y;
					int detaY = points[i].x - points[j].x;

					if(detaX == 0 &&  detaY == 0) {
						++overlapped;
					}else{
						//此时，gcd不可能为０
						int gcd = GCD(detaX, detaY);
						detaX /= gcd;
						detaY /= gcd;

						int currPoints = ++map[detaX][detaY];
						localMaxPoints= max(localMaxPoints, currPoints);
					}
				}
				maxPoints = max(maxPoints, localMaxPoints + overlapped + 1);
			}
			return maxPoints;
		}
};

int main(){
	vector<Point> v;
	v.push_back(Point(1,2));
	v.push_back(Point(2,4));
	v.push_back(Point(1,2));
	Solution s;
	cout<<s.maxPoints(v)<<endl;
}
