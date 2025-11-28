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
    void merge(int *arr, int st, int mid, int end) {
        vector<int> temp;
        int i=st, j = mid+1;

        while(i<=mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=end) temp.push_back(arr[j++]);

        for(int idx=st, x=0; idx <= end; idx++) {
            arr[idx] = temp[x++];
        }
    }

    void mergeSort(int *arr, int st, int end) {
        if (st >= end) return;
        int mid = (st + end) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, st, mid, end);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> mergedArr;
        int size = 0;

        for(auto head : lists) {
            while(head) {
                mergedArr.push_back(head->val);
                head = head->next;
            }
        }

        // for(int i=0; i<size; i++) {
        //     ListNode* curr = lists[i];
        //     while (curr) {
        //         mergedArr.push_back(curr->val);
        //         curr = curr->next;
        //     }
        // }

        int n = mergedArr.size();
        mergeSort(mergedArr.data(), 0, n-1);

        //building linked list from mergeSOrt;
        ListNode* dummy = new ListNode(0);
        ListNode* tail =  dummy;

        for(int val : mergedArr) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        
        return dummy->next;
    }
};



// Merge K Sorted Lists — Your Approach (Step-by-Step)

// Step 1: Extract all values
// Loop through each linked list head in lists
// Traverse nodes while head != nullptr
// Push each head->val into mergedArr

// 📌 Goal: Convert all lists into one array
// Step 2: Sort the array
// Call mergeSort(mergedArr.data(), 0, n-1)
// mergeSort() recursively splits into halves
// merge() combines sorted halves
// 📌 Sorting makes merging simple

// Step 3: Build the sorted linked list
// Create a dummy node → dummy
// Use tail pointer to append nodes
// For each value in sorted array:
// tail->next = new ListNode(val)
// Move tail = tail->next
// Return dummy->next

// 📌 Reconstruct linked list in sorted order
// Step 4: Return final sorted list


// Convert lists → sort values → rebuild sorted list → return head

// ⏱️ Time Complexity (Short)
// Extract values:   O(N)
// Merge sort:       O(N log N)
// Rebuild list:     O(N)
// --------------------------------
// Total:            O(N log N)

// 💾 Space Complexity (Short)
// Array storage + merge temp:  O(N)
// Output linked list:          O(N) (not counted as extra)


// ➡ Auxiliary Space: O(N)
// ✔ What this method is good for
// Easy to understand
// Works reliably