class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i = 0; i < q.size()-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        for(int i = 0; i < q.size()-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        int el = q.front();
        q.push(q.front());
        q.pop();

        return el;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */