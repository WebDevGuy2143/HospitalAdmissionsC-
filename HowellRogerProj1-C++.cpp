/******************************************************************************
Gene Howell
October 16th, 2020 
COP2224 C++ Programming
Project 1 - Hospital Admissions
*******************************************************************************/

#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>

using namespace std; // use std namespace

// Declare Function prototypes
double inputValidate(double);
char userChoice(char);
double calculateTotalCharges(double, double);
double calculateTotalCharges(double, double, double, double);
void displayMenu();
void receiveCalculateDisplay();
double writeToFileOpt1(double, double, double, double);
double writeToFileOpt2(double, double, double);
void displayOutputOpt1(double, double, double, double);
void displayOutputOpt2(double, double, double);

// main 
int main() {
    displayMenu();
    receiveCalculateDisplay();
    return 0;
}


// Choose I or O to proceed to the next step 
char userChoice(char letter) {
    cin >> letter;
    while (!((letter == 'I') || (letter == 'O'))) {
        cout << "ERROR: enter only the letters I or O: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> letter;
    }
    return letter;
}

// Validation 
double inputValidate(double num) {
    while(!(cin >> num) || num < 0) {
        cout << "Error. Number must not be " << "0 or greater:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

// function to calculate total charges by adding vars med_charges and services_charge to give a sum
double calculateTotalCharges(double med_charges, double services_charge) {
    return med_charges + services_charge;
}

// function to calculate the total charges by multiplying days_spent and daily_rate, then adding med_charges and services_charge 
double calculateTotalCharges(double days_spent, double daily_rate, double med_charges, double services_charge) {
    return (days_spent * daily_rate) + med_charges + services_charge;
}


// Show menu options
void displayMenu() {
    cout << "Welcome to ACME hospital. Please follow our instructions below for further processing\n"
         << "Were you admitted as an in-patient or an out-patient? " << endl
         << "Enter (I) for in-patient or (O) for out-patient" << endl;
}

// function to gather and display data
void receiveCalculateDisplay() {
    char user_choice;
    double days_spent, daily_rate, med_charges, services_charge, total_charges;

    user_choice = userChoice(user_choice);

    if (user_choice == 'I' || user_choice == 'i') {
        cout << "Number of days spent in the hospital: ";
        days_spent = inputValidate(days_spent);

        cout << "Daily rate: $";
        daily_rate = inputValidate(daily_rate);

        cout << "Hospital medication charges: $";
        med_charges = inputValidate(med_charges);

        cout << "Charges for hospital services (i.e lab tests, medication, etc.): $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(days_spent, daily_rate, med_charges, services_charge);
        writeToFileOpt1(days_spent, services_charge, med_charges, total_charges);
        displayOutputOpt1(days_spent, services_charge, med_charges, total_charges);
    }
    else if(user_choice == 'o' || user_choice == 'O') {
        cout << "Hospital medication charges: $";
        med_charges = inputValidate(med_charges);

        cout << "Charges for hospital services (i.e lab tests, medication, etc.): $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(med_charges, services_charge);
        writeToFileOpt2(med_charges, services_charge, total_charges);
        displayOutputOpt2(services_charge, med_charges, total_charges);
    }
}

// function to write gathered data to file for in-patients
double writeToFileOpt1(double days_spent, double services_charge, double med_charges, double total_charges) {
    ofstream outputFile;
    outputFile.open("HowellRogerHospAdm.txt");

    if(outputFile.fail()) {
        cout << "Failed to open file. Program ended." << endl;
        exit(EXIT_SUCCESS);
    }
    else {
        outputFile  << "**************************************************************" << endl
                    << " ACME Hospital Billing Statement for in-patient: Roger Howell" << endl
                    << "**************************************************************" << endl
                    << setprecision(2) << fixed
                    << " Room Charges: " << setw(38) << "$" << setw(8) << days_spent << endl
                    << " Lab & Services: " << setw(36) << "$" << setw(8) << services_charge << endl
                    << " Medication: " << setw(40) << "$" << setw(8) << med_charges << endl
                    << " Total Charges: " << setw(37) << "$" << setw(8) << total_charges << endl
                    << "**************************************************************" << endl;

        outputFile.close();
        return total_charges;
    }
}

// function to write gathered data to file for out-patients
double writeToFileOpt2(double services_charge, double med_charges, double total_charges) {
    ofstream outputFile;
    outputFile.open("HowellRogerHospAdm.txt");

    if(outputFile.fail()) {
        cout << "Failed to open file. Program ended." << endl;
        exit(EXIT_SUCCESS);
    }
    else {
        outputFile  << "***************************************************************" << endl
                    << " ACME Hospital Billing Statement for out-patient: Roger Howell" << endl
                    << "***************************************************************" << endl
                    << setprecision(2) << fixed
                    << " Lab & Services: " << setw(37) << "$" << setw(8) << services_charge << endl
                    << " Medication: " << setw(41) << "$" << setw(8) << med_charges << endl
                    << " Total Charges: " << setw(38) << "$" << setw(8) << total_charges << endl
                    << "***************************************************************" << endl;

        outputFile.close();
        return total_charges;
    }
}

// display outro message for in-patients to the console
void displayOutputOpt1(double days_spent, double services_charge, double med_charges, double total_charges) {
    cout    << "\nThank you, Roger! Your report has been created and written to an external file for your insurance needs." << endl
            << endl 
            << "Below is the outputed data we've gathered and sent to your external file: " << endl
            << endl
            << "**************************************************************" << endl
            << " ACME Hospital Billing Statement for in-patient: Roger Howell" << endl
            << "**************************************************************" << endl
            << setprecision(2) << fixed
            << " Room Charges: " << setw(38) << "$" << setw(8) << days_spent << endl
            << " Lab & Services: " << setw(36) << "$" << setw(8) << services_charge << endl
            << " Medication: " << setw(40) << "$" << setw(8) << med_charges << endl
            << " Total Charges: " << setw(37) << "$" << setw(8) << total_charges << endl
            << "**************************************************************" << endl
            << "\nThank you for choosing ACME Hospital for all your medical needs!" << endl
            << "Have a wonderful day!" << endl
            << "Goodbye!" << endl;
}

// display outro message for out-patients to the console
void displayOutputOpt2(double services_charge, double med_charges, double total_charges) {
    cout    << "\nThank you, Roger! Your report has been created and written to an external file for your insurance needs." << endl
            << endl 
            << "Below is the outputed data we've gathered and sent to your external file: " << endl
            << endl
            << "***************************************************************" << endl
            << " ACME Hospital Billing Statement for out-patient: Roger Howell" << endl
            << "***************************************************************" << endl
            << setprecision(2) << fixed
            << " Lab & Services: " << setw(37) << "$" << setw(8) << services_charge << endl
            << " Medication: " << setw(41) << "$" << setw(8) << med_charges << endl
            << " Total Charges: " << setw(38) << "$" << setw(8) << total_charges << endl
            << "***************************************************************" << endl
            << "\nThank you for choosing ACME Hospital for all your medical needs!" << endl
            << "Have a wonderful day!" << endl
            << "Goodbye!" << endl;
}
