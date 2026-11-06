#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
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

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next_node = nullptr;

        tail = head;

        while (curr != nullptr) {
            next_node = curr->next; // 1. Запоминаем следующий узел
            curr->next = prev;       // 2. Разворачиваем указатель
            prev = curr;            // 3. Сдвигаем prev вперед
            curr = next_node;       // 4. Сдвигаем curr вперед
        }

        head = prev;
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    /* ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    } */
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.push_back(val);
    }

    list.reverse();
    list.print();

    return 0;
}