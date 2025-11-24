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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


// Floyds Algorithm
// While traversing the List:
// slow pointer will move one step at a time.
// fast pointer moves two steps at a time.
// If there's a cycle, the fast pointer will eventually catch up with the slow pointer within the cycle because it's moving faster.
// If there's no cycle, the fast pointer will reach the end of the list (i.e., it will become NULL).
// When the slow and fast pointers meet, a cycle or loop exists.