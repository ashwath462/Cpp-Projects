#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;
int main(){
    int hr=0;
    int min=0;
    int sec=0;

    while(true){
        system("cls");
        cout<<"\t\t   ******************** \n\n";
        cout<<"\t\t\t"<<hr<<" : "<<min<<" : "<<sec<<" \n\n";
        cout<<"\t\t   ******************** \n";
        sec++;
        if(sec == 60){
            min++;
            if(min == 60){
                hr++;
                if(hr == 24){
                    hr=0;
                }
            }
        }
        sleep(1);
    }
    return 0;
}