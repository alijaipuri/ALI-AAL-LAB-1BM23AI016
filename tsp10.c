#include <stdio.h>
#include <limits.h>

#define N 6  

int dist[N][N] = {
    {0, 10, 15, 20, 40, 30},
    {10, 0, 35, 25, 10, 15},
    {15, 35, 0, 30,15, 10},
    {20, 25, 30, 0, 30, 25},
    {10,30,30, 25,0, 10},
    {5,10,20,15,25,0}
	};
int dp[1 << N][N];

void initDP() {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
}

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;  
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {  
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);  
            ans = (ans < newAns) ? ans : newAns;  
        }
    }
    dp[mask][pos] = ans;  
    return ans;
}

int main() {
    initDP(); 
    printf("The minimum cost is: %d\n", tsp(1, 0)); 
    return 0;
}
/*Output
The minimum cost is: 85*/
