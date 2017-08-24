//
//  main.cpp
//  17
//
//  Created by Alessandro Solbiati on 22/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int fact(int n){
    int out =1;
    for (int i=n; i>0; i--) out *=i;
    return out;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(scanf(" %d %d",&n,&m)==2 && !(n==0 && m==0)){
        int count=0;
        
        int a[8];
        for (int i=0; i<n; i++) *(a+i)=i;
        std::vector<int> av (&a[0], &a[n]);
        
       
    
        bool pers[40320] = {};

            
        for (int i=0; i<m; i++) {
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            
            std::vector<int> t(av);
            t.resize(n);
            int per = 0;
            
            do {
                if(!pers[per]){
                    int pa=0,pb=0;
        
                    for (int i=0; i<n; i++) {
                        if(t.at(i)==a) pa=i;
                        else if(t.at(i)==b) pb=i;
                    }
                
                    if(c>0 && abs(pb-pa)>c) *(pers+per)=1;
                    else if(c<0 && abs(pb-pa)<(-c)) *(pers+per)=1;
                }
                per++;
            } while (std::next_permutation(&t[0],&t[n]));
            
            
            
        }
        
        for (int i=0; i<fact(n); i++) if (!pers[i]) count++;

        printf("%d\n",count);
        
    }
}
