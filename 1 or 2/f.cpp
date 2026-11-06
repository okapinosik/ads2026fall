#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

};


Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList list1, list2;

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            list1.push_back(val);
        }
    }

    int m;
    if (cin >> m) {
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            list2.push_back(val);
        }
    }


    Node* mergedHead = mergeTwoLists(list1.head, list2.head);


    Node* curr = mergedHead;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << "\n";

    return 0;
}