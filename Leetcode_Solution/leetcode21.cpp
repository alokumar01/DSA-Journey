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
 //revision
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* res = nullptr;

        if (list1->val <= list2->val) {
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        } else {
            res = list2;
            res->next = mergeTwoLists(list1, list2->next);
        }
        return res;
    }
};

