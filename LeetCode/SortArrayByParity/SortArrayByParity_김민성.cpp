class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        for (int i = 1; i < n; ++i)
        {
            int key = nums[i];
            int j = i - 1;

            while ((j >= 0) && ((key % 2) == 0) && ((nums[j] % 2) != 0))
            {
                nums[j + 1] = nums[j];
                --j;
            }

            nums[j + 1] = key;
        }

        return nums;
    }
};

// 삽입정렬
// 일반 삽입정렬은 nums[j] > key 로 비교하지만
// 짝수는 앞에, 홀수는 뒤에 오도록 하기 위해 nums[j] % 2 != 0(홀수) && key % 2 == 0(짝수)로 비교한다.(11번째줄)
// 예를 들어 nums=[3,1,2,4] 인 경우
// 1. i = 1; key = 1: nums=[3,1,2,4] 조건 불만족, 그대로 둠 [3,1,2,4
// 2. i = 2; key = 2: nums=[3,1,2,4] 조건 만족, 3을 한 칸 뒤로 밀고 key를 0번 인덱스에 삽입 [2,3,1,4]
// 3. i = 3; key = 4: nums=[2,3,1,4] 조건 만족, 3을 한 칸 뒤로 밀고 key를 1번 인덱스에 삽입 [2,4,3,1]
