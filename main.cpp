#include <iostream>
#include "FamilyTree.h"
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    FamilyTree Tree = FamilyTree();
    bool quit = false;
    cout << "WELCOME TO THE FAMILY TREE GENERATOR" << endl;
    cout << endl;

    while(!quit)
    {
        cout << "\t\tMain Menu" << endl;
        cout << "1. Add a Relative!" << endl;
        cout << "2. See a Relative's Information!" << endl;
        cout << "3. Edit a Relative's Information!" << endl;
        cout << "4. Show All Relatives!" << endl;
        cout << "5. Quit" << endl;

        string menuInput;
        getline(cin, menuInput);
        if(menuInput == "1")
        {
            Tree.addRelative();
        }
        if(menuInput == "2")
        {
            std::string name2;
            std::cout << "What is the relative's name (capitalize first letter)? "<< std::endl;
            getline(std::cin, name2);
            Tree.showInformation(name2);
        }
        if(menuInput == "3")
        {
            bool edit = true;
            string relativeName;
            cout << "What relative profile would you like to add information to? " << endl;
            getline(cin,relativeName);
            cout << relativeName << endl;
            if(Tree.findRelative(relativeName) == NULL)
            {
                cout << "Profile not found.  Try making one with that name first." << endl;
            }
            else
            {
                while(edit)
                {
                    cout << "\t\tWould you like to:" << endl;
                    cout << "1. Change their Location?" << endl;
                    cout << "2. Change their Occupation?" << endl;
                    cout << "3. Add Their Birthday?" << endl;
                    cout << "4. Add a Child?" << endl;
                    cout << "5. Add a Parent?" << endl;
                    cout << "6. Add a Sibling?" << endl;
                    cout << "7. Go Back" << endl;
                    string secondInput;
                    getline(cin, secondInput);
                    if(secondInput == "1")
                    {
                        string location;
                        cout << "Where are they currently living? " << endl;
                        getline(cin,location);
                        Tree.addLocation(Tree.findRelative(relativeName),location);
                    }
                    if(secondInput == "2")
                    {
                        string occupation;
                        cout << "What is their current occupation? " << endl;
                        getline(cin,occupation);
                        Tree.addOccupation(Tree.findRelative(relativeName),occupation);
                    }
                    if(secondInput == "3")
                    {
                        string year;
                        string month;
                        string day;
                        cout << "What year? " <<endl;
                        getline(cin, year);
                        cout << "Month (by number, not string)? " << endl;
                        getline (cin, month);
                        cout << "Day? " << endl;
                        getline(cin, day);
                        Tree.addBirthday(Tree.findRelative(relativeName),atoi(year.c_str()),atoi(month.c_str()),atoi(day.c_str()) );
                    }
                    if(secondInput == "4")
                    {
                        string childName;
                        cout << "Who is their child? " << endl;
                        getline(cin,childName);
                        Tree.addChild(Tree.findRelative(relativeName),childName);
                    }
                    if(secondInput == "5")
                    {
                        string parentName;
                        cout << "Who is their parent? " << endl;
                        getline(cin,parentName);
                        Tree.addParent(Tree.findRelative(relativeName),parentName);
                    }
                    if(secondInput == "6")
                    {
                        string siblingName;
                        cout << "Who is their sibling? " << endl;
                        getline(cin,siblingName);
                        Tree.addSibling(Tree.findRelative(relativeName),siblingName);
                    }
                    if(secondInput == "7")
                    {
                        edit = false;
                    }

                }
            }
        }
        if(menuInput == "4")
        {
            Tree.showChronologically();
        }
        if(menuInput == "5")
        {
            quit = true;
        }


    }
    return 0;
}
