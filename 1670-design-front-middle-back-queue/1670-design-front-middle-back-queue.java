class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class FrontMiddleBackQueue {

    Node front, back, middle;
    int n = 0;

    public FrontMiddleBackQueue() {
        front = null;
        back = null;
        middle = null;
    }
    
    public void pushFront(int val) {
        Node curr = new Node(val);

        if(front == null) {
            front = middle = back = curr;
        } else {
            curr.next = front;
            front.prev = curr;
            front = curr;
        }

        if(n % 2 != 0) {
            middle = middle.prev;
        }
        n++;
    }
    
    public void pushMiddle(int val) {
        Node curr = new Node(val);
        if(middle == null) {
            front = middle = back = curr;
        } else {
            if(n % 2 == 0) {
                curr.next = middle.next;
                curr.prev = middle;
                middle.next.prev = curr;
                middle.next = curr;
            } else {
                curr.prev = middle.prev;
                curr.next = middle;
                if(middle.prev != null) {
                    middle.prev.next = curr;
                }
                if(n == 1) {
                    front = curr;
                }
                middle.prev = curr;
            }
            middle = curr;
        }
        n++;
    }
    
    public void pushBack(int val) {
        Node curr = new Node(val);
        if(back == null) {
            front = middle = back = curr;
        } else {
            back.next = curr;
            curr.prev = back;
            back = curr;
        }

        if(n > 0 && n % 2 == 0) {
            middle = middle.next;
        }
        n++;
    }
    
    public int popFront() {
        if(n == 0) {
            return -1;
        }
        int val = front.data;
        Node temp = front;
        front = front.next;

        if(front == null) {
            middle = back = null;
        } else {
            front.prev = null;
            if(n % 2 == 0) {
                middle = middle.next;
            }
        }
        temp.next = null;
        temp = null;
        n--;
        return val;
    }
    
    public int popMiddle() {
        if(n == 0) {
            return -1;
        }

        int val = middle.data;
        Node last = middle.prev;
        Node forward = middle.next;
        Node temp = middle;
        if(n % 2 != 0) {
            middle = middle.prev;
            if(middle == null) {
                front = back = null;
            }
        } else {
            middle = middle.next;
        }

        if(last != null) {
            last.next = temp.next;
        } else {
            front = forward;
        }
        if(forward != null) {
            forward.prev = temp.prev;
        } else {
            back = last;
        }
        temp.next = null;
        temp.prev = null;
        temp = null;
        n--;
        return val;
    }
    
    public int popBack() {
        if(n == 0) {
            return -1;
        }
        int val = back.data;
        Node temp = back;
        back = back.prev;
        if(back == null) {
            front = middle = null;
        } else {
            back.next = null;
            if(n % 2 != 0) {
                middle = middle.prev;
            }
        }

        temp.prev = null;
        temp = null;
        n--;
        return val;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */