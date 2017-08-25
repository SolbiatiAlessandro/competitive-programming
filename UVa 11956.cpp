//
//  main.cpp
//  021
//
//  Created by Alessandro Solbiati on 25/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

int m[256];
int *p; int foo=0;

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void exe(char op){
    if(op=='+') *p = *p+1;
    if(op=='-') *p = *p-1;
    if(op=='>'){
        foo++;
        if(foo>=0 && foo<256) p++;
        if(foo==256){
            p = m;
            foo=0;
        }
    }
    if(op=='<'){
        foo--;
        if(foo>=0 && foo<256) p--;
        if(foo==-1){
            p = m+255;
            foo=255;
        }
    }
}

char hexmap(int n){
    n=abs(n);
    if(n==0) return '0';
    if(n==1) return '1';
    if(n==2) return '2';
    if(n==3) return '3';
    if(n==4) return '4';
    if(n==5) return '5';
    if(n==6) return '6';
    if(n==7) return '7';
    if(n==8) return '8';
    if(n==9) return '9';
    if(n==10) return 'A';
    if(n==11) return 'B';
    if(n==12) return 'C';
    if(n==13) return 'D';
    if(n==14) return 'E';
    if(n==15) return 'F';
    else return '0';
}




int main(int argc, const char * argv[]) {
    int T; int count=0;
    char empty;
    scanf(" %d %c", &T, &empty);
    while(T--){
        memset(m, 0, sizeof(m));
        p=m;
        foo=0;
        char op = '\0';
        
        while(op!='\n'){
            scanf("%c",&op);
            exe(op);
        }
        
        cout << "Case " << ++count << ": ";
        for (int i=0; i<256; i++) printf("%c%c ",hexmap((m[i]/16)%16),hexmap(m[i]%16));
        cout << "\n";
    }

}





