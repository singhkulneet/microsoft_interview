// The purpose of this program is to implement the binary search algorithm
// for a sorted integer array
#include <iostream>

using namespace std;

bool binSearch(int array[], int size, int searchVal)
{
    int low = 0;
    int high = size-1;
    int mid;

    while(low <= high)
    {    
        mid = (low + high)/2;

        if(searchVal == array[mid])
        {
            return true;
        }
        else if(searchVal < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    int array[] = {12, 22, 34, 47, 55, 67, 82, 98};    
    int size = sizeof(array)/sizeof(array[0]);
    int search1 = 82;
    int search2 = 300;
    string resultStr;

    cout << "Given the following array: {";
    for(int i = 0; i < size-1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[size-1] << "}" << endl;
    
    bool result = binSearch(array, size, search1);
    resultStr = result ? "True" : "False";
    cout << "1) The value " << search1 << " was found via binary search? " << resultStr << endl;
    result = binSearch(array, size, search2);
    resultStr = result ? "True" : "False";
    cout << "2) The value " << search2 << " was found via binary search? " << resultStr << endl;
    return 0;
}