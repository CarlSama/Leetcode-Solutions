#include<iostream>
#include<vector>
using namespace std;

	
 struct Interval {
    int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		bool isOverlapped(Interval l1,Interval l2) {
			return !(l1.start > l2.end || l2.start > l1.end);
		}

		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> res;

			bool isUsed = false;
			bool hasOverlapped = false;
			for(int i=0;i<intervals.size();++i) {
				if(!isOverlapped(intervals[i],newInterval)) {
					if(intervals[i].start > newInterval.end && !isUsed) {
						res.push_back(newInterval);
						isUsed = true;
					}
					res.push_back(intervals[i]);
				}else{
					newInterval.start = min(newInterval.start, intervals[i].start);
					newInterval.end = max(newInterval.end, intervals[i].end);
				}
			}

			if(!isUsed)
				res.push_back(newInterval);

			return res;
		}
};

int main() {
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(5,6));
	Solution s;
	vector<Interval> res = s.insert(intervals, Interval(7,7));
	for(int i=0;i<res.size();++i) {
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}
