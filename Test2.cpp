#include <iostream>
using namespace std;

void pattern1() {
    cout << "Pattern 1:\n";
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern2() {
    cout << "Pattern 2:\n";
    for (int i = 6; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3() {
    cout << "Pattern 3:\n";
    for (int i = 1; i <= 6; i++) {
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4() {
    cout << "Pattern 4:\n";
    for (int i = 6; i >= 1; i--) {
        for (int j = 6; j >= 7 - i; j--) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    pattern1();
    pattern2();
    pattern3();
    pattern4();
    return 0;
}




