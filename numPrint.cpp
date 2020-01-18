#include <iostream>
#include <sstream>
#include "numPrint.hpp"

// Main function with that takes a user suplied commandline integer
// and it is converted to the english spelled out equivalent
int main(int argc, char** argv) 
{
    // Declaring Variables 
    int number, count, remainder, placeVal;
    string strNum;

    // Getting command line number
    strNum = argv[1];

    // Calculating values
    count = strNum.size() / 3;
    placeVal = count;
    remainder = strNum.size() - (count * 3);

    // Parsing if place value is less than 3 and calling the printing function
    if(remainder > 0)
    {
        placeVal++;
        // Call to the print numbers function
        printNumbers(strNum.substr(0, remainder), placeVal);
        placeVal--;
    }

    // Loop to go through number and print out the sub sections
    for(int i = 0; i < count; i++)
    {
        // Call to the print numbers function
        printNumbers(strNum.substr((i*3 + remainder), 3), placeVal);
        placeVal--;
    }

    // Printing a newline
    cout << endl;
    return 0;
}

// Declaring function to print out value to ostream
void printNumbers(string numStr, int placeVal)
{   
    // Declaring neccesary variable for function 
    stringstream ss;
    int number, number2;
    bool printed = false;

    // Converting the number string to an integer
    ss << numStr;
    ss >> number;

    // Case for if the value is in the hundreds place
    if(number > 99)
    {
        // Printing out the hundreths place
        cout << onesMap[numStr[0]] << " Hundred";
        
        // Converting tens and ones numString to integer
        ss.clear();
        ss << numStr.substr(1,2);        
        ss >> number2;

        // Logic to print the rest of the number
        // Case for if the 2 Least Significant Digits are in the 10's 
        if(number2 >= 10 && number2 <= 19)
        {
            printed = true;
            cout << " " << tensMap[numStr.substr(1,2)];
        }
        // Case for if the 2 Least Significant Digits are in the 20's or beyond
        else if(number2 >= 20)
        {
            printed = true;
            cout << " " << higherMap[numStr[1]];
            
            if(numStr[2] != '0')
            {
                cout << " " << onesMap[numStr[2]];
                printed = true;
            }
        }
        // Case for if the remainder of the number is only in the ones place
        else 
        {
            if(numStr[2] != '0')
            {
                cout << " " << onesMap[numStr[2]];
                printed = true;
            }
        }
    }
    // Logic for if the number is in the 10's place
    else if(number > 9)
    {
        printed = true;
        // Case for if the number is in the 10's 
        if(number >= 10 && number <= 19)
        {
            cout << tensMap[numStr];
        }
        // Case for if the number is in the 20's or beyond
        else if(number >= 20)
        {
            cout << higherMap[numStr[0]] << " " << onesMap[numStr[1]];
        }
    }
    // Case for if the number is only in the ones place
    else 
    {
        printed = true;
        cout << onesMap[numStr[0]];
    }

    // Formatting logic
    if(number != 0)
    {
        cout << " " << placeMap[placeVal]; 
    }

    if(placeVal > 1 && printed == true)
    {
        cout << " ";
    }
}
