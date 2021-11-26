#include<bits\stdc++.h>
using namespace std;

int diff_in_time(int ss1, int mm1, int hh1, int ss2, int mm2, int hh2){
    int totalsec, ts1, ts2;
    ts1 = hh1*3600 + mm1*60 + ss1;
    ts2 = hh2*3600 + mm2*60 + ss2;

    int hh,mm,ss;

    if(ts1>=ts2){
        totalsec = ts1-ts2;
    }
    else{
        totalsec = ts2-ts1;
    }

    mm = totalsec/60;
    hh = mm/60;
    mm = mm%60;
    ss = totalsec%60;

    cout<<"\n\t\t"<<hh1<<":"<<mm1<<":"<<ss1<<" - "<<hh2<<":"<<mm2<<":"<<ss2<<" = "<<hh<<":"<<mm<<":"<<ss<<endl;

    return 0;
    
}

int main(){
    int hh1,mm1,ss1,hh2,mm2,ss2,n;
    cout<<"\nEnter the time in hh:mm:ss format\n";
    cin>>hh1>>mm1>>ss1;
    cout<<endl;
    cin>>hh2>>mm2>>ss2;

    diff_in_time(ss1,mm1,hh1,ss2,mm2,hh2);
    cout<<"\n1. Run Again \n2. Exit";
    cin>>n;
    switch(n){
        case 1: system("cls");
                main();
        case 2: system("cls");
                cout<<"Bye! Have a nice day :p";
                exit(1);
    }

}