class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            //1. ����ǲ�������ȡջ���ݽ������������ջ
            //2. ����ǲ���������ջ
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