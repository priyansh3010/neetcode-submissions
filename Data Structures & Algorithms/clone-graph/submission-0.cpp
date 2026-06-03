/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> lookup;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* currNode = new Node(node->val);
        lookup[node] = currNode;
        
        for (auto neighbor : node->neighbors) {
            if (lookup.find(neighbor) != lookup.end())
                currNode->neighbors.push_back(lookup[neighbor]);
            else currNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return currNode;
    }
};