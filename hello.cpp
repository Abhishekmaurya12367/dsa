#include<bits/stdc++.h>
using namespace std;

struct Box {
    int numberOfBoxes;
    int numberOfUnitsPerBox;
};

bool compare(Box b1, Box b2) {
    return b1.numberOfUnitsPerBox > b2.numberOfUnitsPerBox; 
}

int maximumUnits(vector<Box>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), compare);
    
    int totalUnits = 0;
    
    for (auto& box : boxTypes) {
        if (truckSize == 0) break; 
        
        if (box.numberOfBoxes < truckSize) {
            totalUnits += box.numberOfBoxes * box.numberOfUnitsPerBox; 
            truckSize -= box.numberOfBoxes;  
        }
        else {
            totalUnits += truckSize * box.numberOfUnitsPerBox; 
            break;  
        }
    }
    
    return totalUnits;
}

int main() {
    vector<Box> boxTypes = {{1, 3}, {2, 2}, {3, 1}};  
    int truckSize = 4;  
    
    cout << maximumUnits(boxTypes, truckSize) << endl;  
    
    return 0;
}
