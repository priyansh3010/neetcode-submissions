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
    ListNode* reverseList(ListNode* head) {
        ListNode* traverse = head;
        ListNode* prev = nullptr;
        while (traverse != nullptr) {
            ListNode* temp = traverse->next;
            traverse->next = prev;
            prev = traverse;
            traverse = temp;
        } 

        return prev;
    }
};
