class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = (right - left) / 2; // size = 4, mid = 1 (idx)

        vector<int> results;
        vector<int> leftNums;
        vector<int> rightNums;
        for (int i = 0; i < nums.size(); ++i)
        {
           if (i > mid)
                rightNums.push_back(nums[i]);
            else
                leftNums.push_back(nums[i]);
        }

        sort(leftNums.rbegin(), leftNums.rend());
        sort(rightNums.rbegin(), rightNums.rend());

        int l, r;
        while (!leftNums.empty() or !rightNums.empty())
        {
            if (leftNums.empty())
            {
                r = rightNums.back();
                results.push_back(r);
                rightNums.pop_back();
                continue;
            }
            if (rightNums.empty())
            {
                l = leftNums.back();
                results.push_back(l);
               leftNums.pop_back();
               continue;
            }


            l = leftNums.back();
            r = rightNums.back();

            if (l < r)
            {
               results.push_back(l);
               leftNums.pop_back();
           }
            else
           {
                results.push_back(r);
               rightNums.pop_back();
           }
        }

        return results;
    }
};