#include<bits\stdc++.h>
#include<fstream>

using namespace std;

bool LoggingIn(){
    string username, password, un, pw;

    cout<<" \nEnter username:"; cin>>username;
    cout<<" \nEnter password:"; cin>>password;

    ifstream read("D:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(username == un && password == pw){
        return true;
    }
    else{

        return false;
    }
}

int main(){
    while(true){
    int n;
    cout<<"Press\n 1: New registraton\n 2: For Login\n Any Other key to break\n";
    cin>>n;
    if(n==1){
        string username,password;

        cout<<"\nEnter your Username:"; cin>>username;
        cout<<"\nEnter your password:"; cin>>password;

        ofstream read;
        read.open("D:\\" + username + ".txt");
        read<<username<<endl<<password;
        read.close();

        main();                                 //INORDER TO RECALL THE FUNCTION SO THAT EITHER WE CAN REGISTER AGAIN OR LOGIN
    }
    else if(n==2){
        bool login = LoggingIn();

        if(login){
            cout<<" Successful Login ;)\n";
            system("PAUSE");
            return 1;
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