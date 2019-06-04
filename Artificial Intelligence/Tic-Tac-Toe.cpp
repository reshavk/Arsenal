#include<bits/stdc++.h>
using namespace std;

class Game {
    enum class Player {
        none = '-',
        human = 'X',
        computer = 'O'
    };

    struct Move {
        int x = 0;
        int y = 0;
    };

    Player board[3][3];
    
    public :
        Game() {
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    board[i][j] = Player::none;
                }
            }
        }

        void printBoard() {
            cout << "\n+-----------------+";
            for(int i=0; i<3; i++) {
                cout << "\n|";
                for(int j=0; j<3; j++) {
                    cout << setw(3) << static_cast<char>(board[i][j]) << setw(3) << "|";
                }
            }
            cout << "\n+-----------------+\n"; 
        }

        bool isTie() {
            for(int i=0; i<3; i++) {
                if(board[i][0]==Player::none || board[i][1]==Player::none || board[i][2]==Player::none) {
                    return false;
                }
            }
            return true;
        }

        bool checkWin(Player player) {
            for(int i=0; i<3; i++) {
                if(board[i][0]==player && board[i][1]==player && board[i][2]==player) {
                    return true;
                }
            }

            for(int i=0; i<3; i++) {
                if(board[0][i]==player && board[1][i]==player && board[2][i]==player) {
                    return true;
                }
            }

            if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
                return true;
            
            if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
                return true;
            
            return false;
        }

        Move minimax() {
            int score = numeric_limits<int>::max();
            Move move;

            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if(board[i][j]==Player::none) {
                        board[i][j] = Player::computer;
                        int temp = maxSearch();
                        cout << i << "," << j << " " << temp << " " << score << "\n";
                        if(temp < score) {
                            score = temp;
                            move.x = i;
                            move.y = j;
                        }
                        board[i][j] = Player::none;
                    }
                }
            }
            return move;
        }

        int maxSearch() {
            if(checkWin(Player::human))
                return 10;
            else if(checkWin(Player::computer))
                return -10;
            else if(isTie())
                return 0;
            
            int score = numeric_limits<int>::min();
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if(board[i][j] == Player::none) {
                        board[i][j] = Player::human;
                        score = max(score, minSearch());
                        board[i][j] = Player::none;
                    }
                }
            }
            return score;
        }

        int minSearch() {
            if(checkWin(Player::human))
                return 10;
            else if(checkWin(Player::computer))
                return -10;
            else if(isTie())
                return 0;
            
            int score = numeric_limits<int>::max();
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if(board[i][j] == Player::none) {
                        board[i][j] = Player::computer;
                        score = min(score, maxSearch());
                        board[i][j] = Player::none;
                    }
                }
            }
            return score;
        }

        void getHumanMove() {
            bool fail = true;
            int x = -1, y =-1;

            do {
                cout << "Your Move : ";
                char c;
                cin >> c;
                x = c - '0';
                cin >> c;
                y = c - '0';

                fail = board[x][y] != Player::none;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

            }while(fail);

            board[x][y] = Player::human;
        }

        void play() {
            int turn = 0;
            bool exit = false;

            printBoard();
            cout << "Enter you move : ";

            do {
                if(!turn) {
                    getHumanMove();
                    if(checkWin(Player::human)) {
                        cout << "You Win\n";
                        exit = true;
                    }
                }
                else {
                    cout << "Computer Move : ";
                    Move aimove = minimax();
                    cout << aimove.x << aimove.y << "\n";
                    board[aimove.x][aimove.y] = Player::computer;

                    if(checkWin(Player::computer)) {
                        cout << "Computer Wins\n";
                        exit = true;
                    }
                }
                
                if(isTie()) {
                    cout << "\n+--------TIE-------+\n";
                    exit = true;
                }

                turn ^= 1;
                printBoard();
            }while(!exit);
        }
};

int main() {
    Game tictactoe;
    tictactoe.play();
    return 0;
}
