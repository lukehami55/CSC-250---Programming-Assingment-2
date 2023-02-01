//Luke Hamilton
//2/1/2023
//CSC 250, S03

//Winter Park

//Menu-driven program to store attendance and print attendance for winter park
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_WEEKS = 5;
const int NUM_ACT = 4;

//print menu options for the user
void printWelcome();

//return menu option from user input
int userSelection();

//add enrolling for an activity to a 2D array
void enroll(int menu[][NUM_ACT]);

//calculate total attendance
int calcTotal(int menu[][NUM_ACT], int rows);

//calculate week totals
void calcRowTotal(int menu[][NUM_ACT], int weekTotals[], int rows);

//calculate activity totals
void calcColTotal(int menu[][NUM_ACT], int rows, int actTotals[], int cols);

//print enrollment table
void printEnroll(int menu[][NUM_ACT], int weekTotals[], int rows, int actTotals[], int cols, int total);

//print week values in enrollment table
void printWeek(int week);

int main(){
    //variable and array declarations
    int option, total;
    int menu[NUM_WEEKS][NUM_ACT] = {0};
    int weekTotals[NUM_WEEKS] = {0};
    int actTotals[NUM_ACT] = {0};

    //print menu options
    printWelcome();

    //loop menu options till user exits
    while (option != 3){
        option = userSelection();
        //enroll
        if (option == 1){
            enroll(menu);
        }
        //calc and display enrollment
        if (option == 2){
            total = calcTotal(menu, NUM_WEEKS);
            calcRowTotal(menu, weekTotals, NUM_WEEKS);
            calcColTotal(menu, NUM_WEEKS, actTotals, NUM_ACT);
            printEnroll(menu, weekTotals, NUM_WEEKS, actTotals, NUM_ACT, total);
        }
    }
    return 0;
}

void printWelcome(){
    cout << "Welcome to Winter Fun!" << endl;
    cout << "     1. Enroll in an activity" << endl;
    cout << "     2. Print the current enrollment" << endl;
    cout << "     3. Exit" << endl;
}

int userSelection(){
    int option;
    cout <<  "Please select an option: ";
    cin >> option;
    return option;
}

void enroll(int menu[][NUM_ACT]){
    int amount, activity, day;
    cout << "Enter how many people: ";
    cin >> amount;
    cout << "Activity" << endl;
    cout << "     1. Skiing" << endl;
    cout << "     2. Curling" << endl;
    cout << "     3. Ice Skating" << endl;
    cout << "     4. Sledding" << endl;
    cout << "Enter an activity: ";
    cin >> activity;
    cout << "Days" << endl;
    cout << "     1. Saturday 1" << endl;
    cout << "     2. Saturday 2" << endl;
    cout << "     3. Saturday 3" << endl;
    cout << "     4. Saturday 4" << endl;
    cout << "     5. Saturday 5" << endl;
    cout << "Enter a day: ";
    cin >> day;
    //add amount to pre-existing 2d array
    menu[day-1][activity-1] = menu[day-1][activity-1]+amount;
    return;
}

int calcTotal(int menu[][NUM_ACT], int rows){
    int total = 0;
    for (int r=0; r < rows; r++){
        for (int c=0; c < NUM_ACT; c++){
            total = total + menu[r][c];
        }
    }
    return total;
}

void calcRowTotal(int menu[][NUM_ACT], int weekTotals[], int rows){
    for (int r=0; r < rows; r++){
        weekTotals[r]=0;
        for (int c=0; c < NUM_ACT; c++){
            weekTotals[r] += menu[r][c];
        }
    }
    return;
}

void calcColTotal(int menu[][NUM_ACT], int rows, int actTotals[], int cols){
    for (int c=0; c < cols; c++){
        actTotals[c]=0;
        for (int r=0; r < rows; r++){
            actTotals[c] += menu[r][c];
        }
    }
    return;
}

void printEnroll(int menu[][NUM_ACT], int weekTotals[], int rows, int actTotals[], int cols, int total){
    cout << "                          Skiing        Curling       Ice Skating     Sledding       Week Totals" << endl;
    for (int r=0; r < rows; r++){
        printWeek(r);
        for (int c=0; c < NUM_ACT; c++){
            cout << setw(15) << menu[r][c];
        }
        cout << setw(15) << weekTotals[r] << endl;
    }
    cout << "Activity Totals";
    for (int c=0; c < cols; c++)
        cout << setw(15) << actTotals[c];
    cout << setw(15) << total << endl << endl;
    return;
}

void printWeek(int week){
    switch(week){
    case 0: cout << " Saturday 1    ";
            break;
    case 1: cout << " Saturday 2    ";
            break;
    case 2: cout << " Saturday 3    ";
            break;
    case 3: cout << " Saturday 4    ";
            break;
    case 4: cout << " Saturday 5    ";
            break;
    default: cout << " Unknown    ";
    }
    return;
}
