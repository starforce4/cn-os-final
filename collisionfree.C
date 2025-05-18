#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#define N 5 
void passToken(int nodes[], int currentHolder) {
    printf("Node %d has the token.\n", currentHolder + 1);
    printf("Node %d is sending data...\n", currentHolder + 1);
    sleep(1);
    printf("Node %d has finished sending data.\n", currentHolder + 1);
    printf("Passing token to Node %d...\n\n", (currentHolder + 1) % N + 1);
}
int main() {
    int nodes[N];
    for (int i = 0; i < N; i++) {
        nodes[i] = i + 1;  
    }
    printf("Starting Token Ring Network with %d nodes...\n\n", N);
    int currentHolder = 0;
    for (int i = 0; i < 2 * N; i++) {  
        passToken(nodes, currentHolder);
        currentHolder = (currentHolder + 1) % N;
    }
    printf("Token passing completed.\n");
    return 0;
}
