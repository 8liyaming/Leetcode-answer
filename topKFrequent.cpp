class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        //ͳ�Ƴ�����
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }

        //������������ͨ���º������ƴ�С����
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