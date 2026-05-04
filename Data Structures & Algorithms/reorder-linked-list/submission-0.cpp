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
    void reorderList(ListNode* head) {
        ListNode* traverse = head;

        vector<ListNode*> nodeTracker;
        while (traverse != nullptr) {
            nodeTracker.push_back(traverse);
            traverse = traverse->next;
        } 

        int left = 0;
        int right = nodeTracker.size() - 1;

        vector<ListNode*> newList;
        while (left <= right) {
            if (left == right) newList.push_back(nodeTracker[left]);
            else {
                newList.push_back(nodeTracker[left]);
                newList.push_back(nodeTracker[right]);
            }
            left++;
            right--;
        }
        newList.push_back(nullptr);

        traverse = newList[0];
        for (int i = 1; i < newList.size(); i++) {
            traverse->next = newList[i];
            traverse = traverse->next;
        }
    }
};
