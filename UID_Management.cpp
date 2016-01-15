#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <algorithm>

using namespace std;

/* This function is for adding new entries */
void addNewRecord()
{
    ofstream myfile;
    string full_name;
    string passport;
    string aadhar;
    string d_license;
    string voter_id;
    string u_id;

    myfile.open("C:/Users/shubham_soin/Desktop/DataSet.txt", ios::out | ios::app);

    //myfile<<"Full_Name"<<"  "<<"Passport"<<"  "<<"Aadhar_Card"<<"  "<<"Driving_License"<<"  "<<"Voter_Id"<<"  "<<"Unique_Id"<<"\n";

    cout<<"\nPlease enter your full name using underscore as a separator : \n";
    cin>>full_name;
    myfile<<"\n"<<full_name<<"  ";

    cout<<"Please enter your passport number if applicable : \n";
    cin>>passport;
    myfile<<passport<<"  ";

    cout<<"Please enter your aadhar card number if applicable : \n";
    cin>>aadhar;
    myfile<<aadhar<<"  ";

    cout<<"Please enter your driving license number if applicable : \n";
    cin>>d_license;
    myfile<<d_license<<"  ";

    cout<<"Please enter your voter id if applicable : \n";
    cin>>voter_id;
    myfile<<voter_id<<"  ";


    //string testMe = "shubham_soin";
    size_t pos = full_name.find("_");
    size_t pos_2 = full_name.find_last_not_of("_");
    string Tested = full_name.substr(pos);
    std::transform(Tested.begin(), Tested.end(),Tested.begin(), ::toupper);
    string First = full_name.substr(pos_2);
    std::transform(First.begin(), First.end(),First.begin(), ::toupper);
    srand(time(NULL));

    int comp_number = rand() % 1000 + 100;
    stringstream ss;
    ss << comp_number;
    string first_random = ss.str();
    int comp_number_2 = rand() % 9998 + 1;
    stringstream ss_2;
    ss_2 << comp_number_2;
    string second_random = ss_2.str();

    u_id = "UI"+second_random+Tested+first_random+First;
    //cout<<final<<endl;

    cout<<"\n The UID generated for this entry is : \n"<<u_id;
    myfile<<u_id;

    getch();

    myfile.close();

}

/* This function is for searching any entry using UID */
void searchUID()
{
    ifstream fileInput;
    fileInput.open("C:/Users/shubham_soin/Desktop/DataSet.txt");
    string line;
    string search;
    cout<<"Enter The UID You Wanna Search: "<<endl;
    cin>>search;
    string name,id1,id2,id3,id4,id5;

    unsigned int curLine = 0;
    while(getline(fileInput, line))
    {
        curLine++;
        if (line.find(search) != string::npos)
        {
            istringstream data(line);

            if(data>>name>>id1>>id2>>id3>>id4>>id5)
            {
                cout<<" Name :"<<name<<endl;
                cout<<" Passport :"<<id1<<endl;
                cout<<" Addhar Card :"<<id2<<endl;
                cout<<" Driving License :"<<id3<<endl;
                cout<<" Voter :"<<id4<<endl;
                cout<<" Unique Id :"<<id5<<endl;
                //name.replace(name.begin(),name.end(),"Motu_Manny");

            }
            else
            {
                cout<<"\n Wrong Line Format \n";
            }
            cout << "found: " << search << "line: " << curLine << endl;
        }
    }

    fileInput.close();

}

/* This function is used for deleting existing records from the system */
void  deleteRecord()
{

    string line;

    ifstream in("C:/Users/shubham_soin/Desktop/DataSet.txt");
    if(!in.is_open())
    {
        cout << "Input file failed to open\n";
        //return 1;
    }

    ofstream out("C:/Users/shubham_soin/Desktop/outfile.txt");

    string search;
    cout<<"Enter The UID You Wanna Remove From The System: "<<endl;
    cin>>search;
    while(getline(in,line))
    {
        if (line.find(search) != string::npos)
        {
            continue;
        }
        else
        {
            out << line <<"\n";
        }

    }
    in.close();
    out.close();

    remove("C:/Users/shubham_soin/Desktop/DataSet.txt");

    rename("C:/Users/shubham_soin/Desktop/outfile.txt","C:/Users/shubham_soin/Desktop/DataSet.txt");

    cout<<"\n\n  The record is successfully removed from the system \n";

}


/* This function is used for editing the existing records of the system */
void editRecord()
{
    string line;

    ifstream in("C:/Users/shubham_soin/Desktop/DataSet.txt");
    if(!in.is_open())
    {
        cout << "Input file failed to open\n";
        //return 1;
    }

    ofstream out("C:/Users/shubham_soin/Desktop/outfile.txt");

    string search;
    cout<<"Enter The UID You Wanna Edit The Details Of: "<<endl;
    cin>>search;
    while(getline(in,line))
    {
        if (line.find(search) != string::npos)
        {
            continue;
        }
        else
        {
            out << line <<"\n";
        }

    }
    in.close();
    out.close();

    remove("C:/Users/shubham_soin/Desktop/DataSet.txt");

    rename("C:/Users/shubham_soin/Desktop/outfile.txt","C:/Users/shubham_soin/Desktop/DataSet.txt");

    ofstream myfile;
    string full_name,passport,aadhar,d_license,voter_id;

    myfile.open("C:/Users/shubham_soin/Desktop/DataSet.txt", ios::out | ios::app);

    myfile<<"Full_Name"<<"  "<<"Passport"<<"  "<<"Aadhar_Card"<<"  "<<"Driving_License"<<"  "<<"Voter_Id"<<"  "<<"Unique_Id"<<"\n";

    cout<<"\n Please enter your full name using underscore as a separator : \n";
    cin>>full_name;
    myfile<<"\n"<<full_name<<"  ";

    cout<<"Please enter your passport number if applicable : \n";
    cin>>passport;
    myfile<<passport<<"  ";

    cout<<"Please enter your aadhar card number if applicable : \n";
    cin>>aadhar;
    myfile<<aadhar<<"  ";

    cout<<"Please enter your driving license number if applicable : \n";
    cin>>d_license;
    myfile<<d_license<<"  ";

    cout<<"Please enter your voter id if applicable : \n";
    cin>>voter_id;
    myfile<<voter_id<<"  ";

    myfile<<search;

    cout<<"\n The Record Has been edited successfully";

    myfile.close();


}


/* This function is used for displaying all the records of the system */
void displayAllRecords()
{
    string line;
    ifstream fileDisplay("C:/Users/shubham_soin/Desktop/DataSet.txt", ios::out | ios::app);
    while(fileDisplay.good())
    {
        getline(fileDisplay,line);
        cout<<line<<endl;
    }
    getch();
}


/* This is the main function where all the other functions are called from */
int main()
{

    string pass;
    string fileContent;
    cout<<"                         ##*****## ADMIN PANEL ##*****##\n\n";
    cout<<" Enter the admin password: ";
    cin>>pass;

    ifstream forPass("C:/Users/shubham_soin/Desktop/encryptedPass.txt");

    while(forPass >> fileContent)
    {
        if(pass == fileContent)
        {
            while(1)
            {
                //clrscr();
                system("CLS");
                int choice;
                cout<<"\n                #***** UNIQUE IDENTITY MANAGEMENT SYSTEM *****#\n\n\n";
                cout<<"  1. Add New Entry\n\n";
                cout<<"  2. Display All Records\n\n";
                cout<<"  3. Edit A Record\n\n";
                cout<<"  4. Search From UID\n\n";
                cout<<"  5. Delete A Record\n\n";
                cout<<"  6. Exit The Application\n\n\n";

                cout<<"  Choose your choice to proceed: ";
                cin>>choice;

                switch(choice)
                {
                case 1 :
                    addNewRecord();
                    break;

                case 2 : //Display All Records
                    cout<<"\nFull_Name"<<"  "<<"Passport"<<"  "<<"Aadhar_Card"<<"  "<<"Driving_License"<<"  "<<"Voter_Id"<<"  "<<"Unique_Id"<<"\n";
                    displayAllRecords();
                    break;

                case 3 : //edit a record
                    editRecord();
                    break;

                case 4 : //Search from UID
                    searchUID();
                    break;

                case 5 : //Delete Record
                    deleteRecord();
                    break;

                case 6 :
                    cout<<"\n\n";
                    return 0;
                }
            }
        }
        else
        {
            cout<<"ATTENTION : You are not allowed to enter the system Without Admin Rights And Priviledges \n";
        }
    }
    forPass.close();


    return 0;

}
