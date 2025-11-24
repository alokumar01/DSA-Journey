class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // STEP 1: find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at middle
        ListNode* second = slow->next;
        slow->next = nullptr;   // cut here (correct)

        // STEP 2: reverse second half
        ListNode* prev = nullptr;
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // STEP 3: merge two halves
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while (p2) {
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;

            p1->next = p2;
            p2->next = t1;

            p1 = t1;
            p2 = t2;
        }
    }
};

// Quick Summary

// Find middle using slow/fast.
// Reverse second half
// Merge nodes alternately.
// In-place → O(1) space, single pass stages → O(n) time.