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
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        while (l1)
        {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }

        while (l2)
        {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];

        for(int i = 0; i < n-1; ++i)
            lists[i+1] = merge(lists[i], lists[i+1]);
        
        return lists[n-1];
    }
};