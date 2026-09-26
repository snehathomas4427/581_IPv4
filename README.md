# IPv4 AI Disclosure Document 
## AI model and version: ChatGPT GPT-5.6
### Date used: 9/24/2026

**Prompts:**
i am creating a parser that extracts IPv4 Addresses from noisy text. all functions will be in a main.cpp file. it should read a line of text and extract a single valid IPv4 address — optionally followed by a port number — embedded anywhere in that text. Only digits, periods (.), and colons (:) are ever part of a valid token; every other character is garbage and is skipped. A candidate token must match the address grammar in full — no partial matches, no truncating to find a valid piece inside a longer run. An address is four octets separated by periods (octet.octet.octet.octet), each octet 1–3 digits, value 0–255. An optional :port may follow the fourth octet: 1–5 digits, value 0–65535. If a colon is present, the port must be fully valid or the entire match — address included — is rejected.

here is what I have so far:
#include <iostream> using namespace std; int extractIPv4(string ip_addr){ return 0; } int main(){ string val = ""; while(val != "END"){ cout << "Enter a string (or 'END' to quit): "; cin >> val; extractIPv4(val); } cout << "Program terminated."; return 0; }

am I on the right track? what are the next steps

-----------------

what's wrong with my main function? It's only reading the first word of the input. What function do I use to read the whole line. 

-----------------

help me write the extractIPv4 function

------------------

an octet should have no leading zero unless the value is exactly 0. include a check for that. also the extractIPv4 should be returning a bool, so string extractIPv4 should actually be bool extractIPv4 and the parameters it takes should be input string, the address, and the port, all sectioned and sent from the main function. 

-------------------

explain the extractIPv4 function line by line so I can best understand

-------------------

extract the inputs so I can create a test file with all these test cases. also create a function in main.cpp that calls the testcases file and runs through them
Enter a string (or 'END' to quit): connecting to 192.168.1.1 now
Extracted IPv4 address: 192.168.1.1 (decimal value: 3232235777, port: none)
Enter a string (or 'END' to quit): server=10.0.0.255:8080end
Extracted IPv4 address: 10.0.0.255 (decimal value: 167772415, port: 8080)
Enter a string (or 'END' to quit): 192a168.1.1.1
Extracted IPv4 address: 168.1.1.1 (decimal value: 2818638081, port: none)
Enter a string (or 'END' to quit): 192.168.1.1.
Invalid input: no valid IPv4 address found
Enter a string (or 'END' to quit): Connection from 192.168.1.1 refused
Extracted IPv4 address: 192.168.1.1 (decimal value: 3232235777, port: none)
Enter a string (or 'END' to quit): 192.168.01.1
Invalid input: no valid IPv4 address found
Enter a string (or 'END' to quit): 1.2.3.4:99999
Invalid input: no valid IPv4 address found
Enter a string (or 'END' to quit): 12.34.56
Invalid input: no valid IPv4 address found
Enter a string (or 'END' to quit): no number here
Invalid input: no valid IPv4 address found
Enter a string (or 'END' to quit): END
Program terminated.

----------------------------------------

add extra test cases so I can best test my program. Include a variety of test cases from normal valid IPv4 addresses to ports and octets outside range, missing octets, extra garbage text, leading zeros, and more.

-----------------------------------------

create a separate function that calls the testcases from test_cases.txt and runs through them in terminal

------------------------------------------

would the the ouptut for this: ello there 145.say 2.2.2 be 'Invalid input: no valid IPv4 address found?'

------------------------------------------

**What the AI generated vs. Student:**
- Initial extractIPv4 implementation: AI generated
- extractIPv4 conditionals (ex: if (str[i] >= '0' && str[i] <= '9'): Student written
- Generated 10 extra cases: AI generated
- main() function: student generated, getline() function correction by AI
- runTestCases(): AI generated for quick testing purposes (without user input)

**Problem(s) found in the AI output**
The initial AI-generated parser accepted an IPv4 address embedded inside a longer numeric token. I discovered this by testing an input containing a valid-looking address followed immediately by another period. The assignment requires the entire candidate token to be valid, so I modified the parser to reject a candidate when a period or colon is directly adjacent to the address in an invalid position.

**Testing and validation**
Asked AI to create variety of test cases for normal valid IPv4 addresses, ports and octets outside range, missing octets, extra garbage text, and more. Test cases are stored in the test_cases.txt file. 

**Modifications made to eh AI code**
- Changed the validation of leading zeros because the initial implementation allowed values such as 01.2.3.4, which violates the specified grammar.

**VERIFICATION STATEMENT:**
I understand all the code I've committed. The code has been tested and works as intended. All bugs in the main and extractIPv4 function were resolved. 
