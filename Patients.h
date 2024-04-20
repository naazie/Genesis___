#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Patient {
private:
    private:
    struct MedicalRecord {
        string illness;
        string date;
    };
    vector<MedicalRecord> records;  // To store multiple medical records
    string uniqueid;
    

    public:
    void setID(const string &id){
         uniqueid=id;
    }

    void getID() const {
        if(uniqueid.empty())
        cout<<"\n\t\t\t Unique ID is not generated \n"<<endl;
        else
        cout<<"Your Unique ID is :"<<uniqueid<<endl;
            
    }
    string generateUniqueID();

    void saveIDToFile() {
        ofstream file("uniqueid.txt");
        if (file.is_open()) {
            file << uniqueid;
            file.close();
        } else {
            cerr << "Failed to open file." << endl;
        }
    }

    void addRecord(const string& illness, const string& date);
    void printRecords() const;
    void saveRecordsToFile(const string& filename);
    void collectrecord();
};

void Patient::addRecord(const string& illness, const string& date)
{
    records.push_back({illness, date});
}

void Patient::printRecords() const {
        for (const auto& record : records) {
            cout << "Illness: " << record.illness << ", Date: " << record.date << endl;
        }
    }

void Patient::saveRecordsToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& record : records) {
                file << "Illness: " << record.illness << ", Date: " << record.date << endl;
            }
            file.close();
            cout << "Records saved successfully" <<endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }    

string Patient::generateUniqueID() 
{                              // Method to generate a unique 6 digit ID
    string id;
    
    srand((unsigned)time(0) + rand());                   // Ensure more randomness
    
        id = "";
        for (int i = 0; i < 6; ++i) {
            id += '0' + rand() % 10;
        }
    
    return id;
}