
#include <bits/stdc++.h>
#include "Patients.h"
// #include "Appointments.h"
#include "Doctor.h"
using namespace std;


class User
{   
    public:
    string name, contact_number, email, password;

    void getInput(); 
    bool saveToFile(); 
    bool checkIfUserExists(const string& emailToCheck); 
    void userinfo(); 
};

class updateduser:public User {
public:

void updateuserinfo();
void getUserField(int choice);
void updateField(int choice, const string& newValue);
void updateFile();
};

void User::getInput() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Contact Number: ";
        getline(cin, contact_number);
        cout << "Enter Email ID: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);
}

bool User::saveToFile() {
        ofstream file("users.txt", ios::app);
        if (file) {
            file << name << "," << contact_number << "," << email << "," << password << "\n";
            file.close();
            return true;
        }
        return false;
}

bool User::checkIfUserExists(const string& emailToCheck) {
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            int pos = line.find(emailToCheck);
            if (pos != string::npos) {
                return true;
            }
        }
        file.close();
        return false;
} 

void User::userinfo() {
    cout << "Current Information:\n";
    cout << "1. Name: " << name << "\n";
    cout << "2. Contact Number: " << contact_number << "\n";
    cout << "3. Email: " << email << "\n";
    cout << "4. Password: " << password << "\n";
}

void updateduser::updateuserinfo(){
        cout << "What would you like to update (1-4)?: ";
        int choice;
        cin >> choice;
        cin.ignore();

        cout << "Enter new value";
        
        string newValue;
        getline(cin, newValue);
        updateField(choice, newValue);
        // updateFile();
}

void updateduser::updateField(int choice, const string& newValue) 
{

    switch (choice) {
        case 1: name = newValue; break;
        case 2: contact_number = newValue; break;
        case 3: email = newValue; break;
        case 4: password = newValue; break;
    }
}

void signUp() {
    User user;
    user.getInput();

    if (user.checkIfUserExists(user.email)) {
        cout << "User already exists with this email.\n";
        return;
    }

    if (user.saveToFile()) {
        cout << "User registered successfully.\n";
    } else {
        cout << "Failed to save user data.\n";
    }
}

bool loginUser() {
    string email, password;
    cout << "Enter Email ID: ";
    getline(cin, email);
    cout << "Enter Password: ";
    getline(cin, password);

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        size_t posEmail = line.find(email);
        size_t posPassword = line.find(password);
        if (posEmail != string::npos && posPassword != string::npos && posPassword > posEmail) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid email or password.\n";
    return false;
}


void whatUser();
void SignIn_LogIn();
void userpatient();
void userdoctor();

void whatUser()
{
    int choice;
    cout <<"Hello, Welcome to MedPlus"<<endl;
    cout <<"\n";
    cout <<"-------------------------------------------------------------------------------------------"<<endl;
    cout << "Are you a Patient or Doctor?? \nEnter 1 for Patient and 2 for Doctor\n";
    cin >> choice;
    switch(choice)
    {
        case 1:  //patient
            userpatient();
            break;
        case 2: //doctor
            userdoctor();
            
        break;
        default:" Please enter Valid Input";
            whatUser();
    }
}


void userpatient()
{
    Patient p;
    Appointment appointment;
    int choice;
    string id;

     string illness, date;
    string continueInput;

    cout << "\t\t\tWelcome ! Please Signup or Login\n\t\t\t1: Sign Up\n\t\t\t2: Login\n\t\t\tEnter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            signUp();
            break;
        case 2:
            if (loginUser()==false) {
                cout<<"Enter Again"<<endl;
                loginUser();}
            else{
            cout << "Welcome back!\n";
            }
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    do
    {
        cout<<"\n\n\t\t\t\t======================\n";
        cout<<"\t\t\t\tWelcome to MedPlus";
        cout<<"\n\t\t\t\t======================\n";

        cout<<"\t\t\t\t    ::MAIN MENU::\n";
            cout<<"\n\t\t\t\t0. EXIT";
            cout<<"\n\t\t\t\t1. Generate Epic ID";
            cout<<"\n\t\t\t\t2. View Epic ID";
            cout<<"\n\t\t\t\t3. Book New Appointment";
            cout<<"\n\t\t\t\t4. Cancel an Appointment";
            cout<<"\n\t\t\t\t5. Update Personal Information";
            cout<<"\n\t\t\t\t6. View Medical Record";
            cout<<"\n\t\t\t\t7. Add Medical Record";
            cout<<"\n\t\t\t\t8. Log Out";
            
            cout<<"\n\n\t\t\t\tSelect Your Option (0-8): ";
        cin >> choice;
        cin.ignore();

    switch(choice)
    {
            case 0 : cout<<"Exited Succesfully "<<endl;
                break;

            case 1 : system("CLS");
                        cout<<"Your Generated ID is"<<endl;
                        id = p.generateUniqueID();
                        p.setID(id);
                        p.saveIDToFile();
                        cout<<id<<endl;
                        break;

            case 2:  system("CLS");
                        p.getID();  
                        break;   
            
            case 3: system("CLS");
                    book_appointment();
                    break;

            case 4: system("CLS");
                    cancelAllAppointments();        
                    break;
            case 5: system("CLS");
                    if(loginUser())
                    {
                        User user;
                        updateduser newuser;
                        user.userinfo();
                        newuser.updateuserinfo();
                    }
                    break;

           case 6: system("CLS");
           cout << "All recorded medical entries:" << endl;
           p.printRecords();
           break;       

            case 7: system("CLS");
                    
            do {
        cout << "Enter illness: ";
        getline(cin, illness);
        cout << "Enter date (DD/MM/YYYY): ";
        getline(cin, date);

        p.addRecord(illness, date);

        cout << "Do you want to add another record? (yes/no): ";
        getline(cin, continueInput);
        } 
       while (continueInput == "yes" || continueInput == "y");
               p.saveRecordsToFile("medical_records.txt");
               break;        
            case 8: system("CLS");
                    userpatient();
                    break;
            default: cout<<"Invalid Choice"<<endl;        
        }       
    }

    while(choice!=0);
}


void userdoctor()
{
    Doctor d;
    int choice;
    cout << "\t\t\tWelcome ! Please Signup or Login\n\t\t\t1: Sign Up\n\t\t\t2: Login\n\t\t\tEnter your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            signUp();
            break;
        case 2:
            if (loginUser()==false) {
                cout<<"Enter Again"<<endl;
                loginUser();}
            else{
            cout << "Welcome back!\n";
            }
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    // Doctor d;
    d.themain();
}

int main()
{
    whatUser();
    return 0;
}