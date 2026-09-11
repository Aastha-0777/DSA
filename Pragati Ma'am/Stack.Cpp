#include <iostream>
using namespace std;
#define SIZE 5
int stack[SIZE];

/*
===== Browser History Management =====

1. Visit Website : take wedsite name
2. Go Back : top--
3. Current Website : top
4. Display Browser History : display()
5. Exit

Enter Your Choice :
*/

class Stack
{

    int top;
    int data;

public:
    Stack()
    {

        top = -1;

    } // end of default constructor

    void push()
    {

        if (top == SIZE - 1)
        {

            cout << "\nThe Stack is Overflowed!!";
        }
        else
        {

            cout << "Enter the Value : ";
            cin >> data;
            top++;
            stack[top] = data;
            cout << "Value Added Successfully!!";

        } // end of if-else

    } // end of push

    void pop()
    {

        if (top == -1)
        {

            cout << "The Stack is Empty!!";
        }
        else
        {

            cout << stack[top] << " Poped!!";
            top--;

        } // end of if-else

    } // end of pop

    void peek()
    {

        if (top == -1)
        {

            cout << "The Stack is Empty!!";
        }
        else
        {

            cout << "Found " << stack[top] << " on the Top of the Stack!!";

        } // end of if-else

    } // end of peek

    void display()
    {

        if (top == -1)
        {

            cout << "The Stack is Empty!!";
        }
        else
        {

            cout << "STACK : ";
            for (int i = top; i >= 0; i--)
            {

                cout << "\n| " << stack[i] << " |\n";

            } // end of for

        } // end of if-else

    } // end of display

}; // end of class

int main()
{

    Stack s;
    int choice;

    do
    {

        cout << "\n------------------- STACK MENU -------------------";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter From the above Choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "\nExtiting the Program...";
            break;

        default:
            cout << "\nInvalide Choice!!";

        } // end of switch

    } while (choice != 5);

} // end of main
