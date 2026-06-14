class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* first = head;
        ListNode* second = head->next;
        while (first != nullptr)
        {
            if (first == second) return true;
            if (second == nullptr || second->next == nullptr) return false;
            first = first->next;
            second = second->next->next;
        }
        return false;
    }
};