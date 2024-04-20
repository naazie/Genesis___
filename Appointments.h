#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

struct Appointment {
    public:
    string patient_name;
    int age;
    string phone_number;
    string preferred_time;
    string preferred_date;
};

 void book_appointment() {
    Appointment appointment;
    cout << "Enter patient's name: ";
    getline(cin, appointment.patient_name);
    cout << "Enter patient's age: ";
    cin >> appointment.age;
    cin.ignore(); 
    cout << "Enter patient's phone number: ";
    getline(cin, appointment.phone_number);
    cout << "Enter preferred time: ";
    getline(cin, appointment.preferred_time);
    cout << "Enter preferred date (YYYY-MM-DD): ";
    getline(cin, appointment.preferred_date);

    // Displaying Entered Information
    cout << "\nPlease confirm the entered information:\n";
    cout << "Patient's Name: " << appointment.patient_name << endl;
    cout << "Age: " << appointment.age << endl;
    cout << "Phone Number: " << appointment.phone_number << endl;
    cout << "Preferred Time: " << appointment.preferred_time << endl;
    cout << "Preferred Date: " << appointment.preferred_date << endl;

    // Confirmation
    char confirm;
    cout << "\nIs the entered information correct? (Y/N): ";
    cin >> confirm;
    if (confirm=='N' || confirm == 'n') {
        cout << "Please re-enter the information.\n";
        book_appointment();
    }
    

    // Write the appointment details to the file
    ofstream appo("appointments.txt", ios::app);
    if ( appo.is_open() ) 
    {
        appo << "Patient Name: " << appointment.patient_name << endl;
        appo << "Age: " << appointment.age << endl;
        appo << "Phone Number: " << appointment.phone_number << endl;
        appo << "Preferred Time: " << appointment.preferred_time << endl;
        appo << "Preferred Date: " << appointment.preferred_date << endl << endl;

        cout << "Appointment booked successfully!\n";
        appo.close();
    }
    else {
        cerr<<"Unable to open file for writing." <<endl;
    }
}

void cancelAllAppointments() {
    string confirmation;
    cout << "Are you sure you want to cancel all appointments? (yes/no): ";
    cin >> confirmation;

    if (confirmation =="yes" || confirmation=="YES") {
        ofstream appo("appointments.txt", ofstream::out | ofstream::trunc);//Truncating a file means to reduce its size to zero bytes
        if (appo.is_open()) {                              // ofstream::out:It is typically used when you want to write data to a file.
            appo.close();
            cout << "All appointments canceled successfully!" << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    } else {
        cout << "Operation canceled. No appointments were deleted." << endl;
    }
}

void DisplaytoDoc()
    {
        string l;
        ifstream obj;
        obj.open("appointments.txt");
        while (getline(obj,l))
        {
            cout << l << endl;
        }
        obj.close();
    }
