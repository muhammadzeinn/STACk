
#include <iostream>
using namespace std;

const int MAX = 100;     // kapasitas stack karakter
char stackArr[MAX];      // stack berisi char
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stackArr[++top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return stackArr[top--];
}

int main() {
    char word[MAX];
    cout << "Enter a word: ";
    cin.getline(word, MAX);

    // hitung panjang kata secara manual (tanpa strlen)
    int len = 0;
    while (word[len] != '\0') len++;

    // Push: masukkan tiap karakter dari kiri ke kanan
    for (int i = 0; i < len; i++) push(word[i]);

    // Pop: keluarkan semua karakter -> otomatis urutan terbalik
    char reversed[MAX];
    int idx = 0;
    while (!isEmpty()) reversed[idx++] = pop();
    reversed[idx] = '\0';

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;
    return 0;
}