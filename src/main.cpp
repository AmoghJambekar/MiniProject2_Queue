#include <iostream>
#include <limits>
#include "../include/Queue.h"

using namespace std;

void displayMenu() {
    cout << "\nQueue Menu" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Size" << endl;
    cout << "5. Print queue (optional)" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;
    bool running = true;
    
    cout << "Welcome to the Queue System!" << endl;
    
    while (running) {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid value!" << endl;
                        break;
                    }
                    q.enqueue(value);
                    cout << "Enqueued " << value << endl;
                    break;
                    
                case 2:
                    value = q.dequeue();
                    cout << "Dequeued: " << value << endl;
                    break;
                    
                case 3:
                    value = q.peek();
                    cout << "Front element: " << value << endl;
                    break;
                    
                case 4:
                    cout << "Size: " << q.size() << endl;
                    cout << "Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
                    cout << "Full: " << (q.isFull() ? "Yes" : "No") << endl;
                    break;
                    
                case 5:
                    cout << "Print not implemented" << endl;
                    break;
                    
                case 6:
                    running = false;
                    break;
                    
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    return 0;
}