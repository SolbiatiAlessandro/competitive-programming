//
//  main.cpp
//  003
//
//  Created by Alessandro Solbiati on 14/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

int main(){
    int a,b,c,d,deg,tot;
    while(scanf("%d %d %d %d \n",&a,&b,&c,&d)!=EOF){
        deg=1080;
        tot = (a+40-b)%40;
        tot += (c+40-b)%40;
        tot += (c+40-d)%40;
        deg+= tot*360/40;
        printf("%d\n",deg);
    }
          return 0;
}

