//
//  main.cpp
//  018
//
//  Created by Alessandro Solbiati on 24/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int row[8],a,b,lcount;

bool valid_pos(int r,int c){
    for(int prev=c-1; prev>=0; prev--)
        if(row[prev]==r || abs(row[prev]-r) == abs(prev-c))
            return false;
    return true;
}

void rec(int c){
    
    if(c==8 && row[b]==a){
        printf("%2d      %d",++lcount,row[0]+1);
        for (int i=1; i<8; i++) {
            printf(" %d", row[i]+1);
        }
        printf("\n");
    }
    
    else
        for (int r=0; r<8; r++)
            if(valid_pos(r,c)){
                row[c]=r;
                rec(c+1);
            }
}

int main(int argc, const char * argv[]) {
    
    int TC;
    scanf("%d",&TC);
    while(TC--){
        scanf(" %d %d",&a,&b);
        a--;
        b--;
        lcount=0;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        rec(0);
        if(TC) printf("\n");
    }
}
