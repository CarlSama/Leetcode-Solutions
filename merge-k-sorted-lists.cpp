#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
	vector<int> minHeap;
public:
	static bool cmp(ListNode* left,ListNode* right) {
		return left->val < right->val;
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		for(auto l : lists) {
			if(l) {
				pq.push(l);
			}
		}

		if(pq.empty())
			return 0;

		ListNode* result = pq.top();
		pq.pop();
		if(result->next) {
			pq.push(result->next);
		}

		ListNode* tail = result;
		while(!pq.empty()) {
			tail->next = pq.top();
			pq.pop();
			tail = tail->next;

			if(tail->next) 
				pq.push(tail->next);
		}
		
		return result;
	}
};

int main() {
}
