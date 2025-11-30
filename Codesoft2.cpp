#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    int choice;
    
    cout << "=== Basic Calculator ===\n";
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "\nChoose operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;
    
    // Input validation for choice
    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "Invalid choice! Please run again.\n";
        return 1;
    }
    
    // If-else chain for operations
    if (choice == 1) {
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (choice == 2) {
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (choice == 3) {
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (choice == 4) {
        if (num2 == 0) {
            cout << "Error: Division by zero!\n";
        } else {
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << endl;
        }
    }
    
    return 0;
}
