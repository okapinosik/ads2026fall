#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string val) : val(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(const string& val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void rotateLeft(int k) {
        if (!head || k == 0) return;

        Node* curr = head;
        for (int i = 1; i < k && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (!curr || !curr->next) return;

        Node* newHead = curr->next;
        Node* oldTail = tail;

        oldTail->next = head;

        curr->next = nullptr;
        tail = curr;

        head = newHead;
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << (curr->next ? " " : "");
            curr = curr->next;
        }
        cout << "\n";
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        list.push_back(word);
    }

    list.rotateLeft(k);
    list.print();

    return 0;
}