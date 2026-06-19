#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    // [3 1 2 4]
    // 1부터 시작 -> 3124 -> 2번 출발 -> 3214 -> 2314 -> 4번 출발 -> 2341 -> 2431

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] % 2 != 0)
            continue;
        int idx = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[j] % 2 != 0)
            {
                int temp = nums[idx];
                nums[idx] = nums[j];
                nums[j] = temp;

                --idx;
            }
        }
    }

    return nums;
}