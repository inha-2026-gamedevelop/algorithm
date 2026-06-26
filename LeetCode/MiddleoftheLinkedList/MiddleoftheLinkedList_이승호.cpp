/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // 위 ListNode를 사용해서 하는건지 몰라 찾아보다가 토끼,거북이 풀이방법을 봐버려서 일단은 풀긴했습니다

class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};

// 