#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val; 
    Node* next;
    
    Node(string val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const string& val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeConsecutiveDuplicates() {
        if (!head) return;

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
                size--; 
            } else {
                current = current->next;
            }
        }
    }

    void print() const {
        cout << size << "\n";
        Node* current = head;
        while (current != nullptr) {
            cout << current->val << "\n";
            current = current->next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        list.push_back(name);
    }

    list.removeConsecutiveDuplicates();
    list.print();

    return 0;
}