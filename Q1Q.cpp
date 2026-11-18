
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = -1;   // indeks elemen paling depan
int rearIdx = -1;    // indeks elemen paling belakang

bool isEmpty() { return frontIdx == -1; }
bool isFull()  { return rearIdx == MAX - 1; }

// Masukkan di belakang (rear)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue penuh." << endl;
        return;
    }
    if (isEmpty()) frontIdx = 0;   // elemen pertama
    rearIdx++;
    queueArr[rearIdx] = value;
    cout << value << " inserted successfully." << endl;
}

// Keluarkan dari depan (front)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully." << endl;
    frontIdx++;
    if (frontIdx > rearIdx) {      // queue jadi kosong -> reset
        frontIdx = -1;
        rearIdx = -1;
    }
}

void front() {
    if (isEmpty()) {
        cout << "Queue kosong." << endl;
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(kosong)" << endl;
        return;
    }
    for (int i = frontIdx; i <= rearIdx; i++) cout << queueArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        display();
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: front(); break;
            case 4: display(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);
    return 0;
}