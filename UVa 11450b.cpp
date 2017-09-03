//
//  main.cpp
//  030
//
//  Created by Alessandro Solbiati on 02/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int TC,M,C,prices[20][20],memo[201][20],inf=10000000;

int shop(int money,int g){
    
    if(money<0) return -inf;
    if(g==C) return M-money;
    if(memo[money][g]){
        return memo[money][g];
    }
    int ans = -1;
    for(int j=1;j<=prices[g][0];j++)
        ans = max(ans,shop(money - prices[g][j],g+1));
    return memo[money][g] = ans;
    
}

int main(int argc, const char * argv[]) {
    scanf("%d",&TC);
    while(TC--){
        memset(memo,0,sizeof(memo));
        memset(prices,0,sizeof(prices));
        scanf("%d %d",&M,&C);
        for(int i=0;i<C;i++){
            scanf("%d",&prices[i][0]);
            for(int j=1;j<=prices[i][0];j++) scanf("%d",&prices[i][j]);
        }
        int score = shop(M,0);
        if(score<0) printf("no solution\n");
        else printf("%d\n",score);
    }
}

