//
//  main.cpp
//  049
//
//  Created by Alessandro Solbiati on 10/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int T,n,M[101],V[101],memo[10001][101][2];

int rec(int m, int i, int flag){
    if(i==n||m==0) return 0;
    if(memo[m][i][flag]!=-1) return memo[m][i][flag];
    if(T-(m-M[i])>2000 && flag){
        if(m-M[i]<-200) return memo[m][i][flag] = rec(m,i+1,flag);
        return memo[m][i][flag] = max(rec(m,i+1,1),rec(m-M[i]+200,i+1,0)+V[i]);
    }
    if(m-M[i]<0) return memo[m][i][flag] = rec(m,i+1,flag);
    return memo[m][i][flag] = max(rec(m,i+1,flag),rec(m-M[i],i+1,flag)+V[i]);
}

int main(int argc, const char * argv[]) {
    while(scanf("%d",&T)!=EOF){
    
        memset(M, -1, sizeof M);
        memset(V, -1, sizeof M);
        memset(memo, -1, sizeof memo);
        
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d %d",&M[i],&V[i]);
        
        printf("%d\n",rec(T,0,1));
    }
}
