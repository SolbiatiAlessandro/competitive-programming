//
//  main.cpp
//  031
//  UVa 11236
//  Created by Alessandro Solbiati on 03/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    for(int a=1;a<=500;a++){
        for(int b=a;b<=500;b++){
            for(int c=b;c<=500;c++){
                long long p = (a * b * c);
                long long s = (a + b + c);
                
                if(p <= 1000000)
                    continue;
                
                //d = (a+b+c)*10^6/(a*b*c-10^6)
                long long d = (1000000 * s) / (p - 1000000);
                
                if(d < c || s + d >2000)
                    continue;
                
                if(fabs((a+b+c+d)/100.0 - (a*b*c*d) / 100000000.0) < 1e-9){
                    printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",a/100.0,b/100.0,c/100.0,d/100.0);
                }
            }
        }
    }
}
