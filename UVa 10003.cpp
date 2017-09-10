//
//  main.cpp
//  043
// UVa 10003
//  Created by Alessandro Solbiati on 07/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cstring>

int A[52],memo[52][52];

int M = 1 << 30;

using namespace std;

int rec(int a, int b){
    if((b-a)==1) return 0;
    if(memo[a][b]!=-1) return memo[a][b];
    int m=M;
    for(int i=a+1;i<b;i++){
        m=min(m, rec(a,i)+rec(i,b));
    }
    return memo[a][b] = m+A[b]-A[a];
}

int main(int argc, const char * argv[]) {
    int l,n;
    while(scanf("%d",&l), l){
        scanf("%d",&n);
        A[0]=0;
        for(int i=1;i<=n;i++) scanf("%d",&A[i]);
        A[n+1]=l;
        memset(memo, -1, sizeof memo);
        printf("The minimum cutting is %d.\n",rec(0,n+1));
    }
}
