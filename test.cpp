#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

vector<string> timestamps;

void logTimestamp(const string timestamp){
    timestamps.push_back(timestamp);
}

int main(){
    time_t timestamp;
    time(&timestamp);
    string ts_str = ctime(&timestamp); // Converts to string

    logTimestamp(ts_str);
}