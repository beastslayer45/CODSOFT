#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, cleaned = "";

    cout << "Enter a word or phrase: ";
    getline(cin, input);

    // Remove spaces and convert to lowercase
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            cleaned += tolower(input[i]);
        }
    }

    // Check palindrome
    bool isPalindrome = true;
    int start = 0;
    int end = cleaned.length() - 1;

    while (start < end) {
        if (cleaned[start] != cleaned[end]) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    // Display result
    if (isPalindrome) {
        cout << "The given input is a palindrome.\n";
    } else {
        cout << "The given input is NOT a palindrome.\n";
    }

    return 0;
}
