class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_map<int, int> countMap;  //map<int, int> countMap“≤ø…“‘
        for (auto e : nums)
        {
            countMap[e]++;
        }

        int N = nums.size() / 2;
        for (auto kv : countMap)
        {
            if (kv.second == N)
            {
                return kv.first;
            }
        }

        return -1;
    }
};