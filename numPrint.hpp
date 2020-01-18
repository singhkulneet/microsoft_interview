#include <string>
#include <map>

using namespace std;

// Header file for the numPrint Program
// Function prototype for the printNumbers() function
void printNumbers(string, int);

// Dictionary to map number charecters to the spelled out strings
map<char, string> onesMap = {
    {'1', "One"},
    {'2', "Two"},
    {'3', "Three"},
    {'4', "Four"},
    {'5', "Five"},
    {'6', "Six"},
    {'7', "Seven"},
    {'8', "Eight"},
    {'9', "Nine"}
};

// Dictionary to map 10's place to the spelled out string
map<string, string> tensMap = {
    {"10", "Ten"},
    {"11", "Eleven"},
    {"12", "Twelve"},
    {"13", "Thirteen"},
    {"14", "Fourteen"},
    {"15", "Fifteen"},
    {"16", "Sixteen"},
    {"17", "Seventeen"},
    {"18", "Eighteen"},
    {"19", "Nineteen"}
};

// Dictionary to match the 20's place and beyond to its spelled out equivalent
map<char, string> higherMap = {
    {'2', "Twenty"},
    {'3', "Thirty"},
    {'4', "Fourty"},
    {'5', "Fifty"},
    {'6', "Sixty"},
    {'7', "Seventy"},
    {'8', "Eighty"},
    {'9', "Ninety"}
};

// Dictionary to match place value to its suffix
map<int, string> placeMap = {
    {2, "Thousand"},
    {3, "Million"},
    {4, "Billion"},
    {5, "Trillion"}
};