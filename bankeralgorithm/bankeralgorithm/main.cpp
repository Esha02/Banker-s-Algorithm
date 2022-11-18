#include <iostream>

//banker algorithm implementation in void function
void banker(int n, int m, int alloc[][3], int avail[3], int need[][3]){
    int i, j, k;
    int f[n], ans[n], ind = 0;
    //initially all process are not finished
    for (k = 0; k < n; k++){
        f[k] = 0;
    }

    //count of finished process
    int needCount = 0;
    while (needCount < n){
        //traverse all process
        for (i = 0; i < n; ++i) {
            //if process is not finished
            if (f[i] == 0) {
                //check if process can be finished
                int flag = 0;
                for (j = 0; j < m; ++j) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                //if process can be finished
                if (flag == 0) {
                    //add process to safe sequence
                    //move allocation resources to available
                    for (k = 0; k < m; ++k) {
                        avail[k] += alloc[i][k];
                    }
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
        needCount++;
    }
    int flag = 1;
    for (i = 0; i < n; ++i) {
        if (f[i] == 0) {
            flag = 0;
            std::cout << "System is not in safe state" << std::endl;
            break;
        }
    }

    if (flag == 1){
        std::cout << "System is in safe state" << std::endl;
        std::cout << "Safe sequence is: ";
        for (i = 0; i < n - 1; ++i) {
            std::cout << "P" << ans[i] << " -> ";
        }
        std::cout << "P" << ans[n - 1] << std::endl;
    }
}



int main() {
    int n, m, i, j;
    n = 5; // Number of processes
    m = 3; // Number of resources
    //read from input.txt
    //next number of processes line contains allocation matrix
    //next number of processes line contains max matrix
    //next line contains available resources
    //read
    int alloc[n][3];
    int max[n][3];
    int avail[3];
    int need[n][3];

    //read from input.txt
    FILE *fp;
    fp = fopen("../input.txt", "r");

    //reading allocation matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            fscanf (fp, "%d", &alloc[i][j]);
        }
    }

    //reading max matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            fscanf (fp, "%d", &max[i][j]);
        }
    }

    //reading available resources
    for (i = 0; i < m; i++){
        fscanf (fp, "%d", &avail[i]);
    }

    //calculate need matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    //call banker algorithm
    banker(n, m, alloc, avail, need);

    return 0;
}
