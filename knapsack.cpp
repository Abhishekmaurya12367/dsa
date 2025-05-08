/* Bhavik Agarwal (bhavik_2001) */
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a[1] > b[1]; 
}

int main(){
    int n,truckSize;
    cin >> n >> truckSize;

    vector<vector<int>> boxTypes(n);

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        boxTypes[i].push_back(a);
        boxTypes[i].push_back(b);
    }

    int ans = 0;
    sort(boxTypes.begin(), boxTypes.end(), comp);

    for(int i = 0;i<n;i++){
        if(truckSize < boxTypes[i][0]){
            ans += truckSize * boxTypes[i][1];
            break;
        }
        else{
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
    }

    cout << ans << endl;
    
}