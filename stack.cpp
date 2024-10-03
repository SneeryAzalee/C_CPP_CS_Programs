/*
 *  Make a program that will do stack operations
 *  when the user input is a prime number.
 *
 *  1. If the input is a prime number, you will then
 *      use that number for two options:
 *
 *          1.1. Push - Add the number to the stack.
 *          1.2. Pop - Remove the previous number from the stack.
 *
 *  2. If the input is not a prime number, you will then
 *      ask for another number.
 */

#include <iostream>

using namespace std;

class Stack
{
    private:

        int *stack;
        int stackSize;
        int top = -1;
        bool exit = false;

    public:

        void printErrors(int input)
        {
            switch(input)
            {
                case 1:
                {
                    cout << "\nERROR:  Not a prime number!\n";
                    break;
                }
                case 2:
                {
                    cout << "\n\nERROR:  Stack is full!\n\n";
                    break;
                }
                case 3:
                {
                    cout << "\n\nERROR:  Stack is empty!\n\n";
                    break;
                }
                case 4:
                {
                    cout << "\n\nERROR:  Invalid option!\n\n";
                    break;
                }
                default:
                {
                    cout << "\nERROR!\n";
                    break;
                }
            }
        }

        void printSuccess(int input)
        {
            switch(input)
            {
                case 1:
                {
                    cout << "\n\nSUCCESS:  Element has been added to the stack.\n\n";
                    break;
                }
                case 2:
                {
                    cout << "\n\nSUCCESS:  An element has been removed from the stack.\n\n";
                    break;
                }
                default:
                {
                    cout << "\n\nSUCCESS!\n\n";
                    break;
                }
            }
        }

        void getStackSize()
        {
            cout << "\nEnter stack size:  ";
            cin >> stackSize;
            stack = new int[stackSize];
        }

        bool getExitStatus()
        {
            return exit;
        }

        bool primeChecker(int input)
        {
            bool isPrime = true;
            for(int i = 2; i < input; i++)
            {
                if(input % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime && input > 1)
            {
                return true;
            }
            return false;
        }

        void displayStack()
        {
            cout << "\n\n[STACK INFO]\n\n";
            for(int i = top; i >= 0; i--)
            {
                cout << (i + 1) << ".  " << stack[i] << endl;
            }
        }

        void displayStackOptions(int input)
        {
            cout << "\n\n[STACK OPTIONS]\n";
            cout << "\nElement:  " << input << "\n";
            cout << "\n1)  Push";
            cout << "\n2)  Pop";
            cout << "\n3)  Exit";
            cout << "\n\n?) >>  ";
        }

        void pushElement(int input)
        {
            if(top < (stackSize - 1))
            {
                stack[++top] = input;
                printSuccess(1);
            }
            else
            {
                printErrors(2);
            }
        }

        void popElement()
        {
            if(top >= 0)
            {
                stack[top--] = NULL;
                printSuccess(2);
            }
            else
            {
                printErrors(3);
            }
        }

        void setExitStatus(bool input)
        {
            exit = input;
        }

        ~Stack()
        {
            delete[] stack;
        }
};

int main()
{
    Stack stack;

    stack.getStackSize();

    do
    {
        int primeInput;
        cout << "\nEnter input:  ";
        cin >> primeInput;

        if(stack.primeChecker(primeInput))
        {
            stack.displayStack();
            int stackInput;
            stack.displayStackOptions(primeInput);
            cin >> stackInput;

            switch(stackInput)
            {
                case 1:
                {
                    stack.pushElement(primeInput);
                    break;
                }
                case 2:
                {
                    stack.popElement();
                    break;
                }
                case 3:
                {
                    stack.setExitStatus(true);
                    break;
                }
                default:
                {
                    stack.printErrors(4);
                    break;
                }
            }
        }
        else
        {
            stack.printErrors(1);
        }

    } while(!stack.getExitStatus());

    return 0;
}