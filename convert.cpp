#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <limits> // Add this header for numeric_limits

void gotoxy(short x, short y) {
    COORD pos {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

using namespace std;

// Helper function to convert a decimal number to any base (2, 8, 16)
string convertToBase(int decimal, int base, const string& digits) {
    if (decimal == 0) return "0";

    string result = "";
    while (decimal > 0) {
        result += digits[decimal % base];
        decimal /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to convert a decimal number to octal
string decimalToOctal(int decimal) {
    return convertToBase(decimal, 8, "0123456789");
}

// Function to convert a decimal number to hexadecimal
string decimalToHexadecimal(int decimal) {
    return convertToBase(decimal, 16, "0123456789ABCDEF");
}

// Function to convert a decimal number to binary
string decimalToBinary(int decimal) {
    return convertToBase(decimal, 2, "01");
}

int main() {
    int decimal;
    gotoxy(80, 6);
    cout << "Enter a decimal number: ";
    gotoxy(80, 7);
    cin >> decimal;

    // Check for input failure
   

    // Set position for output
    gotoxy(80, 5);

    // Output conversions
    cout << "Octal representation: " << decimalToOctal(decimal) << endl;
    gotoxy(80, 6);
    cout << "Hexadecimal representation: " << decimalToHexadecimal(decimal) << endl;
    gotoxy(80, 7);
    cout << "Binary representation: " << decimalToBinary(decimal) << endl;

    return 0;
}
