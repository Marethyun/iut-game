#include <iostream>

using namespace std;

void clearScreen() {
    cout << "\033[2J";
    cout << "\033[H";
}

int main() {
    clearScreen();
    char t;
    cin >> t;
    return 0;
}