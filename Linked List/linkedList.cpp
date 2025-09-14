#include <iostream>
using namespace std;
#include <list>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    { // constructor
        data = val;
        next = NULL;
    }

    ~Node()
    { // destructor
        // cout << "~Node " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        // cout << "~List\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic
        // Node* newNode(val); //static why we use new keyword because in static after the call of function end then values will also be deleted but we dont want that so we dont use the static implementation here so we use dynamic allocation.
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    { // print elements
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next; // temp is now at pos-1 e.g 1 index
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    { // delete the first element means remove the head
        if (head == NULL)
        {
            cout << "Head is NULL";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL; // prev's val tails
        delete temp;
        tail = temp;
    }

    int search(int val)
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                // cout << "Found" << endl;
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // function for calculating size
    int size()
    {
        int sx = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            sx++;
        }
        return sx;
    }

    void removeNth(int n)
    {
        int sz = size();
        Node *prev = head;

        for (int i = 1; i < (sz - n); i++)
        {
            prev = prev->next;
        }
        Node *toDel = prev->next;
        cout << "going to delete: " << toDel->data << endl;

        prev->next = prev->next->next;
    }

    bool isCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << " cycle exist\n";
                return true;
            }
        }

        cout << "cycles doesn't exists\n";
        return false;
    }

    void removeCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        bool isDetect = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << "Cycle exists\n";
                isDetect = true;
                break;
            }
        }

        if (!isDetect)
        {
            cout << "Cycles doesnt exists\n";
            return;
        }

        slow = head;
        if (slow == fast)
        { // special case
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL; // remove cycle
            cout << "Cycle is breaked when head and tail is at same\n";
        }
        else
        {
            Node *prev = fast;

            while (slow != fast)
            {
                // slow = head;
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
            cout << "Cycle is breaked when head and tail is not same\n";
        }
    }

    // MERGE SORT CODE BELOW ALL
    Node *splitAtMid(Node *head)
    {
        if (!head || !head->next)
            return nullptr;

        Node *slow = head;
        Node *fast = head;
        Node *prev = slow;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != NULL)
        {
            prev->next = NULL;
        }
        return slow;
    }

    Node *merge(Node *left, Node *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        Node *result = nullptr;

        if (left->data <= right->data)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *rightHead = splitAtMid(head);

        Node *left = mergeSort(head);
        Node *right = mergeSort(rightHead);

        return merge(left, right);
    }

    // ZIG- ZAG Linked List
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *zigZagLL(Node *head)
    {
        Node *rightHead = splitAtMid(head);

        Node *rightHeadRev = reverse(rightHead);

        // Alternate merging
        Node *left = head;
        Node *right = rightHeadRev;
        Node *tail = nullptr;

        while (left != NULL && right != NULL)
        {
            Node *nextLeft = left->next;
            Node *nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            tail = right;

            left = nextLeft;
            right = nextRight;
        }

        if (right != NULL)
        {
            tail->next = right;
        }
        return head;
    }
};
















int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.printList();

    // ll.pop_front();
    // ll.printList();

    // ll.pop_back();
    // ll.printList();

    // cout << "Index found: " << ll.search(2) << endl;

    // ll.reverse();
    // ll.printList();

    // ll.removeNth(2);
    // ll.printList();

    // ll.tail->next = ll.head; // head and tail is at same
    // ll.isCycle(ll.head);
    // Node* temp = ll.head->next;
    // ll.tail->next = temp;
    // ll.removeCycle(ll.head);
    // ll.printList();

    // ll.printList();

    // merge sort
    // ll.head = ll.mergeSort(ll.head);
    // ll.printList();

    ll.head = ll.zigZagLL(ll.head);
    ll.printList();

    // ll.push_back(4);
    // ll.push_back(5);
    // ll.printList();

    // ll.insert(100, 2);
    // ll.printList();

    return 0;
}