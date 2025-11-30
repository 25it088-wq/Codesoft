#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;  // Brings std namespace into global scope

int main() {
    // Seed random number generator with current time
    srand(time(0));
    
    // Generate random number between 1 and 100
    int secret_number = rand() % 100 + 1;
    int guess, attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I've picked a number between 1 and 100. Can you guess it?\n\n";
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        // Input validation
        if (cin.fail()) {
            cout << "Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            attempts--;  // Don't count invalid attempts
            continue;
        }
        
        // Provide feedback
        if (guess < secret_number) {
            cout << "Too low! Try a higher number.\n\n";
        } else if (guess > secret_number) {
            cout << "Too high! Try a lower number.\n\n";
        } else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts!\n";
        }
    } while (guess != secret_number);
    
    return 0;
}
