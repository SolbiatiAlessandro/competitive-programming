//
//  main.cpp
//  007
//
//  Created by Alessandro Solbiati on 17/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int TC,n,m,x,y;
    
    while(scanf(" %d",&TC),TC){
        scanf(" %d %d",&n,&m);
        while(TC--){
            std::scanf(" %d %d", &x,&y);
            if (x==n||y==m) printf("divisa\n");
            else if(x>n&&y>m) printf("NE\n");
            else if(x<n&&y>m) printf("NO\n");
            else if(x<n&&y<m) printf("SO\n");
            else if(x>n&&y<m) printf("SE\n");
        }
    }

    
}
