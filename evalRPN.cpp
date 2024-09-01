class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            //1. 如果是操作符就取栈数据进行运算后再入栈
            //2. 如果是操作数就入栈
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;

                case '-':
                    st.push(left - right);
                    break;

                case '*':
                    st.push(left * right);
                    break;

                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};