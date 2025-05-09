using namespace std;
#include <iostream>
#include <limits>
#include<stdio.h>

class board {
  private:
    char a[9];
  public:
    board(){
        int k=49;
        for(int i=0;i<9;i++){
            a[i]=k++;
        }
    }
    void print_board(){
        int k =0;
        printf(" %c | %c | %c \n",a[0],a[1],a[2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n",a[3],a[4],a[5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n",a[6],a[7],a[8]);
    }
    bool check(int n){
        if(1>n || n>9 || a[n-1]=='X' || a[n-1]=='O'){
            return true;
        }
        else{
            return false;
        }
    }
    void move(int n ,char c ){
        a[n-1]=c;
        print_board();
    }
    bool win_lose(char c){
        int k=0;
        for(int i=0;i<3;i++){
            if(a[0+k]==c && a[1+k]==c &&a[2+k]==c){
                return true;
            }
            k+=3;
        }
        for(int i =0;i<3;i++){
            if(a[i]==c && a[3+i]==c && a[6+i]==c){
                return true;
            }
        }
        if(a[0]==c && a[4]==c && a[8]==c){
            return true;
        }
        else if(a[2]==c && a[4]==c && a[6]==c){
            return true;
        }
        else return false;
    }
};

class tic {
    private:
        board board_2;
    public:
        int player=0;
        int n, rounds = 0;
        int players=1;
        char symbol ;
        void start(){
            printf("-- Tic Tac Toe -- CSIE@CGU\n");
            printf("Player 1 (X) - Player 2 (O)\n");
            board_2.print_board();
            while(rounds!=9){
                if(player%2==0){
                    symbol ='X';
                    players =1;
                }
                else{
                    symbol='O';
                    players =2 ;
                }
                while(true){
                    printf("==> Player %d (%c), enter a number:",players,symbol);
                    cin>>n;
                    if(cin.fail() || board_2.check(n) ){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        printf("==> Invalid value, please enter again\n");
                    }
                    else{
                        rounds++;
                        break;
                    }
                } 
                board_2.move(n,symbol);
                if(board_2.win_lose(symbol)){
                    printf("==> Player %d wins!\n",players);
                    break;
                }
                player++;
            }
            if(!board_2.win_lose(symbol)){
                cout<<"==> Game draw\n";
            }
        }
};
int main()
{   
   tic tic_1;
   tic_1.start();
}


    
 
