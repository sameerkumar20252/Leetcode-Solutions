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
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*> Q;
        Q.push(node);
        unordered_map<int, Node*> m;

        while(Q.size() > 0) {
            Node* u = Q.front();
            Q.pop();
            
            Node* newNode = nullptr;
            if(m.count(u->val)) {
                if(m[u->val]->neighbors.size() > 0) continue;
                newNode = m[u->val];
            } else {
                newNode = new Node(u->val);
                m[u->val] = newNode;
            }


            for(Node* v : u->neighbors) {
                if(m.count(v->val)) {
                    newNode->neighbors.push_back(m[v->val]);
                } else {
                    Node* newNeigh = new Node(v->val);
                    m[v->val] = newNeigh;
                    newNode->neighbors.push_back(newNeigh);
                }
                Q.push(v);
            }

        }

        return m[1];
    }
};