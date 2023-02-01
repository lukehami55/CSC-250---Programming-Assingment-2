# Program Design
## Structure Chart
![Chart](https://github.com/lukehami55/CSC-250---Programming-Assingment-2/blob/main/Structure%20Chart.png?raw=true)

## Data Storage in Main
``` cpp
int option; //user inputted option based on menu choice
int total; //total for 2d array
int menu[NUM_WEEKS][NUM_ACT] = {0}; //2d array
int weekTotals[NUM_WEEKS] = {0}; //row totals
int actTotals[NUM_ACT] = {0}; //col totals
```
## Function Design
``` cpp
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
```
## Time Estimates
|  | Estimated Time    | Actual Time    |
| :---:   | :---: | :---: |
| Program Design | 30   | 15   |
| printWelcome | 5   | 5   |
| userSelection | 5   | 5   |
| enroll | 15   | 10   |
| calcTotal | 10   | 5   |
| calcRowTotal | 10   | 5   |
| calcColTotal | 10   | 5   |
| printEnroll | 10   | 15   |
| printWeek | 5   | 5   |
| Program Test | 5   | 5   |
| Total Time | 100   | 70   |
