#include <iostream>
#include <algorithm>

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

    int maxSubarraySum() {
        if (!head) return 0;

        int max_so_far = head->val;
        int current_max = head->val;

        Node* curr = head->next;
        while (curr != nullptr) {
            current_max = max(curr->val, current_max + curr->val);
            max_so_far = max(max_so_far, current_max);
            curr = curr->next;
        }

        return max_so_far;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.push_back(val);
    }

    cout << list.maxSubarraySum() << "\n";

    return 0;
}