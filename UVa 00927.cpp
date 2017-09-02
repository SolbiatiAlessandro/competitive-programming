//
//  main.cpp
//  022
//
//  Created by Alessandro Solbiati on 28/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cmath>


int G,d,c[20];

double a(int n){
    double sum=0;
    for(int g=0;g<=G;g++) sum+= c[g]* std::pow(n, g);
    return sum;
}

int main(int argc, const char * argv[]) {
    int TC;
    scanf("%d",&TC);
    while (TC--) {
        double k,n=1;
        
        std::cin >> G;
        for(int i=0;i<=G;i++) std::cin >> c[i];
        std::cin >> d;
        std::cin >> k;
        
        while(k>d*n*(n+1)/2) n++;
        
        
        printf("%.0f\n", a(n));
        
    }
}


