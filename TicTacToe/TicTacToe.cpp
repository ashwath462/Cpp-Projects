#include<bits\stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char CurrMarker;
int CurrPlayer;

void drawboard(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"---------\n";
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"---------\n";
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

int winner(){
    for(int i = 0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return CurrPlayer;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return CurrPlayer;
    }
    if(board[0][0] == board[1][1] and board[1][1] == board[2][2]) return CurrPlayer;
    if(board[0][2] == board[1][1] and board[1][1] == board[2][0]) return CurrPlayer;

    return 0;
}

bool placemarker(int slot){
    int row, col;
    row = slot%3 == 0?(slot/3) - 1: slot/3;
    col = slot%3 == 0?2:(slot%3)-1;
    // cout<<row<<" "<<col<<endl;
    if (board[row][col] != 'X' and board[row][col] != 'O'){
        board[row][col] = CurrMarker;
        return true;
    }
    return false;
}

void swap_player_and_marker(){
    if(CurrMarker == 'X') CurrMarker = 'O';
    else CurrMarker = 'X';

    if(CurrPlayer == 1) CurrPlayer = 2;
    else CurrPlayer = 1;

}

void game(){
    cout<<"Player One choose your marker\n";
    char marker_p1;cin>>marker_p1;
    CurrPlayer = 1;
    CurrMarker = marker_p1;

    drawboard();
    int player_won;

    for(int i = 0; i<9; i++){
        cout<<"It's player "<<CurrPlayer<<"'s turn. Enter your Slot : ";
        int slot;cin>>slot;
        if(slot < 1 or slot > 9){
            cout<<"That Slot doesn't exist! Enter a valid Slot";
            i--;
            continue;
        }

        if(!placemarker(slot)){
            cout<<"That Slot Occupied! Try another slot!";
            i--;
            continue;
        }
    placemarker(slot);
        drawboard();
        player_won = winner();

        if(player_won == 1) {cout<<"Player one won! Congratulations... "<<endl;break;}
        if(player_won == 2) {cout<<"Player Two won! Congratulations... "<<endl;break;}

        swap_player_and_marker();
    }
    if(player_won == 0) cout<<"It's a Tie, Play again... ";
}
int main(){
    game();
    // srand(time(NULL));
    // cout<<(rand() % (10 - 1 + 1)) + 1<<endl;
}