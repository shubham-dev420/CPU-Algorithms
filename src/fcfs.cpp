#include<iostream>
using namespace std;

struct Process
{
    int pid, at, bt, ct, tat, wt;
};

void find_ct(Process proc[], int n) {
    proc[0].ct = proc[0].bt;
    for(int i = 1; i < n; i++) {
        proc[i].ct = proc[i-1].ct + proc[i].bt;
    }
}

void find_tat(Process proc[], int n) {
    for(int i = 0; i < n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}

void find_wt(Process proc[], int n) {
    proc[0].wt = 0;
    for(int i = 1; i < n; i++) {
        proc[i].wt = proc[i].tat - proc[i].bt;
    }
}

void find_FCFS(Process proc[], int n) {
    find_ct(proc, n);
    find_tat(proc, n);
    find_wt(proc, n);
}

void print_FCFS(Process proc[], int n) {
    cout << "FCFS SCHEDULING......" << endl;
    cout << "pid\tat\tbt\tct\ttat\twt" << endl;
    for(int i = 0; i < n; i++) {
        cout <<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<< endl;
    }
}
int main() {
    int n = 5;
    Process proc[n] = {{1,0,5}, {2,1,3}, {3,2,2}, {4,3,4}, {5,4,1}};
    find_FCFS(proc, n);
    print_FCFS(proc, n);

    return 0;
}
