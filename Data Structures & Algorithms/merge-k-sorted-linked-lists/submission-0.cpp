/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode();
        ListNode* traverse = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, CustomCompare> minHeap;

        for (auto list : lists) {
            if (list != nullptr) minHeap.push(list);
        }

        while (!minHeap.empty()) {
            ListNode* currNode = minHeap.top();
            minHeap.pop();
            if (currNode->next) minHeap.push(currNode->next);

            traverse->next = currNode;
            traverse = traverse->next;
        }

        return dummyHead->next;
    }

    struct CustomCompare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
};
