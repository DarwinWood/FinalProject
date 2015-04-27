#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <vector>
#include <string>

struct node
{
    std::string name;
    std::string occupation;
    std::string location;
    int generation;
    std::vector<node*> siblings;
    std::vector<node*> parents;
    std::vector<node*> children;
    node* sameGeneration;
    int birthDay;
    int birthMonth;
    int birthYear;
    node(){};
    node(std::string add_name)
    {
        name = add_name;
        generation = 0;
    }

};

class FamilyTree
{
    public:
        FamilyTree();
        virtual ~FamilyTree();
        void addRelative();
        node* findRelative(std::string name);
        void showGeneration(std::string name);
        void showChronologically();
        void showSiblings(node *relative);
        void showParents(node *relative);
        void showChildren(node *relative);
        void showInformation(std::string name2);
        void addLocation(node* relative, std::string location);
        void addOccupation(node* relative, std::string occupation);
        void addSibling(node* relative, std::string name);
        void addParent(node* relative, std::string name);
        void addChild(node* relative, std::string name);
        void addBirthday(node* relative, int year, int month, int day);
    protected:
    private:
        std::vector<node*> people;
        std::vector<node*> generations;
        node* root;
};

#endif // FAMILYTREE_H
