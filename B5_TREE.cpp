#include<iostream>
using namespace std;
#define size 20

struct node
{
    char name[10];
    struct node* child[size];
};

class GT
{
    public:
    node* root;
    
    int i, j, k;
    int tchapters;
    int sections;
    int subsections;
    
    GT()
    {
        root = NULL;
    }

    node* create()
    {
        root = new node();

        if (root != NULL)
        {
            cout << "\nEnter the name of BOOK: ";
            cin >> root->name;
            
            cout << "\nEnter number of chapters: ";
            cin >> tchapters;

            for (i = 0; i < tchapters; i++)
            {
                root->child[i] = new node();  
                
                cout << "\nEnter name of chapter " << i+1 << ": ";
                cin >> root->child[i]->name;
                
                cout << "Enter number of sections in chapter " << i+1 << ": ";
                cin >> sections;

                for (j = 0; j < sections; j++)
                {
                    root->child[i]->child[j] = new node();  

                    cout << "Enter name of section " << j+1 << " in chapter " << i+1 << ": ";
                    cin >> root->child[i]->child[j]->name;
                    
                    cout << "Enter number of subsections in section " << j+1 << ": ";
                    cin >> subsections;

                    for (k = 0; k < subsections; k++)
                    {
                        root->child[i]->child[j]->child[k] = new node();  

                        cout << "Enter name of subsection " << k+1 << " in section " << j+1 << ": ";
                        cin >> root->child[i]->child[j]->child[k]->name;
                    }
                }
            }
        }

        return root;
    }

    void display(node* r1)
    {
        if (r1 != NULL)
        {
            cout << "   \nBOOK HIERARCHY: " << endl;
            cout << "   NAME OF BOOK IS: " << r1->name << endl;

            for (i = 0; i < tchapters; i++)
            {
                if (r1->child[i] != NULL)
                {
                    cout << "   \nChapter " << i+1 << ": " << r1->child[i]->name << endl;

                    for (j = 0; j < sections; j++)
                    {
                    
                        if (r1->child[i]->child[j] != NULL)
                        {
                            cout << "   Section " << j+1 << ": " << r1->child[i]->child[j]->name << endl;

                            for (k = 0; k < subsections; k++)
                            {
                            
                                if (r1->child[i]->child[j]->child[k] != NULL)
                                {
                                    cout << "   Subsection " << k+1 << ": " << r1->child[i]->child[j]->child[k]->name << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            cout << "TREE IS EMPTY" << endl;
        }
    }
};

int main()
{
    GT obj;
    node* r2 = NULL;
    int choice;

    do
    {
        cout << "\n1.CREATE TREE \n2.DISPLAY \n3.EXIT " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                r2 = obj.create();
                break;

            case 2:
                obj.display(r2);
                break;

            case 3:
                cout << "EXITING...." << endl;
                return 0;

            default:
                cout << "Enter valid choice!!" << endl;
        }
    }while(choice!=3);

    return 0;
}

