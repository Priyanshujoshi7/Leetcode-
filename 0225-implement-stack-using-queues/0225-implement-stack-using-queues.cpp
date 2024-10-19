class MyStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int topValue = q1.front();
        q1.pop();
        return topValue;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};