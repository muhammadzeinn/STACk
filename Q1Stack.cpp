// Q1_Stack.cpp - Stack berbasis array (kapasitas 5), tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;     
int stackArr[MAX];      
int top = -1;           

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }


void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Stack penuh, " << value << " tidak bisa dimasukkan." << endl;
        return;
    }
    top++;
    stackArr[top] = value;
    cout << value << " inserted successfully." << endl;
}


void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack kosong." << endl;
        return;
    }
    cout << stackArr[top] << " removed successfully." << endl;
    top--;
}

// Lihat elemen puncak tanpa menghapus
void peek() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}


void display() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push  2. Pop  3. Peek" << endl;
        cout << "4. Display  5. Exit" << endl;
        cout << "\nChoose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);
    return 0;
}