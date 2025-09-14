#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(list<int> ll)
{
    list<int>::iterator itr;
Node* splitAtMid(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr;
    return slow;
}
    cout << endl;
}



Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL) {
        prev->next = NULL;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL) {
    if (i->data <= j->data) {
        ans.push_back(i->data);
        i = i->next;
    } else {
        ans.push_back(j->data);
        j = j->next;
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans;
}





int main()
{
    list<int> ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // printList(ll);
    // cout << "size " << ll.size() << endl;
    // cout << "head " << ll.front() << endl;
    // cout << "tail " << ll.back() << endl;

    // ll.pop_front();
    // ll.pop_back();

    printList(ll);

    return 0;
}