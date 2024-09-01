class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        //ʱ�临�Ӷȣ�O(N*logN)
       // �ռ临�Ӷȣ�O(N)
        priority_queue<int> pq;
        for(auto e : nums)
        {
            pq.push(e);
        }
        while(--k)
        {
            pq.pop();
        }

        return pq.top(); 



        //ʱ�临�Ӷȣ�O(N*logN)(��Ϊsort�ײ�Ϊ����)
        //�ռ临�Ӷȣ�O(1)
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k]; 



        //����k������С��(Top-K����)
        //ʱ�临�Ӷȣ�O(N*logK) (���N�ܴ�KԶС��N,logK�ɺ���)
        //�ռ临�Ӷȣ�O(K)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        size_t i = 0;
        for (; i < k; ++i)
        {
            minHeap.push(nums[i]);
        }

        for (; i < nums.size(); ++i)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};