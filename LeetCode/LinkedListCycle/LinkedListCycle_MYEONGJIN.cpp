/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;

        std::unordered_set<ListNode*> s;
        
        ListNode* curr = head;
        while (curr != nullptr)
        {
            if (s.find(curr) != s.end())
                return true;
            
            s.insert(curr);
            
            curr = curr->next;
        }

        return false;
    }
};
