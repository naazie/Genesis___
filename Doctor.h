#include <bits/stdc++.h>
#include "Appointments.h"

using namespace std;


class Doctor
{
    private: 
        int scan(int id)
        {
            int id1;
            ifstream fin;
            int r=0;

            int index = 0;
            fin.open("uniqueid.txt");
            while(fin >> id1)
            {
                if(id1 == id){
                    r=1;
                    break;
                    
                }
                index++;
            }
            fin.close();

            if(r == 0)
                r = -1;
            else
                r = index;

            return r;
        }
        // void addHistory(int index)
        // {
        //     string addmed;
        //     cout << "Enter Medical Data to be added\n";
        //     cin.ignore();
        //     getline(cin,addmed);
        //     vector<string> data;
        //     ifstream fin;
        //     fin.open("medical_records.txt");
        //     string d;
        //     while (getline(fin, d)) {
        //         data.push_back(d);
        //     }
        //     fin.close();

        //     if (index >= 0 && index <= data.size()) {
        //         data.insert(data.begin() + index, addmed);
        //     }

        //     ofstream fout("medical_records.txt");
        //     fout.open("medical_records.txt",ios::app);
        //     for (const auto& d : data) {
        //         fout << d << endl;
        //     }
        //     fout.close();

        //     cout << "Data added " << endl;
        // }

        
        
        void viewHistory(int index)
        {
            ifstream fin;
            string rec;
            fin.open("medical_records.txt");
            int ind = 0;
            while(ind < index && getline(fin,rec))
                ind++;
            if(ind == index && getline(fin,rec))
            {
                cout << rec << endl;
            }
            cout << ind << " " <<index<<endl;

            fin.close();
        }
        public:

        void themain()
        {
            int index;
            cout << "Welcome to MedPlus Doctor!\n";
            int ch;
            cout << "MENU:- \n1. Enter EPIC ID\n2. View Appointments \n";
            
            cin >> ch;
            switch(ch)
            {
                case 1: 
                    index = scanningprocess();
                    choose(index);
                    break;
                case 2: 
                    appointments();
                    break;
                default: cout << "Invalid Input\n";


            }
            
        }
        int scanningprocess()
        {
            int id;
            int index;
            cout << "Enter EPIC ID:\n";
            cin >> id;
            int r = scan(id);
            if( r == -1){
                cout << "ID not found, please Enter correct EPIC ID\n";
                scanningprocess();
                choose(index);
            }
            else 
                index = r;
            return r;
        }
        void choose(int index)
        {
            int ch;
            cout<< "1. View Medical Records\n";
            cout << "2. Add to Medical Records\n";
            cin>>ch;
            switch(ch)
            {
                case 1: viewHistory(index);
                    break;
                // case 2: addHistory(index);
                //     break;        
            }
        }
        void appointments()
        {
            void DisplaytoDoc();
        }  
};