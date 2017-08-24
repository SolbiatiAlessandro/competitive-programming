//
//  main.cpp
//  019
//
//  Created by Alessandro Solbiati on 24/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

int N,n,tracks[20],tape[20],btape[20],maxsum=0;

int valid(int c, int t){
    int sum=t;
    for(int prev=c-1; prev>=0; prev--){
        sum = sum + tape[prev];
    }
    if(sum<=N && c<n) return sum;
    else return 0;
}

void rec(int c, int ii){
    int t,foo;
    for(int i=ii; i<n; i++){
        t= tracks[i];
        foo= valid(c,t);
        if(foo){
            tape[c]=t;
            if(foo>maxsum){
                maxsum=foo;
                int j=0;
                for(;j<c+1;j++) btape[j]=tape[j];
                for(;j<n;j++) btape[j] = 0;
            }
            rec(c+1,i+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    while(scanf("%d %d",&N,&n)==2){
        maxsum=0;
        memset(tape, 0, sizeof(tape));
        memset(btape, 0, sizeof(btape));
        memset(tracks, 0, sizeof(tracks));
        for(int i=0;i<n;i++) std::cin >> tracks[i];
        rec(0,0);
        for(int i=0;btape[i]!=0;i++) std::cout << btape[i] << " ";
        std::cout << "sum:" << maxsum <<"\n";
        
    }
}
