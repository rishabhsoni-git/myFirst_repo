#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int size = 3;
    string stuName[size + 5], stuRoll[size + 5], stuEnroll[size + 5]; // TO STORE DATA TEMPERARY & Extra space.
    for(int i=0; i<size; i++)   // TAKE INPUT FROM TERMINAL AND STORE IN ARRAYS
    {
        cout<<"Enter Student Name : ";
        getline(cin,stuName[i]);
        cout<<"\tEnter Student Roll No. : ";
        getline(cin,stuRoll[i]);
        cout<<"\tEnter Student Enrollment No. : ";
        getline(cin,stuEnroll[i]);
    }
    

    fstream file; // File object
    file.open("temp.txt", ios::in | ios::out | ios::app); // Connect file and object
    

    char serial[2]; // To store previous serial no. < string >
    file.seekg(-2,ios::end); // Move input pointer to just before written Serial no
    for(int i=0;i<2;i++) // loop for input
    file.get(serial[i]); // use get to read char by char

    int sr[2]; // store serial no < int >
    for(int i=0;i<2;i++) // Convert character serial into integer serial
    {
        switch (serial[i])
        {
        case '1' : sr[i] = 1;
            break;
        case '2' : sr[i] = 2;
            break;
        case '3' : sr[i] = 3;
            break;
        case '4' : sr[i] = 4;
            break;
        case '5' : sr[i] = 5;
            break;
        case '6' : sr[i] = 6;
            break;
        case '7' : sr[i] = 7;
            break;
        case '8' : sr[i] = 8;
            break;
        case '9' : sr[i] = 9;
            break;
        case '0' : sr[i] = 0;
            break;
        default: sr[i] = 0;
            break;
        }
    }
    int srNo = (sr[0]*10 + sr[1]);

    file.seekp(-2,ios::end);  // Move output pointer before mention serial no to automatic delete them
    file << "\n";
    for(int i=0; i<size; i++, srNo++)  // WRITE DATA IN A FILE
    {
        file.width(2);
        file<<srNo<<','<<stuName[i]<<','<<stuRoll[i]<<','<<stuEnroll[i]<<endl;
    }

    file.width(2); // this store last serial no.
    file << srNo;

    file.close();
    return 0;
}