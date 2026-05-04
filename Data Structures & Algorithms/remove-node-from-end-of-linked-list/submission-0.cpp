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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* traverse = head;
        
        int len = 0;
        while (traverse != nullptr) {
            traverse = traverse->next;
            len++;
        }

        if (n == 1 && head->next == nullptr) return nullptr;

        n = len - n;
        while (n > 0) {
            n--;
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr) return curr->next;
        
        prev->next = curr->next;
        return head;
    }
};
