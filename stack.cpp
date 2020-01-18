#include <iostream> 

using namespace std; 

// Class to implement a simple stack data structure with an array implementation
class Stack 
{ 
    public: 
    int array[10]; 
    int size;

    // Default Constructor 
    Stack() 
    {  
        cout << "The Stack has been created" << endl;  
        size = 0;
    } 

    // Method to get stack size
    int Size()
    {
        return size;
    }

    // Method to push integers on to the top of the stack
    void push(int x)
    {
        if(size < 10)
        {
            array[size] = x;
            cout << "Pushed " << x << " to the top of the Stack!" << endl;
            size++;
        }
        else 
        {
            cout << "The Stack is already full!" << endl;
        }
    }

    // Method to pop integers off the top of the stack
    int pop()
    {
        if(size > 0)
        {
            int retVal = array[size-1];
            cout << "Popped " << retVal << " off the top of the Stack!" << endl;
            size--;
            return retVal;
        }
        else 
        {
            cout << "The Stack is empty!" << endl;
            return -1;
        }
    }

    // Method to print the current stack
    void print()
    {
        if(size > 0) 
        {
            cout << "The stack contains: ";
            for(int i = 0; i < size-1; i++)
            {
                cout << array[i] << ", "; 
            }
            cout << array[size-1] << endl;
        }
        else
        {
            cout << "The Stack is empty!" << endl;
        }
    }
}; 

// Test program to demonstrate stack class functionality
int main() { 
    Stack test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.print();
    test.pop();
    test.pop();
    test.print();
    return 0; 
} 