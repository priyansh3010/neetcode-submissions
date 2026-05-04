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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* newHead = nullptr;
        if (list1->val <= list2->val) {
            newHead = list1;
            list1 = list1->next;
        }
        else {
            newHead = list2;
            list2 = list2->next;
        }

        ListNode* traverse1 = list1;
        ListNode* traverse2 = list2;
        ListNode* newTraverse = newHead;
        while (traverse1 != nullptr && traverse2 != nullptr) {
            if (traverse1->val < traverse2->val) {
                newTraverse->next = traverse1;
                newTraverse = newTraverse->next;
                traverse1 = traverse1->next; 
            }
            else { 
                newTraverse->next = traverse2;
                newTraverse = newTraverse->next;
                traverse2 = traverse2->next; 
            }
        }

        while (traverse1 != nullptr) {
            newTraverse->next = traverse1;
            newTraverse = newTraverse->next;
            traverse1 = traverse1->next;
        }

        while (traverse2 != nullptr) {
            newTraverse->next = traverse2;
            newTraverse = newTraverse->next;
            traverse2 = traverse2->next;
        }

        return newHead;
    }
};
