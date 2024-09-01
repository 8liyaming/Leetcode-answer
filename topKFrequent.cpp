class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        //统计出次数
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }

        //按次数排序，且通过仿函数控制从小到大
        multimap<int, string, greater<int>> countSort;
        for (auto& kv : countMap)
        {
            countSort.insert(make_pair(kv.second, kv.first));
        }

        vector<string> v;
        for (auto e : countSort)
        {
            v.push_back(e.second);
            if (--k == 0)
            {
                break;
            }
        }

        return v;
    }
};