#include<iostream>

using namespace std;

class Hashtable {
public:
    int data;
    Hashtable* next;
};

Hashtable hassh[10];

void insert(int data) {
    int key = data % 10;
    Hashtable* newNode = new Hashtable();
    newNode->data = data;
    newNode->next = nullptr;

    // Check if the bucket is empty
    if (hassh[key].data == 0 && hassh[key].next == nullptr) {
        hassh[key] = *newNode;
    } else {
        // Collision handling: Append to the end of the linked list
        Hashtable* current = &hassh[key];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display() {
    for (int i = 0; i < 10; ++i) {
        cout << "Bucket " << i << ": ";
        Hashtable* current = &hassh[i];
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout<<endl;
    }
}

int main() {
    cout << hassh[2].data << endl;

    insert(12);
    insert(23);
    insert(32);
    insert(42);
    insert(122);

    display();

    return 0;
}