//Jefferson Zheng
//October 15, 2024
//Homework 3

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /*
    //Setup Variables
    ifstream transactions("transactions.txt");
    float balance, change;
    char transactionType;
    
    //Setup Starting Balance
    transactions >> balance;

    //Outputs Table Header
    cout << right << "Type" << setw(10) << "Amount" << setw(20) << "Balance" << endl;

    //Repeat 7 Times
    for(int i = 0; i < 7; i++) {
        //Take the Transaction Type
        transactions >> transactionType;
        //Take the Transaction Amount
        transactions >> change;
        //Different Actions for Different Cases
        switch(transactionType) {
            case 'W':
                balance -= change;
                break;
            case 'D':
                balance += change;
                break;
        }
        //Outputs Data In a Set Format
        setfill(".");
        cout << right << transactionType << setw(13) << fixed << setprecision(2) << change << setw(20) << balance << endl;
    }

    //Outputs Final Balance
    cout << "\nFinal Balance: " << fixed << setprecision(2) << balance;

    //Closes txt File
    transactions.close();
    */

    //Setup Variables
    ifstream transactions("transactions.txt");
    ofstream banknote("banknote.txt");
    float startingBalance, balance, change, transactionsDone, totalDeposits, totalWithdraws;
    char transactionType;

    //Setup Starting Balance
    transactions >> balance;
    startingBalance = balance;

    //Outputs Starting Balance and Table Header
    banknote << "Starting Balance: " << fixed << setprecision(2) << startingBalance << endl << endl;
    setfill(".");
    banknote << right << "Type" << setw(10) << "Amount" << setw(20) << "Balance" << endl;

    //Repeat Until End of File
    while (!transactions.eof()) {
        //Take the Transaction Type
        transactions >> transactionType;
        //Take the Transaction Amount
        transactions >> change;
        //Add 1 to Transactions Done
        transactionsDone++;
        //Different Actions for Different Cases
        switch(transactionType) {
            case 'W':
                balance -= change;
                totalWithdraws += change;
                break;
            case 'D':
                balance += change;
                totalDeposits += change;
                break;
        }
        //Outputs Data In a Set Format
        setfill(".");
        banknote << right << transactionType << setw(13) << fixed << setprecision(2) << change << setw(20) << balance << endl;
    }

    //Final Bank Info
    banknote << "\nTransactions Done: " << transactionsDone << endl;
    banknote << "Total Deposits: " << fixed << setprecision(2) << totalDeposits << endl;
    banknote << "Total Withdraws: " << fixed << setprecision(2) << totalWithdraws << endl;
    banknote << "Final Balance: " << fixed << setprecision(2) << balance << endl;
    
    //Closes txt Files
    transactions.close();
    banknote.close();

    //Exits Successfully
    return 0;
}