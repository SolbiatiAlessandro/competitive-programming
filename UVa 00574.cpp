//
//  main.cpp
//  27
//
//  Created by Alessandro Solbiati on 30/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int t,n,seq[12],sums[12],c_sums;

vector<vector<int>> output;

bool valid(int e){
    int sum = e;
    for(int i = 0;i<c_sums;i++) sum += sums[i];
    if (sum<t) return 1;
    else if(sum==t){
        vector<int> new_out;
        for(int i=0;i<c_sums;i++) new_out.push_back(sums[i]);
        new_out.push_back(e);
        output.push_back(new_out);
        return 0;
    }
    else return 0;
}

void rec(int c){
    for(int i=c;i<n;i++){
        if(valid(seq[i])){
            sums[c_sums] = seq[i];
            c_sums++;
            rec(i+1);
            c_sums--;
        }
    }
}

int main(){
    while (scanf("%d",&t),t) {
        scanf("%d",&n);
        memset(seq, 0, sizeof(seq));
        memset(sums, 0, sizeof(sums));
        c_sums=0;
        
        int elem;
        for(int i=0; i<n; i++){
            scanf("%d",&elem);
            seq[i]=elem;
        }
        
        rec(0);
        
        for (<#initialization#>; <#condition#>; <#increment#>) {
            <#statements#>
        }
        
    }
}
