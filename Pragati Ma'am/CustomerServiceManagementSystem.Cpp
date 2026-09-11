/*
    Customer Service Management System

    Add Customer (Queue – Enqueue)0
    Serve Customer (Queue – Dequeue + Push to Stack)
    View Waiting Customers (Queue)
    View Recently Served Customers (Stack)
    Sort Served Customer Records (Bubble Sort)
    Exit

*/

#include <iostream>
#define MAX 100

using namespace std;

string servedCustStack[MAX];
string waitingCustQueue[MAX];
static int servedCustCounter = -1;  // top
static int waitingCustCounter = -1; // rear

int front = -1;

class Customer
{

private:
    int id;
    string name;
    string serviceProductName;
    float price;

public:
    void addCustomer(int id, string name, string serviceProductName, float price)
    {

        if (waitingCustCounter == MAX - 1)
        {

            cout << endl
                 << "The Service Queue is Full!!";
        }
        else
        {

            waitingCustCounter++;
            waitingCustQueue[waitingCustCounter] = name;

            if (front == -1)
            {

                front = 0;

            } // end of if

            cout << endl
                 << "Customer Added Successfully!!";

        } // end of if-else

    } // end of addCustomer

    void serveCustomer()
    {

        if (front == -1)
        {

            cout << endl
                 << "The Waiting Queue is Completed!!";
        }
        else if (front == waitingCustCounter)
        {

            cout << endl
                 << waitingCustQueue[front] << "'s Trun!!";
            if (servedCustCounter == MAX - 1)
            {

                cout << endl
                     << "The Served Stack is Full!!";
            }
            else
            {

                servedCustCounter++;
                servedCustStack[servedCustCounter] = waitingCustQueue[front];

            } // end of inner if-else
            front = -1;
            waitingCustCounter = -1;
        }
        else
        {

            cout << endl
                 << waitingCustQueue[front] << "'s Trun!!";
            if (servedCustCounter == MAX - 1)
            {

                cout << endl
                     << "The Served Stack is Full!!";
            }
            else
            {

                servedCustCounter++;
                servedCustStack[servedCustCounter] = waitingCustQueue[front];

            } // end of inner if-else
            front++;

        } // end of if-else ladder

    } // end of serveCustomer

    void viewWaitingCust()
    {

        if (front == -1)
        {

            cout << endl
                 << "The Waiting Queue is Completed!!";
        }
        else
        {

            cout << endl
                 << "Waiting Queue : ";
            for (int i = front; i <= waitingCustCounter; i++)
            {

                cout << waitingCustQueue[i] << " ";

            } // end of for

        } // end of if-else

    } // end of viewWaitingCust

    void viewRecentlyServedCust()
    {

        if (servedCustCounter == -1)
        {

            cout << endl
                 << "No Coustomer is Served Yet!!";
        }
        else
        {

            cout << endl
                 << "Served Customer : ";
            for (int i = 0; i <= servedCustCounter; i++)
            {

                cout << endl
                     << servedCustStack[i];

            } // end of for

        } // end of if-else

    } // end of viewRecentlyServedCust

    void sortServedCustomer()
    {

        string temp;

        for (int i = 0; i <= servedCustCounter; i++)
        {

            for (int j = i + 1; j <= servedCustCounter; j++)
            {

                if (servedCustStack[i] > servedCustStack[j])
                {

                    temp = servedCustStack[i];
                    servedCustStack[i] = servedCustStack[j];
                    servedCustStack[j] = temp;

                } // end of if

            } // end of inner for

        } // end of outer for

        cout << endl
             << "Served Customer Sorted On Name : ";

        for (int i = 0; i <= servedCustCounter; i++)
        {

            cout << servedCustStack[i] << " ";

        } // end of for

    } // end of sortServedCustomer

};

int main()
{

    int choice;

    int custId;
    string custName, prodName;
    float servPrice;

    Customer customer;

    do
    {

        cout << endl
             << "----------------------- CUSTOMER SERVICE MANAGEMENT SYSTEM -----------------------";
        cout << endl
             << "1. Add Customer";
        cout << endl
             << "2. Serve Customer";
        cout << endl
             << "3. View Waiting Customers";
        cout << endl
             << "4. View Recently Served Customers";
        cout << endl
             << "5. Sort Served Customer Records";
        cout << endl
             << "6. Exit";
        cout << endl
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {

            fflush(stdin);
            cout << "Enter the Customer ID : ";
            cin >> custId;
            cout << "Enter the Customer Name : ";
            cin >> custName;
            cout << "Enter the Product Name : ";
            cin >> prodName;
            cout << "Enter the Service Price : ";
            cin >> servPrice;

            customer.addCustomer(custId, custName, prodName, servPrice);
        }
        break;

        case 2:
        {

            customer.serveCustomer();
        }
        break;

        case 3:
        {

            customer.viewWaitingCust();
        }
        break;

        case 4:
        {

            customer.viewRecentlyServedCust();
        }
        break;

        case 5:
        {

            customer.sortServedCustomer();
        }
        break;

        case 6:
        {

            cout << endl
                 << "Exiting the Customer Service Management System..." << endl;

        }
        break;

        default:
            cout << endl
                 << "Invalid Choice!!" << endl;

        } // end of switch-case

    } while (choice != 6); // end of do-while

    return 0;

} // end of main