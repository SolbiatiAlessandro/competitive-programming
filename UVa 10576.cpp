//
//  main.cpp
//  020
//
//  Created by Alessandro Solbiati on 24/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

int s,d,year[12],up,down,flag;

bool valid(int m, int change){
    if(m<4) return 1;
    else if(m>=4 && m<12){
        int sum=change;
        for(int i=m-1;i>m-5;i--) sum+=year[i];
        if(sum<0) return 1;
        else return 0;
    }
    else return 0;
}

void rec(int m){
    if(m==12 && flag){
        int sum=0;
        for (int i=0; i<12; i++)
            sum += year[i];
        if(sum>0) std::cout << sum << "\n";
        else std::cout << "Deficit\n";
        flag=0;
    }
    else{
        if(valid(m,s)){
            year[m]=s;
            up++;
            rec(m+1);
            up--;
        }
        if(valid(m,-d)){
            year[m]=-d;
            down++;
            rec(m+1);
            down--;
        }
    }
}

int main(int argc, const char * argv[]) {
    while (scanf("%d %d",&s,&d)==2) {
        flag=1;
        rec(0);
    }
}
