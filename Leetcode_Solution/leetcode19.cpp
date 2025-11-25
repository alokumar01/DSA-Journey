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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* revHead = prev;

        if (n == 1) {
            ListNode* temp = revHead;
            revHead = revHead->next;
            delete temp;
        } else {
            ListNode* curr2 = revHead;
            ListNode* prev2 = NULL;
            for (int i = 1; i < n && curr2 != NULL; i++) {
                prev2 = curr2;
                curr2 = curr2->next;
            }

            if (curr2 != NULL) {
                prev2->next = curr2->next;
                delete curr2;
            }
        }
        prev = nullptr;
        curr = revHead;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};