class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;
        string retstr;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = 0;
            int val2 = 0;
            if (end1 >= 0)
            {
                val1 = num1[end1] - '0';
            }

            if (end2 >= 0)
            {
                val2 = num2[end2] - '0';
            }

            int ret = val1 + val2 + next;
            if (ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }

            retstr += (ret + '0');  //尾插(直接往后放,加上后面的逆序复杂度为O(2N))
            //retstr.insert(retstr.begin(), '0' + ret); //头插(每次都要挪动数据，复杂度为O(N^2))
            --end1;
            --end2;
        }

        if (next == 1)
        {
            retstr += '1';
            //retstr.insert(retstr.begin(), '1');
        }

        reverse(retstr.begin(), retstr.end());
        return retstr;
    }
};