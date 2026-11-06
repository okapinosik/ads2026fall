#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

int getSize(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

Node* inserts(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 0; i < p - 1; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head) return nullptr;

    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    for (int i = 0; i < p - 1; i++) {
        curr = curr->next;
    }

    Node* toDelete = curr->next;
    curr->next = toDelete->next;
    delete toDelete;

    return head;
}

void print(Node* head) {
    if (!head) {
        cout << "-1\n";
        return;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << "\n";
}

Node* replace(Node* head, int p1, int p2) {
    Node* curr = head;
    for (int i = 0; i < p1; i++) {
        curr = curr->next;
    }
    int val = curr->val;

    head = remove(head, p1);

    head = inserts(head, val, p2);

    return head;
}

// 5. reverse — разворот списка
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next_node = nullptr;

    while (curr != nullptr) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

Node* cyclic_left(Node* head, int x) {
    int n = getSize(head);
    if (n <= 1) return head;

    x = x % n;
    if (x == 0) return head;

    Node* curr = head;
    for (int i = 1; i < x; i++) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = head;
    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    int n = getSize(head);
    if (n <= 1) return head;

    x = x % n;
    if (x == 0) return head;

    return cyclic_left(head, n - x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = nullptr;
    int cmd;

    while (cin >> cmd && cmd != 0) {
        if (cmd == 1) {
            int x, p;
            cin >> x >> p;
            head = inserts(head, x, p);
        } else if (cmd == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (cmd == 3) {
            print(head);
        } else if (cmd == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (cmd == 5) {
            head = reverse(head);
        } else if (cmd == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (cmd == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    return 0;
}