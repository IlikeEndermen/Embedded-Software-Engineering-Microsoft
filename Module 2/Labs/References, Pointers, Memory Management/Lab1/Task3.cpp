#include <iostream>
#include <string>
using namespace std;
struct Config {
    string mode;
    double threshold;
    bool enabled;
};
// Function using reference - always valid, cannot be reassigned
void updateConfigByReference(Config& config, const string& newMode) {
    config.mode = newMode;
    config.enabled = true;
    cout << "Updated config via reference: " << config.mode << endl;
}
// Function using pointer - can be null, can be reassigned
void updateConfigByPointer(Config* config, const string& newMode) {
    if (config != nullptr) { // Safety check required
        config->mode = newMode;
        config->enabled = true;
        cout << "Updated config via pointer: " << config->mode << endl;
    } else {
        cout << "Cannot update: null pointer received" << endl;
    }
}
int main() {
    Config systemConfig = {"default", 50.0, false};
    Config backupConfig = {"backup", 75.0, false};    
    cout << "=== Reference Behavior ===" << endl;
    Config& configRef = systemConfig;
    cout << "Initial reference points to: " << configRef.mode << endl;    
    updateConfigByReference(configRef, "production");    
    // References cannot be reassigned to different objects
    // configRef = backupConfig;  // This modifies systemConfig, doesn't reassign reference
    configRef = backupConfig; // This copies backupConfig data into systemConfig
    cout << "After 'reassignment': systemConfig.mode = " << systemConfig.mode << endl;
    cout << "backupConfig.mode still = " << backupConfig.mode << endl;    
    cout << "\n=== Pointer Behavior ===" << endl;
    Config* configPtr = &systemConfig;
    cout << "Initial pointer points to: " << configPtr->mode << endl;    
    updateConfigByPointer(configPtr, "testing");    
    // Pointers can be reassigned to different objects
    configPtr = &backupConfig; // Now points to different object
    cout << "After reassignment, pointer points to: " << configPtr->mode << endl;    
    updateConfigByPointer(configPtr, "staging");
    cout << "systemConfig.mode = " << systemConfig.mode << endl;
    cout << "backupConfig.mode = " << backupConfig.mode << endl;    
    // Demonstrate null pointer handling
    cout << "\n=== Null Pointer Safety ===" << endl;
    Config* nullPtr = nullptr;
    updateConfigByPointer(nullPtr, "invalid"); // Safe handling of null    
    return 0;
}