/*
===== Browser History Management =====

1. Visit Website : take wedsite name
2. Go Back : top--
3. Current Website : top
4. Display Browser History : display()
5. Exit

Enter Your Choice :
*/
#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

string histStack[SIZE];

class BrowserHistory
{

    int lastVisit;
    string website;

public:
    BrowserHistory()
    {

        lastVisit = -1;

    } // end of constructor

    void visitWebsite()
    {

        if (lastVisit == SIZE - 1)
        {

            cout << "You have reached maximum Limit!";
        }
        else
        {

            cout << "Enter the Website URL : ";
            cin >> website;

            lastVisit++;
            histStack[lastVisit] = website;

            cout << "\n " << website << " Opend Successfully!";

        } // end of if-else

    } // end of visitWebsite

    void goBack()
    {

        if (lastVisit == -1)
        {

            cout << "\nYou have not Visited Any website Yet!!";
        }
        else
        {

            lastVisit--;
            cout << "\n " << histStack[lastVisit] << " was Opend Before!";

        } // end of if - else

    } // end of goBack

    void currentWebsite()
    {

        if (lastVisit == -1)
        {

            cout << "\nYou have not Visited Any website Yet!!";
        }
        else
        {

            cout << "\n You are on " << website;

        } // end of if - else

    } // end of currentWebsite

    void display()
    {

        if (lastVisit == -1)
        {

            cout << "\nYou have not Visited Any website Yet!!";
        }
        else
        {

            cout << "BROWSER HISTORY : ";
            for (int i = lastVisit; i >= 0; i--)
            {

                cout << "\n|" << histStack[i] << "|\n";

            } // end of for

        } // end of if - else

    } // end of display
};

int main()
{

    BrowserHistory bh;

    int choice;

    do
    {

        cout << "\n===== Browser History Management =====\n";
        cout << "\n1. Visit Website";
        cout << "\n2. Go Back";
        cout << "\n3. Current Website";
        cout << "\n4. Display Browser History";
        cout << "\n5. Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            bh.visitWebsite();
            break;

        case 2:
            bh.goBack();
            break;

        case 3:
            bh.currentWebsite();
            break;

        case 4:
            bh.display();
            break;

        case 5:
            printf("\nExtiting the Browser...");
            break;

        default:
            printf("\nInvalid Choice!!");

        } // end of switch

    } while (choice != 5);

} // end of main
