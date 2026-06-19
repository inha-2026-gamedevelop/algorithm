class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        MergeSort(nums, temp, 0, static_cast<int>(nums.size()) - 1);
        return nums;
    }

private:
    void MergeSort(vector<int>& nums, vector<int>& temp, int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        MergeSort(nums, temp, left, mid);
        MergeSort(nums, temp, mid + 1, right);
        Merge(nums, temp, left, mid, right);
    }

    void Merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right)
    {
        for (int i = left; i <= right; ++i)
            temp[i] = nums[i];

        int l = left;
        int r = mid + 1;
        int idx = left;

        while ((l <= mid) && (r <= right))
        {
            if (temp[l] <= temp[r]) nums[idx++] = temp[l++];
            else nums[idx++] = temp[r++];
        }

        while (l <= mid) nums[idx++] = temp[l++];
    }
};

// 머지소트 
// 동작 원리
// 1. 배열을 분할과 병합을 나눠야한다.
// 2. 분할은 재귀적으로 배열을 반으로 나누는 것이다. (MergeSort 함수)
// 3. 병합은 두 개의 정렬된 배열을 하나의 정렬된 배열로 합치는 것이다. (Merge 함수)
// 예를 들어 nums=[5,2,3,1] 인 경우

// 분할 :
// [5,2,3,1]
// [5,2] [3,1]
// [5][2] [3][1]

// 병합 :
// temp = [2,5,1,3]  (left=0, mid=1, right=3)
// l=0(2)  r=2(1)
// 2 vs 1 -> 1이 작음 -> nums[0]=1, r++
// 2 vs 3 -> 2가 작음 -> nums[1]=2, l++
// 5 vs 3 -> 3이 작음 -> nums[2]=3, r++
// l남음 -> nums[3]=5


// [5][2] -> [2,5]
// [3][1] -> [1,3]
// [2,5]+[1,3] -> [1,2,3,5]
