#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "sinlist.h"
#define WINWIDTH 113
#define WINHEIGHT 15
using namespace std;

void filler();
void liner();
void welcome();
void exitscreen();

char pname[30]; //Product name
int pid;    //Product id
int price;    //Product price
int tquant; //Total products purchased from wholesale
int aquant; //How many are available in stock
int rack;

char filename[50];

class store
{
    LinkedList obj;
    int t;
    public:
        store()
        {
            t = 0;
            obj.ReadFromFile(obj);
        }
        void add()
        {
        	system("CLS");
        	cout<<"\n\t\t\t[press enter after each details]";
            cout << "\nEnter Product name" << endl;
            cin >> pname;
            
            cout << "\nEnter Product id" << endl;
            cin >> pid;
            
            cout << "\nEnter Price" << endl;
            cin >> price;
            
            cout << "\nEnter Total Qty" << endl;
            cin >> tquant;
            
            cout << "\nEnter Available Qty" << endl;
            cin >> aquant;
            
            cout << "\nEnter Rack No" << endl;
            cin >> rack;
            
            //cout << "\nEnter Product name, Product id, Price, Total Qty, Available Qty, Rack No" << endl;
            //cin >> pname >> pid >> price >> tquant >> aquant >> rack;
            
			obj.add_end(pname,pid,price,tquant,aquant,rack);
        }
        void display()
        {
            obj.display();
        }
        int getrecs()
        {
            return obj.recsnum();
        }
        void modify()
        {
            obj.modify();
        }
        void PrintBill();
        void deleteproduct()
        {
        	system("CLS");
            char name[30];
            cout << "\n\nEnter name of product : ";
            cin >> name;
            obj.delete_node(name);
        }
        void SearchProduct()
        {
            obj.Search();
        }
        void totalprinter();
        ~store()
        {
            cout << "Number of records = " << obj.getcount() << endl;
            obj.SaveToFile();
            exitscreen();
        }
};

void store::PrintBill()
{
	system("CLS");
    int choice;
    char sname[] = {"Product Name"};
    char name[30];
    int quantity;
    cout << "\n\nEnter filename for bill with full path and file extension : ";
    cin >> filename;
    FILE *fp;
    fp = fopen(filename,"a");
    for(int i = 0 ; i < 70 ; i++)
    {
        fprintf(fp,"*");
    }
    fprintf(fp,"\n");
//brought to you by code-projects.org
    fprintf(fp,"%-30s\tQty.\tPrice/item\tAmount\n",sname);

    for(int i = 0 ; i < 70 ; i++)
    {
        fprintf(fp,"*");
    }
    fprintf(fp,"\n");
    fclose(fp);
    while(1)
    {
        cout << "\nContinue Purchasing Product ?\n1 = yes , 2 = no" << endl;
        cout << "choice : ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "\nEnter product name and quantity : " << endl;
            cin >> name >> quantity;
            obj.billgen(filename,name,quantity,t);
        }
        else
            break;
    }
    fp = fopen(filename,"app");
}

void store::totalprinter()
{
    FILE *fp;
    fp = fopen(filename,"a");
    fprintf(fp,"\n");
    for(int i = 0 ; i < 70 ; i++)
    {
        fprintf(fp,"*");
    }


    fprintf(fp,"\n");

    for(int i = 0 ; i < 70 ; i++)
    {
        fprintf(fp,"*");
    }
    fprintf(fp,"\n");
    fprintf(fp,"Total = %d\n",t);
    for(int i = 0 ; i < 70 ; i++)
    {
        fprintf(fp,"*");
    }
    fprintf(fp,"\n");
    fclose(fp);
}
int main()
{
    store obj;
    int ch;
    welcome();
    cout << endl << "Press any key to continue" << endl;
    getch();
    while(1)
    {
        system("CLS");
        cout <<"\n\n\t\t\t---------------------------------------------";
        cout << "\n\t\t\tSIMPLE ELECTRONIC STORE MANAGEMENT SYSTEM : \n\t\t\t---------------------------------------------" << endl
            << "\n\t\t\t\t (1) To Add Products" << endl
            << "\t\t\t\t (2) To Display Products" << endl
            << "\t\t\t\t (3) To Modify Products" << endl
            << "\t\t\t\t (4) To Delete Products" << endl
            << "\t\t\t\t (5) To Search Products" << endl
            << "\t\t\t\t (6) To Sell Products" << endl
            << "\t\t\t\t (7) Exit " << endl;
        cout << "\t\t\t Choice : ";
        cin >> ch;
        switch(ch)
        {
            case    1   :   obj.add();
                            break;
            case    2   :   obj.display();
                            getch();
                            break;
            case    3   :   obj.modify();
                            break;
            case    4   :   obj.deleteproduct();
                            getch();
                            break;
            case    5   :   obj.SearchProduct();
                            break;
            case    6   :   obj.PrintBill();
                            obj.totalprinter();
                            getch();

                            break;
            case    7   :   return 0;
        }
    }
    return 0;
}

void filler()
{
    for(int i = 0 ; i < WINWIDTH ; i++)
    {
        cout << "*";
    }
    cout << "\a" << endl;
}

void liner()
{
    for(int i = 0 ; i < WINHEIGHT ; i++)
        cout << endl;
}

void welcome()
{
    liner();
    cout << "Loading..." << endl;
    Sleep(500);
    char msg[] = "WELCOME TO ELECTRONIC STORE MANAGEMENT SYSTEM";
    int len = strlen(msg);
    int x;
    x = (WINWIDTH/2) - (len/2);
    for(int i = 0 ; i < WINWIDTH ; i++)
    {
        printf("%c",177);
        Sleep(55);
    }
    cout << endl;
    system("CLS");
    liner();
    filler();
    cout << setw(len+x) << msg << endl;
    filler();
}

void exitscreen()
{
    system("CLS");
    char msg[] = "Brought To You By code-projects.org";
    int len = strlen(msg);
    int x;
    x = (WINWIDTH/2) - (len/2);
    liner();
    filler();
    cout << setw(len+x) << msg << endl;
    filler();
}
