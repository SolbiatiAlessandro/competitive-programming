//
//  main.cpp
//  0444
//
//  Created by Alessandro Solbiati on 09/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int n=9,A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };

int m(int i){
    if(i==0) return A[i];
    int mm = m(i-1)+A[i];
    if(mm < 0) return 0;
    return mm;
}

int main(int argc, const char * argv[]) {
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,m(i));
    printf("%d\n",ans);
}
