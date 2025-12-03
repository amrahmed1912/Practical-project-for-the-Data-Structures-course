#include <iostream>
#define SIZE 50
using namespace std;

struct Node{
    int data;
    Node* Next;
    Node(int val): data(val), Next(NULL) {}
};

// =========== Linked List Implementation ===========
class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(): head(NULL) {}

        void insertNode(int data){
            Node* newnode = new Node(data);

            if(head == NULL){
                head = newnode;
                newnode->Next = NULL;
            }
            else{
                Node* temp = head;
                while(temp->Next != NULL){
                    temp = temp->Next;
                }
                temp->Next = newnode;
                newnode->Next = NULL; 
            }
        }

        void deleteNode(int data) {
            if (head == nullptr){ 
                cout << "Linked list is empty!\n";
                return;
            }

            if (head->data == data) {
                Node* toDelete = head;
                head = head->Next;
                delete toDelete;
                return;
            }

            Node* temp = head;
            while(temp->Next != nullptr && temp->Next->data != data){
                temp = temp->Next;
            }

            if (temp->Next != nullptr) {
                Node* toDelete = temp->Next;
                temp->Next = temp->Next->Next; 
                delete toDelete;
            }
        }

        void Display(){
            Node* current = head;
            if(head == NULL) cout<<"Linked list is empty!\n";
            
            cout<<"Linked List Element: ";
            while(current != NULL){
                cout<<current->data <<" ";
                current = current->Next;
            }
            cout<<endl;
        }

};


// =========== Stack Implementation ===========
class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(int data) {
        if (top == 99) {
            cout << "Stack is Full!\n";
            return;
        }
        arr[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Popped: " << arr[top--] << "\n";
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// =========== Queue Implementation ===========
class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    void enqueue(int x) {
        if (rear == 100) {
            cout << "Queue is Full!\n";
            return;
        }
        arr[rear++] = x;
        cout << "Enqueued Successfully.\n";
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << "\n";
    }

    void display() {
        if (front == rear) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front; i < rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// =========== Array Implementation ===========
class Array {
    private:
        int arr[SIZE]; 
        int size = 0;   

    public:
        void insert(int data) {
            if (size == SIZE) {  
                cout << "array is full \n";
                return;
            }

            arr[size] = data;  
            size++;            
        }

        void deleteItems(int data) {
            if (size == 0) {
                cout <<"array is empty\n";
                return;
            }

            for (int i = 0; i < size; i++) {
                if (arr[i] == data) {
                    for (int j = i; j < size - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    size--;  
                    i--;     
                }
            }
        }


        void Display() {
            if (size == 0) { 
                cout << "array is empty\n";
                return;
            }

            cout<<"Array element: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " "; 
            }
            cout << endl;
        }
};

// =========== Main Menu System ===========
int main() {
    Array a;
    LinkedList l;
    Stack s;
    Queue q;

    int choice;

    while (true) {
        cout << "=====================================\n";
        cout << "   Data Structure Console Manager    \n";
        cout << "=====================================\n";

        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Array\n";
        cout << "2. Liked List\n";
        cout << "3. Stack\n";
        cout << "4. Queue\n";
        cout << "5. Exit\n";
        cout << "Choose Data Structure: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting Program...\n";
            break;
        }

        // --- Array Menu ---
        else if(choice == 1){
            int op, val;
            while(true){
                cout << "\n--- Array Menu ---\n";
                cout << "1. Insert Item\n2. Delete Item\n3. Display\n4. Back\n";
                cout << "Choose Operation: ";
                cin >> op;

                if (op == 4) break;

                switch (op){
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    a.insert(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin>>val;
                    a.deleteItems(val);
                    break;
                case 3:
                    a.Display();
                    break;
                default:
                    cout << "Invalid Option!\n";
                }
            }
        }

        // --- Linked List Menu ---
        else if(choice == 2){
            int op, val;
            while(true){
                cout << "\n--- Linked List Menu ---\n";
                cout << "1. Insert node\n2. Delete node\n3. Display\n4. Back\n";
                cout << "Choose Operation: ";
                cin >> op;

                if (op == 4) break;

                switch (op){
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    l.insertNode(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin>>val;
                    l.deleteNode(val);
                    break;
                case 3:
                    l.Display();
                    break;
                default:
                    cout << "Invalid Option!\n";
                }
            }
        }

        // --- Stack Menu ---
        if (choice == 3) {
            int op, val;
            while (true) {
                cout << "\n--- Stack Menu ---\n";
                cout << "1. Push\n2. Pop\n3. Display\n4. Back\n";
                cout << "Choose Operation: ";
                cin >> op;

                if (op == 4) break;

                switch (op) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                default:
                    cout << "Invalid Option!\n";
                }
            }
        }

        // --- Queue Menu ---
        else if (choice == 4) {
            int op, val;
            while (true) {
                cout << "\n--- Queue Menu ---\n";
                cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n";
                cout << "Choose Operation: ";
                cin >> op;

                if (op == 4) break;

                switch (op) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.display();
                    break;
                default:
                    cout << "Invalid Option!\n";
                }
            }
        }

        else {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}