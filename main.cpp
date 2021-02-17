#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

string name[50];
string phoneNo[50];
string mobileNo[50];
string faxNo[50];
string email[50];
string address[50];
int counter = -1;

int validateContact(string tmpName)
{
    for(int i=0; i<=counter; i++)
    {
        if( name[i] == tmpName)
        {
            return 0;
        }
    }
    return 1;
}

void addContact()
{
    ofstream fout("phone-list.txt",fout.out | fout.app);

    string tmpName = "";
    cout<<"Enter Name : ";
    cin>>tmpName;
    if( validateContact(tmpName) == 1)
    {
        counter++;
        name[counter] = tmpName;
        fout<<"name: "+tmpName<<endl;
    }
    else
    {
        cout<<endl<<"Contact Already Exist with this Name"<<endl;
        return;
    }
    cout<<"Enter Phone No : ";
    cin>>phoneNo[counter];
    fout<<"number: "<<phoneNo[counter]<<endl;
    cout<<"Enter Mobile No : ";
    cin>>mobileNo[counter];
    fout<<"mobileNo: "<<mobileNo[counter]<<endl;
    cout<<"Enter Fax No : ";
    cin>>faxNo[counter];
    fout<<"faxNo: "<<faxNo[counter]<<endl;
    cout<<"Enter Email No : ";
    cin>>email[counter];
    fout<<"email: "<<email[counter]<<endl;
    cout<<"Enter Address No : ";
    cin>>address[counter];
    fout<<"address: "<<address[counter]<<endl;
    fout<<"----"<<endl;
}
void print(int tmpCounter)
{
    if( name[tmpCounter] == "")
        return;
    if( counter > -1 )
    {
        cout<<"Name : "<<name[tmpCounter]<<endl;
        cout<<"Phone No : "<<phoneNo[tmpCounter]<<endl;
        cout<<"Mobile No : "<<mobileNo[tmpCounter]<<endl;
        cout<<"Fax No : "<<faxNo[tmpCounter]<<endl;
        cout<<"Email : "<<email[tmpCounter]<<endl;
        cout<<"Address : "<<address[tmpCounter]<<endl<<endl;
        cout<<"Press any key to view next / continue..."<<endl<<endl;
        getch();
    }


}
void printAll()
{
    if( counter > -1)
    {
        for(int i=0; i<counter; i++)
        {
            print(i);
        }
    }
}

void updateContact( int tmpCounter )
{
    string tmpName = "";
    cout<<"Enter Name : ";
    cin>>tmpName;
    if( validateContact(tmpName) )
    {
        name[tmpCounter] = tmpName;
    }
    else
    {
        cout<<endl<<"Contact Already Exist with this Name"<<endl;
        return;
    }
    cout<<"Enter Phone No : ";
    cin>>phoneNo[tmpCounter];
    cout<<"Enter Mobile No : ";
    cin>>mobileNo[tmpCounter];
    cout<<"Enter Fax No : ";
    cin>>faxNo[tmpCounter];
    cout<<"Enter Email No : ";
    cin>>email[tmpCounter];
    cout<<"Enter Address No : ";
    cin>>address[tmpCounter];
}
void deleteContact(int tmpCounter)
{
    name[tmpCounter] = "";
    phoneNo[tmpCounter] = "";
    mobileNo[tmpCounter] = "";
    faxNo[tmpCounter] = "";
    email[tmpCounter] = "";
    address[tmpCounter] = "";
}
int findCounter()
{
    if( counter < 0)
        return -1;

    string tmpName;
    cout<<"Enter Name ";
    cin>>tmpName;
    for(int i=0; i<=counter; i++)
    {
        if( name[i] == tmpName)
        {
            return i;
        }
    }
    return 1;
}

void fetchDataFromFile()
{
    ifstream fin("phone-list.txt");
    string lazimsiz, _name,_mobile, _phone, _fax, _email, _address;
    int index=0;
        fin>>lazimsiz;
        fin>>_name;
        fin>>lazimsiz;
        fin>>_phone;
        fin>>lazimsiz;
        fin>>_mobile;
        fin>>lazimsiz;
        fin>>_fax;
        fin>>lazimsiz;
        fin>>_email;
        fin>>lazimsiz;
        fin>>_address;
        if(lazimsiz=="----")
        {
            name[index]=_name;
            phoneNo[index]=_phone;
            mobileNo[index]=_mobile;
            faxNo[index]=_fax;
            email[index]=_email;
            address[index]=_address;
            index++;
    }
}

int main()
{
    for(int i=0; i<3; i++)
    {
        cout<<name[i]<<endl;
    }
    char op;
    do
    {
        cout<<"1. Add Contact"<<endl;
        cout<<"2. List Contacts"<<endl;
        cout<<"3. Search Contact"<<endl;
        cout<<"4. Update Contact"<<endl;
        cout<<"5. Delete Contact"<<endl;
        cout<<"6. Fetch Contacts"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter Option (1-7): ";
        cin>>op;

        switch(op)
        {
        case '1':
        {
            addContact();
            cout<<"Contact added succesfully..."<<endl;
            cout<<"Press any key to continue";
            getch();
            break;
        }
        case '2':
        {
            printAll();
            break;
        }
        case '3':
        {
            int tmpCounter = findCounter();
            if(tmpCounter > -1 )
            {
                print(tmpCounter);
            }
            break;
        }

        case '4':
        {

            int tmpCounter = findCounter();
            if( tmpCounter > -1)
            {
                updateContact(tmpCounter);
            }
            break;
        }

        case '5':
        {

            int tmpCounter = findCounter();
            if( tmpCounter > -1 )
            {
                deleteContact(tmpCounter);
            }
            break;
        }
        case '6':
        {
           fetchDataFromFile();
        }
        case '7':
        {

            continue;
            break;
        }

        }
    }
    while(op != '6');

    return 0;

}
