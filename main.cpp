// to run: g++ main.cpp -o hey && ./hey

// all imports were student written
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// extractIPv4 was mostly written by AI
bool extractIPv4(const string& str, unsigned long& outAddress, int& outPort) {
    outAddress = 0;
    outPort = -1;

    for (int i = 0; i < str.length(); i++) {

        // Look for the beginning of a possible IP address
        if (str[i] >= '0' && str[i] <= '9') {

            int octets[4];
            int currentOctet = 0;
            int digitCount = 0;
            bool valid = true;

            // Read the 4 octets
            for (int octet = 0; octet < 4; octet++) {

                currentOctet = 0;
                digitCount = 0;

                // Must start with a digit
                if (i >= str.length() ||
                    str[i] < '0' || str[i] > '9') {
                    valid = false;
                    break;
                }

                // Read digits
                while (i < str.length() &&
                       str[i] >= '0' && str[i] <= '9') {

                    if (digitCount == 3) {
                        valid = false;
                        break;
                    }

                    currentOctet =
                        currentOctet * 10 + (str[i] - '0');

                    digitCount++;
                    i++;
                }

                if (!valid) {
                    break;
                }

                // No leading zeroes
                if (digitCount > 1 &&
                    str[i - digitCount] == '0') {
                    valid = false;
                    break;
                }

                // Must be 0-255
                if (currentOctet > 255) {
                    valid = false;
                    break;
                }

                octets[octet] = currentOctet;

                // First 3 octets need a '.'
                if (octet < 3) {
                    if (i >= str.length() || str[i] != '.') {
                        valid = false;
                        break;
                    }

                    i++; // skip '.'
                }
            }

            if (!valid) {
                continue;
            }

            // Check for optional port
            int port = -1;

            if (i < str.length() && str[i] == ':') {
                i++;

                // Colon must be followed by a digit
                if (i >= str.length() ||
                    str[i] < '0' || str[i] > '9') {
                    continue;
                }

                int portValue = 0;
                int portDigits = 0;
                int portStart = i;

                while (i < str.length() &&
                       str[i] >= '0' && str[i] <= '9') {

                    if (portDigits == 5) {
                        valid = false;
                        break;
                    }

                    portValue =
                        portValue * 10 + (str[i] - '0');

                    portDigits++;
                    i++;
                }

                if (!valid) {
                    continue;
                }

                // No leading zeroes
                if (portDigits > 1 && str[portStart] == '0') {
                    continue;
                }

                // Port must be 0-65535
                if (portValue > 65535) {
                    continue;
                }

                port = portValue;
            }

            // Can't have another '.' or ':' immediately after
            if (i < str.length() &&
                (str[i] == '.' || str[i] == ':')) {
                continue;
            }

            // Convert A.B.C.D into one 32-bit value
            outAddress =
                ((unsigned long)octets[0] << 24) |
                ((unsigned long)octets[1] << 16) |
                ((unsigned long)octets[2] << 8) |
                (unsigned long)octets[3];

            outPort = port;

            return true;
        }
    }

    return false;
}

// the main function was mainly student written 
int main() {
    string val = "";
    while (val != "END") {
        cout << "Enter a string (or 'END' to quit): ";
        getline(cin, val); // fixed by AI. initially did not use getline 

        if (val == "END") {
            break;
        }
        unsigned long address;
        int port;

        if (extractIPv4(val, address, port)) { // lines 171-176 is AI-generated

            unsigned long a = (address >> 24) & 255;
            unsigned long b = (address >> 16) & 255;
            unsigned long c = (address >> 8) & 255;
            unsigned long d = address & 255;

            cout << "Extracted IPv4 address: "
                 << a << "." << b << "." << c << "." << d
                 << " (decimal value: " << address
                 << ", port: ";

            if (port == -1) {
                cout << "none";
            } else {
                cout << port;
            }
            cout << ")" << endl; // added by AI

        } else {
            cout << "Invalid input: no valid IPv4 address found" << endl;
        }
    }
    cout << "Program terminated.";
    return 0;
}

// BELOW was soley for quick testing purposes. The function was written by AI. 
// can uncomment everything below and re-comment the main funciton above to automatically run the test cases. 
// keep the below commented if you want user interaction/user input based test cases.  

// void runTestCases() {
//     ifstream file("test_cases.txt");

//     if (!file) {
//         cout << "Error: could not open test_cases.txt" << endl;
//         return;
//     }

//     string val;

//     while (getline(file, val)) {

//         cout << "Enter a string (or 'END' to quit): " << val << endl;

//         if (val == "END") {
//             cout << "Program terminated." << endl;
//             break;
//         }

//         unsigned long address;
//         int port;

//         if (extractIPv4(val, address, port)) {

//             unsigned long a = (address >> 24) & 255;
//             unsigned long b = (address >> 16) & 255;
//             unsigned long c = (address >> 8) & 255;
//             unsigned long d = address & 255;

//             cout << "Extracted IPv4 address: "
//                  << a << "." << b << "." << c << "." << d
//                  << " (decimal value: " << address
//                  << ", port: ";

//             if (port == -1) {
//                 cout << "none";
//             } else {
//                 cout << port;
//             }

//             cout << ")" << endl;

//         } else {
//             cout << "Invalid input: no valid IPv4 address found" << endl;
//         }
//     }

//     file.close();
// }

// int main() {
//     runTestCases();

//     return 0;
// }