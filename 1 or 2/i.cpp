#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* prev;
    Node* next;

    Node(const string& t) : title(t), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(const string& title) {
        Node* newNode = new Node(title);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok\n";
    }

    void add_back(const string& title) {
        Node* newNode = new Node(title);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "ok\n";
    }

    void erase_front() {
        if (!head) {
            cout << "error\n";
            return;
        }
        Node* temp = head;
        cout << temp->title << "\n";

        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void erase_back() {
        if (!tail) {
            cout << "error\n";
            return;
        }
        Node* temp = tail;
        cout << temp->title << "\n";

        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void front() const {
        if (!head) {
            cout << "error\n";
        } else {
            cout << head->title << "\n";
        }
    }

    void back() const {
        if (!tail) {
            cout << "error\n";
        } else {
            cout << tail->title << "\n";
        }
    }
    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "ok\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DoublyLinkedList list;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string title;
            cin >> title;
            list.add_front(title);
        } else if (command == "add_back") {
            string title;
            cin >> title;
            list.add_back(title);
        } else if (command == "erase_front") {
            list.erase_front();
        } else if (command == "erase_back") {
            list.erase_back();
        } else if (command == "front") {
            list.front();
        } else if (command == "back") {
            list.back();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "exit") {
            cout << "goodbye\n";
            break;
        }
    }

    return 0;
}