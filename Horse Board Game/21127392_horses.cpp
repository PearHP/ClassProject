#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstring>

using namespace std;

void printHorizontalLine (int size){
    for (int i = 0; i < size; i++){
        std::cout << " -------";
    }
    std::cout << "\n";
}

void printVerticalLine (int size){
    for (int i = 0; i < size; i++){
        std::cout << "       |";
    }
    std::cout << "\n";
}

void printBoard(char board[][4],int map[][10], int size){

    for (int i = 0; i < size; i++){
        printHorizontalLine(size);
        cout << "|";
        printVerticalLine(size);
        cout << "|";
        for (int j = 0; j < size; j++){
            cout << "  " << board[map[i][j]] << "  |";
        }
        cout << "\n" << "|";
        printVerticalLine(size);
    }
    printHorizontalLine(size);
}

void setBoard(char board[][4], char name[][4], int pos[], int size, int N){
    
    for (int i = 0; i < size * size; i++){
        memcpy(board[i], "   ", 4);
    }

    for (int i = 0; i < 3; i++){
        if (pos[i] != -1){
            memcpy(board[pos[i]], name[i], 4);
        }
    }
}

void playGame(char board[][4], char name[][4], int pos[], int map[][10], int size, int N, int roll, int& count){
    int move, winner = -1;

    while (winner == -1){
        for (int i = 0; i < N; i++){
            move = rand() % roll + 1;
            cout << name[i] << " roll into " << move << "\n";
            if ( pos[i] + move > size * size - 1){
            cout << name[i] << " cannot move toward " << "\n";
            }
            else{
                pos[i] += move;
                cout << name[i] << " move forward " << move << "\n";
                if (pos[i] == size * size - 1){
                    winner = i;
                    break;
                }
            }

            for (int j = 0; j < N; j++){
                if (pos[i] == pos[j] && i != j){
                    pos[j] = -1;
                    cout << name[i] << " is kicked by " << name[j] << "\n";
                    break;
                }  
            }
            setBoard(board, name, pos, size, N);
            printBoard(board, map, size);
            getch();
        }
    }

    setBoard(board, name, pos, size, N);
    printBoard(board, map, size);
    cout << name[winner] << " is the winner! " << "\n";
    count = winner;
}


void setMapNormal(int a[][10], int& n){
    int k = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int j = 0; j < n; j++){
                a[i][j] = k++;
            }
        }
    }
}

void setMapZigzag(int a[][10], int& n){
    int k = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int j = 0; j < n; j++){
                a[i][j] = k++;
            }
        } else{
            for (int j = n - 1; j >= 0; j--){
                a[i][j] = k++;
            }
        }   
    }
}

void setMapSpiral(int A[][10], int& n){
    
	int len = n, k = 0, p = 0, i;            /*k is to assign the values to the array from 1...n*n */
									/*len is used to update(decrease) array size so that values cans be assign to them */
	while(k < n * n)                      
	{
		for(i = p; i < len; i++)         /*Loop to access the first row of the array*/
		{
			A[p][i] = k++;
		}
		for(i = p + 1; i < len; i++)      /*Loop tp access the last column of the array*/
		{
			A[i][len - 1] = k++;
		}
		for(i = len - 2; i >= p;i--)     /*Loop to access the last row of the array*/ 
		{
			A[len - 1][i] = k++;
		}
		for(i = len - 2; i > p; i--)      /*Loop to access the first column of the array*/
		{
			A[i][p] = k++;
		}
		p++;
        len = len-1;
		
	}
	if(!n % 2)                      /*This block will run only if n is even*/
	{
		A[(n + 1)/2][(n + 1)/2]= n * n; /*It will assign the last value to the centremost element*/
	}

}


int main(){
    srand(time(0));
    
   
    int size;
    int N;
    char name[10][4];
    int map[10][10];
    int pos[10];
    int check;
    int count[10];

    cout << "\nEnter size of board: ";
    cin >> size;

    char board[size * size][4];
  
    cout << "\nEnter number of players: ";
    cin >> N;
    cout << "\nEnter the player's name with 3 characters! " << "\n";
    for (int i = 0; i < N; i++){
        cout << "Name of player " << i + 1 << ":"; 
        cin >> name[i];
        cout << "\n";
    }

    //set default value for array count
    for (int i = 0; i < N; i++){
        count[i] = 0;
    }

    cout << "\n";
    //Play game and replay
    char c;
    do{
        //Menu pick map
        int choose;

        cout << "\n\n\t\t===== MENU PICK MAP=====";
        cout << "\n\t1. Map normal";
        cout << "\n\t2. Map Zigzag";
        cout << "\n\t3. Map Spiral";
        cout << "\n\n\t\t===== END MENU PICK MAP=====";
    
        cout << "\nYour chosen: ";
        cin >> choose;

        if (choose == 1){
            cout << "\nYou have picked map normal";
            setMapNormal(map, size);
   
        }else if(choose == 2){
            cout << "\nYou have picked map zigzag";
            setMapZigzag(map, size);
     
        }else if (choose == 3){
            cout << "\nYou have picked map spiral";
            setMapSpiral(map, size);
        }

        //select max number of dice roll
        int roll;
        cout << "\nSelect max number of dice roll (max is 6): ";
        cin >> roll;

        for (int i = 0; i < N; i++){
            pos[i] = 0;
        }

        playGame(board, name, pos, map, size, N, roll, check);

        for (int i = 0; i < N; i++){
            if (check == i){
                count[check]++;
            }
        }

        for (int i = 0; i < N; i++){
            cout << "\n";
            cout << name[i] << " has wins " << count[i] << " times";
        }

        cout << "\n\nDo you want to play again?" << "\n";
        cout << "Press [y] to continue, [n] to exit the game!" << "\n";
        cin >> c;
    } while (c == 'y'); 

    return 0;
}