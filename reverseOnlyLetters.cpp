class Solution {
public:
    bool IsChar(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string reverseOnlyLetters(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && IsChar(s[begin]) == false)
            {
                ++begin;
            }

            while (begin < end && IsChar(s[end]) == false)
            {
                --end;
            }

            swap(s[begin], s[end]);

            ++begin;
            --end;
        }

        return s;
    }
};