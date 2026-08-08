#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct DataPoint {
    double value;
    string label;
    int timestamp;
};
// Function using reference for efficient parameter passing
void processDataPoint(DataPoint& data) {
    data.value *= 1.1; // Apply 10% scaling factor
    data.timestamp += 1000; // Update timestamp
    cout << "Processed: " << data.label << " = " << data.value << endl;
}
// Function using const reference for read-only access
void displayDataPoint(const DataPoint& data) {
    cout << "Data: " << data.label << " | Value: " << data.value
        << " | Time: " << data.timestamp << endl;
}
int main() {
    DataPoint sensor1 = {25.5, "Temperature", 1000}; 
    DataPoint sensor2 = {10.0, "Testing", 500};   
    cout << "=== Before Processing ===" << endl;
    displayDataPoint(sensor1);    
    // Create reference to the data point
    DataPoint& sensorRef = sensor1;
    cout << "Reference value: " << sensorRef.value << endl;
    cout << "Original and reference have same address: "
        << (&sensor1 == &sensorRef ? "true" : "false") << endl;    
    processDataPoint(sensorRef);    
    cout << "\n=== After Processing ===" << endl;
    displayDataPoint(sensor1); // Shows modified values    

    sensorRef = sensor2;
    cout << "sensorRef now shows: " << sensorRef.label << " = " << sensorRef.value << endl;
cout << "sensor1 is now: " << sensor1.label << " = " << sensor1.value << endl;
cout << "sensor2 is unchanged: " << sensor2.label << " = " << sensor2.value << endl;
cout << "Address of sensorRef still equals address of sensor1: "
     << (&sensorRef == &sensor1 ? "true" : "false") << endl;
    return 0;
}