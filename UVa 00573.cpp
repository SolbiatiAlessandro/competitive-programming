//
//  main.cpp
//  011
//
//  Created by Alessandro Solbiati on 19/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

float new_high(float prev_h,int U,int F, int i){
    float frate = float((i-1)*U*F)/float(100);
    float new_high = prev_h+U-frate;
    if(new_high>0) return new_high;
    else return prev_h;
}


int main(int argc, const char * argv[]) {
    int H,U,D,F;
    std::scanf("%d %d %d %d",&H,&U,&D,&F);
    while (H) {
        float prev_h=0;
        float prev_h_max=0;
        int i=1,flag=1;
        while(flag){
            float h_max = new_high(prev_h, U, F, i);
            float h = h_max-D;
            if (h_max>H){
                printf("success on day %d\n",i);
                flag=0;
            }
            if (h<=0){
                printf("failure on day %d\n",i);
                flag=0;
            }
            i++;
            prev_h = h;
            prev_h_max = h_max;
        }
        std::scanf("%d %d %d %d",&H,&U,&D,&F);
    }
}


