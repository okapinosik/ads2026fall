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
        int size;

    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}

        void push_back(int val) {
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

        void deleteMiddle() {
            // Если список пуст или в нем всего 1 узел
            if (!head) return;
            
            if (size == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                size = 0;
                return;
            }

            int midIndex = size / 2;
            Node* prev = head;

            for (int i = 0; i < midIndex - 1; i++) {
                prev = prev->next;
            }

            Node* toDelete = prev->next;
            
            prev->next = toDelete->next;

            if (toDelete == tail) {
                tail = prev;
            }

            delete toDelete;
            size--;
        }

        void print() const {
            if (!head) {
                cout << "\n";
                return;
            }

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

        int n;
        if (!(cin >> n)) return 0;

        LinkedList list;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            list.push_back(val);
        }

        list.deleteMiddle();
        list.print();

        return 0;
    }