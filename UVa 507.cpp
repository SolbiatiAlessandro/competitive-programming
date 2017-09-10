//
//  main.cpp
//  032
//
//  Created by Alessandro Solbiati on 03/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int TC,count=1;
    cin >> TC;
    while(TC--){
        int n,e,ini=0,fin=0,ans=0,sum=0;
        cin >> n;
        for(int i=1;i<n;i++){
            cin >> e;
            sum+=e;
            if(sum<0){
                sum=0;
                ini=i+1;
            }
            else if(sum<ans) fin=i;
            else ans=sum;
        }
        
        if(!fin) fin=n;
        if(ans) printf("The nicest part of route %d is between stops %d and %d\n",count,ini,fin);
        else printf("Route %d has no nice parts\n",count);
        count++;
    }
}
