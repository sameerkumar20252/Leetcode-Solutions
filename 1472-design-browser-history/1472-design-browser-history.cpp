class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url) {
        this->url = url;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
public:
    Node* curr = nullptr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        if(curr->next) curr->next->prev = nullptr;
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev != nullptr && steps--) curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next != nullptr && steps--) curr = curr->next;
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */