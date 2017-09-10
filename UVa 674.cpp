//
//  main.cpp
//  050
//
//  Created by Alessandro Solbiati on 10/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int V,n=5,C[]={50,25,10,5,1};

int memo[6][7490];

int rec(int t, int v){
    if(!v) return 1;
    if(v<0) return 0;
    if(t==n) return 0;
    if(memo[t][v]!=-1) return memo[t][v];
    return memo[t][v] = rec(t+1,v) + rec(t,v-C[t]);
}

int main(){
    memset(memo, -1, sizeof memo);
    while(scanf("%d",&V)!=EOF) printf("%d\n",rec(0,V));
}
