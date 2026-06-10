#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) return false;

        unordered_set<ListNode*> set;
        ListNode* cur = head;
        while (cur->next != nullptr)
        {
            if (set.contains(cur)) return true;

            set.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

// 시간복잡도 : O(N)
// Runtime 12 ms Beats 43.82%
// 플로이드 사이클 탐지
// class Solution
// {
// public:
//     bool hasCycle(ListNode* head)
//     {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while ((fast != nullptr) && (fast->next != nullptr))
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) return true;
//         }
//         return false;
//     }
// };
