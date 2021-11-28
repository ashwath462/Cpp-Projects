#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string randomstr(){
    srand(time(0));
    string s;int r;
    for(int i = 0; i<6; i++){
        r = rand()%26;
        s += ('a' + r);
        cout<<s<<endl;
    }
    return s;
}

string captcha(){
    string s =randomstr();
    int r;
    for(int i = 0; i<3; i++){
        r = rand()%5;
        s[r] = toupper(s[r]);
    }
    return s;
}
    
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<captcha();
    return 0;
}