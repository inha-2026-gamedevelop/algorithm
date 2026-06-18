void merge(vector<int>& nums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];
    }

    while (i < n1)
        nums[k++] = L[i++];
    while (j < n2)
        nums[k++] = R[j++];
}

void bottomUpMergeSort(vector<int>& nums)
{
    int n = nums.size();
    
    for (int width = 1; width < n; width *= 2)
    {
        for (int i = 0; i < n; i += 2 * width)
        {
            int left = i;
            int mid = min(i + width - 1, n - 1);
            int right = min(i + 2 * width - 1, n - 1);

            if (mid < n - 1)
                merge(nums, left, mid, right);
        }
    }
}

class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        bottomUpMergeSort(nums);
        return nums;
    }
};
