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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        vector<int> v1, v2, res;

        // Convert l1 to vector
        ListNode* temp = l1;
        while (temp != nullptr) {
            v1.push_back(temp->val);
            temp = temp->next;
        }

        // Convert l2 to vector
        temp = l2;
        while (temp != nullptr) {
            v2.push_back(temp->val);
            temp = temp->next;
        }

        int carry = 0;
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int a = (i < v1.size() ? v1[i] : 0);
            int b = (i < v2.size() ? v2[i] : 0);

            int num = a + b + carry;
            int digit = num % 10;
            carry = num / 10;

            res.push_back(digit);
        }

        if (carry > 0)
            res.push_back(carry);

        ListNode* dummy = new ListNode(0);
        ListNode* pointer = dummy;

        for (int num : res) {
            ListNode* node = new ListNode(num);
            pointer->next = node;
            pointer = node;
        }

        return dummy->next;
    }
};
