class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        //时间复杂度：O(N*logN)
       // 空间复杂度：O(N)
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



        //时间复杂度：O(N*logN)(因为sort底层为快排)
        //空间复杂度：O(1)
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k]; 



        //建立k个数的小堆(Top-K问题)
        //时间复杂度：O(N*logK) (如果N很大，K远小于N,logK可忽略)
        //空间复杂度：O(K)
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