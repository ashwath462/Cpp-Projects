#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include <unistd.h>

using namespace std;

bool LoggingIn(){
    string username, password, un, pw;
    system("CLS");
    cout<<" \nEnter username:"; cin>>username;
    cout<<" \nEnter password:"; cin>>password;

    ifstream read("D:\\LoginSystem\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(username == un && password == pw){
        return true;
    }
    else{

        return false;
    }
}

string randomstr(){
    srand(time(0));
    string s;int r;
    for(int i = 0; i<6; i++){
        r = rand()%26;
        s += ('a' + r);
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


void checkCaptcha(int t = 0){
    system("CLS");
    string s = captcha();
    string conf;
    cout<<"        "<<s<<"        ";
    cout<<"\nEnter the Captcha shown above: \n";
    cin>>conf;
    if(s == conf){
        system("CLS");
        cout<<" Successful Login! :) \n";
        system("PAUSE");
    }
    else{
        if(t<2){
            t++;
            cout<<"Wrong Captcha! Try again";
            sleep(1);
            system("CLS");
            checkCaptcha(t);
        }
        else{
            system("CLS");
            cout<<"Verification Failed!\n";
            system("PAUSE");
        }
    }
}

int main(){
    while(true){
    int n;
    system("CLS");
    cout<<"Press\n 1: New registraton\n 2: For Login\n Any Other key to break\n";
    cin>>n;
    if(n==1){
        string username,password;

        cout<<"\nEnter your Username:"; cin>>username;
        cout<<"\nEnter your password:"; cin>>password;

        ofstream read;
        read.open("D:\\loginSystem\\" + username + ".txt");
        read<<username<<endl<<password;
        read.close();

        main();                                 //INORDER TO RECALL THE FUNCTION SO THAT EITHER WE CAN REGISTER AGAIN OR LOGIN
    }
    else if(n==2){
        bool login = LoggingIn();

        if(login){
            checkCaptcha(0);
        }
        else{
            cout<<" Incorrect Details!\n";
            system("PAUSE");
            return 0;
        }
    }
    else{
        break;
    }
    }
}