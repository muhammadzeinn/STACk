// Q4_CircularQueue.cpp - Circular queue (kapasitas 5) dengan modulo, tanpa STL
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;    // indeks elemen paling depan
int rearIdx = -1;    // indeks elemen paling belakang
int count = 0;       // jumlah elemen -> pembeda Full vs Empty

bool isEmpty() { return count == 0; }
bool isFull()  { return count == MAX; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue penuh, " << value << " ditolak." << endl;
        return;
    }
    rearIdx = (rearIdx + 1) % MAX;   // wrap-around ke indeks 0 bila melewati ujung
    queueArr[rearIdx] = value;
    count++;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[frontIdx] << " dequeued." << endl;
    frontIdx = (frontIdx + 1) % MAX; // geser pointer front, tanpa geser elemen
    count--;
}

void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(kosong)" << endl;
        return;
    }
    for (int i = 0; i < count; i++)
        cout << queueArr[(frontIdx + i) % MAX] << " ";
    cout << endl;
}

int main() {
    // ===== Mandatory 10-step test =====
    cout << "=== MANDATORY TEST ===" << endl;
    int vals[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) enqueue(vals[i]);   // langkah 1-5
    dequeue();                                      // langkah 6
    dequeue();                                      // langkah 7
    enqueue(60);                                    // langkah 8 (wrap around)
    enqueue(70);                                    // langkah 9 (wrap around)
    display();                                      // langkah 10
    cout << "=== END TEST ===" << endl;

    // ===== Menu interaktif =====
    int choice, value;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Display  4. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 4);
    return 0;
}