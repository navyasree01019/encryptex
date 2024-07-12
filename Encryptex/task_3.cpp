#include <iostream>
using namespace std;

void printBoard(string board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << "  |  ";
        }
        cout << endl;
        if(i < 2) cout << "___|_____|___" << endl;
    }
}
void ToMove(string board[3][3],string player){
    while(true){
    int row;
    int column;
    cout<<"Enter the row"<<endl;
    cin>>row;
    cout<<"Enter the column"<<endl;
    cin>>column;
    if(board[row][column]==" "&&row>=0&&row<3&&column>=0&&column<3){
        board[row][column]=player;
        break;
    }
    else{
        cout<<"Invalid move,please try again"<<endl;
    }
    }
}
bool CheckWin(string board[3][3],string player){
    for(int i =0;i<3;i++){
        if((board[0][i]==player)&&(board[1][i]==player)&&(board[2][i]==player)){
           return true;
        }
        if((board[i][0]==player)&&(board[i][1]==player)&&(board[i][2]==player)){
            return true;
        }
        if((board[0][0]==player)&&(board[1][1]==player)&&(board[2][2]==player)){
            return true;
        }
        if((board[2][0]==player)&&(board[1][1]==player)&&(board[0][2]==player)){
            return true;
        }
    }
    return false;
}
bool Draw(string board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==" "){
                return false;
            }
        }
    }
    return true;
}

int main() {
    string board[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
    string currentPlayer = "X";
while(true){
    printBoard(board);
    ToMove(board,currentPlayer);
     if(CheckWin(board,currentPlayer)==true){
      cout<<"Hurray "<<currentPlayer<<" you won!!";
      break;
    }
    else if(Draw(board)==true){
        cout<<"Well played the game ended as a draw";
        break;
    }
    
    if(currentPlayer=="X"){
    currentPlayer="O";
    }
else{
    currentPlayer="X";
}
}
    return 0;
}