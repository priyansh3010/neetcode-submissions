/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* traverse = head;
        unordered_map<Node*, Node*> hashMap;
        Node* newHead = new Node(traverse->val);
        hashMap[traverse] = newHead;
        Node* prev = newHead;
        traverse = traverse->next;

        while (traverse != nullptr) {
            Node* newNode = new Node(traverse->val);
            prev->next = newNode;
            prev = newNode;
            hashMap[traverse] = newNode;
            traverse = traverse->next;
        }

        traverse = head;
        Node* newList = newHead;
        while (traverse != nullptr) {
            newList->random = hashMap[traverse->random];
            newList = newList->next;
            traverse = traverse->next;
        }

        return newHead;
    }
};
