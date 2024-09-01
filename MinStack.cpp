class MinStack {
public:
    MinStack()
    { }

    void push(int val)
    {
        _st.push(val);
        if (_minst.empty() || _minst.top() >= val)  //等于情况不入的话pop可能会出错
        {
            _minst.push(val);
        }
    }

    void pop()
    {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }

        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minst.top();
    }

    stack<int> _st;  //用于存放正常数据
    stack<int> _minst;  //用于存放当前栈顶最小的数据
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */