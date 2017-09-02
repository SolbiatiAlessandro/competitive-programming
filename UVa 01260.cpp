//
//  main.cpp
//  025
//  sales
//  Created by Alessandro Solbiati on 29/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int l,n,sum=0;
        cin >> l;
        vector<int> ss;
    
        for (int i=0; i<l; i++) {
        
            cin >> n;
            ss.push_back(n);
            
            int nsum=0;
            for (int j = i-1; j>=0; j--) if (n>=ss[j]) nsum++;
            sum += nsum;
            
        }
        printf("%d\n",sum);
    }
}




