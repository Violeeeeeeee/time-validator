//Vladyslav Humeniuk 1k111



#include <iostream>
#include <limits>
#include <regex>
#include <csignal>
using namespace std;

volatile sig_atomic_t flag = 0;

void signalHandler(int signum) {
    flag = 1;
}

bool beforeOrAfter(string str) {
    int hours, minutes;
    sscanf(str.c_str(), "%d:%d", &hours, &minutes);

    if (hours < 12) {
        return true; // before
    } else {
        return false; // after
    }
}


// Function to validate time in 12/24-hour format
bool isValidTime(string str)
{

	// Regex to check valid time in 12-hour format
	const regex pattern12hour("((([1-9])|(1[0-2])):([0-5])([0-9])(\\s)(A|P)M)");

    // Regex to check valid time in 24-hour format
    const regex pattern24hour("(0[0-9]|[0-9]|1[0-9]|2[0-3]):[0-5][0-9]");

	// If the time in 12/24-hour format
	// is empty return false
	if (str.empty()) 
	{
		return false;
	}
    
	// Return true if the time in 12/24-hour format
	// matched the ReGex
	if (regex_match(str, pattern12hour)) //12-hour format validate before or after noon
	{
        if (str.find("AM") != string::npos) 
        {
            cout << "it`s 12 hour time format, before noon\n";

        }
        else if (str.find("PM") != string::npos)
        {
            cout << "it`s 12 hour time format, after noon\n";
        }
		return true;
	}
    else if (regex_match(str, pattern24hour)) // 24-hour validate before or after noon
    {
        if (str.find("AM") == string::npos || str.find("PM") == string::npos) // validate  time format
        {
            cout << "it`s 24 hour time format" << endl;
            if(beforeOrAfter(str)) {    // use function beforeOrAfter which validate before or after
            cout << "Before noon\n\n";
        } else {
            cout << "After noon\n\n";
        }
        return true; 
        }
    }
    return false;
}

int main()
{
    /*//test work:
    string str1 = "11:00 AM";
    cout << isValidTime(str1) <<endl; //output 1 "before noon"

    string str2 = "11:00 PM";
    cout << isValidTime(str2) <<endl; //output 1 "after noon"

    string str3 = "13:00 AM";
    cout << isValidTime(str3) <<endl; //output 0

    string str4 = "14:59 PM";
    cout << isValidTime(str4) <<endl; //output 0

    string str5 = "11:00";
    cout << isValidTime(str5) <<endl; //output 1 "before noon"

    string str6 = "25:00";
    cout << isValidTime(str6) <<endl; //output 0

    string str7 = "1:00";
    cout << isValidTime(str7) <<endl; //output 1 "before noon"
    
    string str8 = "09:00"; 
    cout << isValidTime(str8) <<endl; //output 1 "before noon"

    string str9 = "1:00 AM";
    cout << isValidTime(str9) <<endl; //output 1 "before noon"

    string str10 = "1:00 PM";
    cout << isValidTime(str10) <<endl; //output 1 "after noon"

    string str11 = "1:61 AM";
    cout << isValidTime(str11) <<endl; //output 0 

    string str12 = "2:60";
    cout << isValidTime(str12) <<endl; //output 0
    */

    signal(SIGINT, signalHandler);
    string str;

    while (!flag) {  //cycle while do not stop if you don`t write q or quit
        cout << "Enter time in format xx:xx AM|PM or xx:xx if you want to write in 24-hour format\n\nif you want quit write q or quit: " << endl;
        getline(cin, str);
        
        if (str == "q" || str == "quit") {
            flag = 1; // exit the program
            cout << "You exited the program." << endl;
            break;
        } else if (!str.empty()) {
            // Process the input
            if (isValidTime(str)) {
                cout << "Do you want to check another time (q to quit or n/next)?\n\n";
                string input;
                getline(cin, input);
                if (input == "q" || input == "quit") {
                    flag = 1;
                    cout << "You exited the program\n\n";
                    break;
                } else if (input == "n" || input == "next") {
                    flag = 0;
                } else {
                    cout << "Invalid input. Try again.\n\n";
                }
            } else {
                cout << "Invalid input. Try again.\n\n";
            }
        }
    }

    return 0;
}

