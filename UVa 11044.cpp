//
//  main.cpp
//  004
//
//  Created by Alessandro Solbiati on 16/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int TC, a, b;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d",&a,&b);
        int xx=0; int xy=0;
        int height = a-2;
        int width = b-2;
        if(height%3){
            xy = height/3 + 1;
        }else xy = height/3;
        
        if(width%3){
            xx = width/3+1;
        }else xx = width/3;
        
        printf("%d\n", xx*xy);
    }
}
