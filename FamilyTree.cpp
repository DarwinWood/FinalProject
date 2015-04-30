 #include "FamilyTree.h"

#include <vector>
#include <iostream>



FamilyTree::FamilyTree()
{
    //ctor
    people.resize(20);
}

FamilyTree::~FamilyTree()
{
    //dtor
}
node* FamilyTree::findRelative(std::string name)
{
    for(int i = 0; i < people.size();i++)
    {
        if(people[i] != NULL)
        {
            if(people[i]->name == name)
            {
                return people[i];
            }
        }
    }
    return NULL;
};
void FamilyTree::addRelative()
{
    std::string name;
    std::cout << "Enter Name: " << std::endl;
    getline(std::cin, name);
    std::cin.ignore(0);
    node* person = new node(name);

    if(generations.empty())
    {
        root = person;
        root->generation = 0;
        generations.push_back(root);
    }
    people.push_back(person);

};
void FamilyTree::showGeneration(std::string name)
{
    node *x = findRelative(name);

    node *y = generations[x->generation];
    while(y != NULL)
    {
        std::cout << "Name: " << y->name << std::endl << "Birthday: " << y->birthMonth << "/" << y->birthDay << "/" << y->birthYear << std::endl;
        y = y->sameGeneration;
    }

};
//Still need to sort the people in each generation, much like our alphabetization in the last assignment
void FamilyTree::showChronologically()
{
    for(int i = 0; i < people.size(); i++)
    {
        std::cout << "Name: " << people[i]->name << std::endl;
    }
};
void FamilyTree::showSiblings(node *relative)
{
    node * x = findRelative(relative->name);
    if(x == NULL)
        return;
    for(int i = 0; i < x->siblings.size(); i++)
    {
        std::cout << x->siblings[i]->name << std::endl;
    }
};
void FamilyTree::showParents(node *relative)
{
    node * x = findRelative(relative->name);
    if(x == NULL)
        return;
    for(int i = 0; i < x->parents.size(); i++)
    {
        std::cout << x->parents[i]->name << std::endl;
    }
};
void FamilyTree::showChildren(node *relative)
{
    node * x = findRelative(relative->name);
    if(x == NULL)
        return;
    for(int i = 0; i < x->children.size(); i++)
    {
        std::cout << x->children[i]->name << std::endl;
    }
};
void FamilyTree::showInformation(std::string name)
{

    node * x = findRelative(name);
    if(x == NULL)
        return;
    if(x->birthDay != 0)
        std::cout << "Birthday: " << x->birthMonthInt << "/" << x->birthDay << "/" << x->birthYear << std::endl;
    if(x->occupation.length() != 0)
        std::cout << "Occupation: " << x->occupation << std::endl;
    if(x->location.length() != 0)
        std::cout << "Location: " << x->location << std::endl;
    std::cout<<"Siblings: \n";
    for(int i = 0; i < x->siblings.size(); i++)
        std::cout << x->siblings[i]->name <<std::endl;
    std::cout << "Parents: \n";
    for(int i = 0; i < x->parents.size(); i++)
        std::cout << x->parents[i]->name <<std::endl;
    std::cout << "Children: \n";
    for(int i = 0; i < x->children.size(); i++)
        std::cout << x->children[i]->name <<std::endl;

};
void FamilyTree::addLocation(node* relative, std::string location)
{
    relative->location = location;
}
void FamilyTree::addOccupation(node* relative, std::string occupation)
{
    relative->occupation = occupation;
};
void FamilyTree::addSibling(node* relative, std::string name)
{
    node* y = findRelative(name);
    if(y == NULL)
    {
        std::cout << "Profile not found.  Please make the profile in the main menu before adding connections. " << std::endl;
        return;
    }
    relative->siblings.push_back(y);
};
void FamilyTree::addParent(node* relative, std::string name)
{
    node* y = findRelative(name);
    if(y == NULL)
    {
        std::cout << "Profile not found.  Please make the profile in the main menu before adding connections. " << std::endl;
        return;
    }
    if(y->generation == 0)
    {
        root = relative;
        relative->generation = 0;
        //increment everyone's
        for(int i = 0; i < people.size(); i++)
        {
            for(int j = 0; j < y->siblings.size(); j++)
            {
                bool inSiblings = false;
                if(people[i]->name == y->siblings[j]->name)
                {
                    inSiblings = true;
                }
                if(!inSiblings)
                {
                    people[i]->generation++;
                }
            }
        }
    }
    relative->parents.push_back(y);
};
void FamilyTree::addChild(node* relative, std::string name)
{
    node* y = findRelative(name);
    if(y == NULL)
    {
        std::cout << "Profile not found.  Please make the profile in the main menu before adding connections. " << std::endl;
        return;
    }
    relative->children.push_back(y);
};
void FamilyTree::addBirthday(node* relative, int year, int month, int day)
{
    relative->birthDay = day;
    relative->birthMonthInt = month;
    relative->birthYear = year;
};
