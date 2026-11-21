#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class BrowserHistory {
string stack[MAX];
int top;

public:
BrowserHistory() {
top = -1;
}

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(string url) {
    if (isFull()) {
        cout << "Stack Overflow! History is full. Cannot visit more pages.\n";
        return;
    }
    stack[++top] = url;
    cout << "Visited: " << url << "\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! No previous website available.\n";
        return;
    }
    cout << "Going back from: " << stack[top] << "\n";
    top--;
    if (!isEmpty()) {
        cout << "Now on: " << stack[top] << "\n";
    } else {
        cout << "No more pages in history.\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "No website currently open.\n";
        return;
    }
    cout << "Current website: " << stack[top] << "\n";
}

void displayHistory() {
    if (isEmpty()) {
        cout << "History is empty.\n";
        return;
    }
    cout << "\n--- Browser History (Top to Bottom) ---\n";
    for (int i = top; i >= 0; i--) {
        cout << (top - i + 1) << ". " << stack[i] << "\n";
    }
    cout << "----------------------------------------\n";
}

};

int main() {
BrowserHistory browser;
int choice;
string url;

cout << "===== Web Browser History Management System =====\n";

do {
    cout << "\n1. Visit a Website (Push)\n";
    cout << "2. Go Back (Pop)\n";
    cout << "3. View Current Website (Peek)\n";
    cout << "4. View Full History\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Enter website URL: ";
            getline(cin, url);
            browser.push(url);
            break;
        case 2:
            browser.pop();
            break;
        case 3:
            browser.peek();
            break;
        case 4:
            browser.displayHistory();
            break;
        case 5:
            cout << "Exiting browser. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
    }
} while (choice != 5);

return 0;

}