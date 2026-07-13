class MyQueue {
private:
    stack<int> inbox;
    stack<int> outbox;

    void transfer() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inbox.push(x);
    }

    int pop() {
        transfer();
        int val = outbox.top();
        outbox.pop();
        return val;
    }

    int peek() {
        transfer();
        return outbox.top();
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};