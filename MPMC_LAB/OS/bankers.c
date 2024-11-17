#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, p, r, all[10][10], max[10][10], need[10][10], avail[10], safe[10];
    int ind = 0;
    bool check[10];

    printf("Enter the no of processes: ");
    scanf("%d", &p);

    printf("Enter the no of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter the maximum matrix: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources: \n");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    printf("The need matrix is: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - all[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++) {
        check[i] = false;
    }
    // setting all processes to false

    for (i = 0; i < p; i++) {
        for (j = 0; j < p; j++) {
            if (check[j] == false) {
                int c = 0;
                for (int k = 0; k < r; k++) { // k = 0 to number of resources r-1
                    if (need[j][k] > avail[k]) { // compares the resource need of the process and available resource
                        c = 1; // the process cant be done since need is greater
                        break;
                    }
                }
                // compares need and the availability of all resources of the process, c=0 means the
                // process can be done
                if (c == 0) {
                    check[j] = true;
                    safe[ind++] = j; // safe sequence holds the index of the process
                    for (int I = 0; I < r; I++) {
                        avail[I] += all[j][I];
                    }
                }
            }
        }
    }

    printf("The safe sequence is: ");
    for (i = 0; i < ind; i++) {
        printf("P%d ", safe[i] + 1);
    }

    return 0;
}
