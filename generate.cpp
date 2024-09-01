class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows);
        for (size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1);
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }

        for (size_t i = 0; i < vv.size(); ++i)
        {
            for (size_t j = 0; j < vv[i].size(); ++j)
            {
                //上一行的下标相同的那个和前一个相加
                if (vv[i][j] != 1)
                {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }

        return vv;
    }
};