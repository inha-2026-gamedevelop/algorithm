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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) return head;

        ListNode* first = head;
        ListNode* result = head;

        while (1)
        {
            result = result->next;
            first = first->next;
            if (first->next == nullptr) return result;
            first = first->next;
            if (first->next == nullptr) return result;
        }
    }
};

/*
노드의 중간 -> 앞 노드는 2번, 뒤 노드는 1번 움직임을 통해 뒷 노드는 항상 중간에 위치
*/
