#include <iostream>
using namespace std;

void calculateSJF(int bt[], int n) {
    int wt[n], tat[n], p[n];

    for(int i = 0; i < n; i++)
        p[i] = i + 1;

    // Sort by burst time
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];
    cout << "Enter Burst Time:\n";
    for(int i = 0; i < n; i++)
        cin >> bt[i];

    calculateSJF(bt, n);

    return 0;
}
