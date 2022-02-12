#include<iomanip>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void ModifiedGuessing();
void RunModifiedGuessGame(int, int);
char TakeUserInput();
bool IsInputValid(int, int);
void PrintGuessedMessage();

int main() {
    ModifiedGuessing();
    return 0;
}

void ModifiedGuessing()
{
    int tracker = 1;
    int low;
    int high;
    char tryagain;

    cout << "............COMPUTER GUESSING GAME............" << endl;
    cout << "HEY USER, Secretly choose a number and I can guess your number with a little help.\nFirst tell me the boundaries...\n\n";
    do {
        cout << "Lowest Boundary: ";
        cin >> low;
        cout << "Highest Boundary: ";
        cin >> high;
        cout << endl;

        RunModifiedGuessGame(low, high);
        // Ask for replay.
        cout << "\n................................Game: " << tracker << " just ended.................................\n";
        cout << "Press any other key to exit, or Enter y to play again: " << endl;
        cin >> tryagain;
        tracker++;
    } while (tryagain == 'y' || tryagain == 'Y');
}

void RunModifiedGuessGame(int low, int high) {
    int computer_guess = 0;
    char user_guide;

    srand(time(0));
    do {
        // We want to randomly choose a number between high and low, excluding both boundaries.
        int rand_zero_minimum = rand() % (high - low);
        computer_guess = rand_zero_minimum == 0 ? low + 1 : rand_zero_minimum + low;
        cout << "Computer guess is " << computer_guess << endl;

        user_guide = TakeUserInput();
        if (user_guide == 'h') {
            if (!IsInputValid(computer_guess, low)) {
                cout << "Currently low is " << low << " and high is " << computer_guess << ". This means my guess must be the right answer.\n Choose equal(e).\n";

                if (TakeUserInput() != 'e') {
                    cout << "Guide is still invalid based on your current boundary. Ending program now...\n";
                    exit(0);
                }
                PrintGuessedMessage();
                break;
            }
            else {
                cout << "Your number is too high, try again..." << endl;
                high = computer_guess;
            }
        }
        else if (user_guide == 'l') {
            if (!IsInputValid(high, computer_guess)) {
                cout << "Currently low is " << low << " and high is " << high << ". This means my guess must be the right answer.\n Choose equal(e).\n";

                if (TakeUserInput() != 'e') {
                    cout << "Guide is still invalid based on your current boundary. Ending program now...\n";
                    exit(0);
                }
                PrintGuessedMessage();
                break;
            }
            else {
                cout << "Your number is too low, try again..." << endl;
                low = computer_guess;
            }
        }
        else {
            PrintGuessedMessage();
            break;
        }
    } while (user_guide != 'e');
}

void PrintGuessedMessage() {
    cout << "Fantastic, I guessed right!!!" << endl;
}

char TakeUserInput() {
    char user_guide;
    do {
        cout << "Input guide: Is this lower(l), higher(h), or equal(e) to the goal number?\n";
        cin >> user_guide;
        if (user_guide != 'h' && user_guide != 'l' && user_guide != 'e') {
            cout << "CPU cannot understand this guide, input a valid guide letter.\n";
        }
    } while (user_guide != 'h' && user_guide != 'l' && user_guide != 'e');
    return user_guide;
}

bool IsInputValid(int high, int low) {
    if (high - low > 1) {
        return true;
    }
    return false;
}

