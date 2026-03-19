#include <iostream>
#include <fstream>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temperature;
};


// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord records[],  int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord records[], int size);
TemperatureRecord findMin(const TemperatureRecord records[], int size);
TemperatureRecord findMax(const TemperatureRecord records[], int size);
double findAverage(const TemperatureRecord records[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord records[MAX_DAYS];
    
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(records, size);

    // TODO: Step 4 - Print the temperatures
    cout << "Record of Temperatures: " << endl;
    printTemperatures(records, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    TemperatureRecord minRec = findMin(records, size);
    TemperatureRecord maxRec = findMax(records, size);
    double average = findAverage(records, size);
    cout << "Results:" << endl;
    cout << "Minimum Temperature: " << minRec.temperature << " (Day: " << minRec.day << ")" << endl;
    cout << "Maximum Temperature: " << maxRec.temperature << " (Day: " << maxRec.day << ")" << endl;
    cout << "Average Temperature: " << average << endl;

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord records[], int& size) {

    ifstream infile("temps.txt");

    if (!infile) {
        cout << "Error: Cannot open file" << endl;
        return;
    }
    size = 0;
    while (infile >> records[size].day >> records[size].temperature) {
        size++;
        if (size >= MAX_DAYS) {
            break;
        }
    }
    infile.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord records[], int size) {
    int i;
    cout << "Day\tTemperature" << endl;
    for (i = 0; i < size; i++) {
        cout << records[i].day << "\t" << records[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord records[], int size) {
    TemperatureRecord minRec = records[0];
    int i;
    for (i = 1; i < size; i++) {
        if (records[i].temperature < minRec.temperature) {
            minRec = records[i];
        }
    }
    return minRec;
}

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord records[], int size) {
    TemperatureRecord maxRec = records[0];
    int i;
    for (i = 1; i < size; i++) {
        if (records[i].temperature > maxRec.temperature) {
            maxRec = records[i];
        }
    }
    return maxRec;
}

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord records[], int size) {
    double sum = 0.0;
    double avg;
    int i;
    for (i = 0; i < size; i++) {
        sum = sum + records[i].temperature;
    }
    avg = sum / size;
    return avg;
}
