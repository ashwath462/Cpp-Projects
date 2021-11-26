#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main(){
    int h,m,s;
    cout<<"enter the Hours:Minutes:Seconds";
    cin>>h>>m>>s;
    int hr=h,min=m,sec=s;
    while(true){    
        if(hr<=23 && min<=59 && sec<=59){
        system("cls");
        cout<<"\t\t   ******************** \n\n";
        cout<<"\t\t\t"<<hr<<" : "<<min<<" : "<<sec<<" \n\n";
        cout<<"\t\t   ******************** \n";
            if(sec > 0){
            sec--;
            }
            else{
                if(min>0){
                    min--;
                    sec = 59;
                    continue;
                }
                else if(min == 0, hr>0){
                    hr--;
                    min = 59;
                    continue;
                }
                if(hr==0 && min==0){
                    system("cls");
                    cout<<"TIME UP !";
                    break;
                }
            }

    }
}
}
