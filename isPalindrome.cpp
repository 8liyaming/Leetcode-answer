class Solution {
public:
    bool isCharOrNumber(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isPalindrome(string s) {
        // ���ַ��������еĴ�д��ĸת��ΪСд��ĸ
        for (auto& ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
            }
        }

        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            while (begin < end && !isCharOrNumber(s[begin])) {
                ++begin;
            }
            while (begin < end && !isCharOrNumber(s[end])) {
                --end;
            }
            if (s[begin] != s[end]) {
                return false;
            }
            else {
                ++begin;
                --end;
            }
        }

        return true;
    }
};