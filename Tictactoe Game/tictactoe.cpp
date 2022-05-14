#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>

using namespace std;
//ham ho tro giao dien
void printHorizontalLine (int size){
    for (int i = 0; i < size; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << " -------";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    std::cout << "\n";
}

void printVerticalLine (int size){
    for (int i = 0; i < size; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "       |";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    std::cout << "\n";
}

// Vẽ ki tu
void drawsym(char c, int i){
	for(int j = 0; j < i; j++){
		cout << c;
	}
	cout << "\n";
}
//end ham ho tro giao dien

//ham ho tro tro choi
void printBoard(int board[][50], int size){

	cout << "\n";
    for (int i = 0; i < size; i++){
        printHorizontalLine(size);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "|";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printVerticalLine(size);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "|";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        for (int j = 0; j < size; j++){
    
			if (board[i][j] < 10){
				 cout << "   ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        		if (board[i][j] == 79 || board[i][j] == 88){
          			cout << char(board[i][j]);
					cout << " ";
        		}else
            		cout << board[i][j];

        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "   |";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}else{
				 cout << "   ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        		if (board[i][j] == 79 || board[i][j] == 88){
          			cout << char(board[i][j]);
					cout << " ";
        		}else
            		cout << board[i][j];
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "  |";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
        }
        cout << "\n";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "|";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printVerticalLine(size);
    }
    printHorizontalLine(size);
}

void setSquare(int square[][50], int size){

    int k = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            square[i][j] = k;
            k++;
        }
    }
}

int check_horizontal(int c, int board[][50], int size){
	int count;
	for(int i = 0; i < size; i++){
		count = 0;
		for(int j = 0; j < size; j++){
			if(board[i][j] == c){
				count++;
			}
			if(count == size){
				return 1;
				break;
			}
		}
	}

}

int check_vertical(int c, int board[][50], int size)
{
	int count;
	for(int i = 0; i < size; i++){
		count = 0;
		for(int j = 0;j < size; j++){
			if(board[j][i] == c){
				count++;
			}
			if(count == size){
				return 1;
				break;
			}
		}
	}
}

int check_diagonal(int c, int board[][50], int size) 
{
	int count = 0;
	for(int i = 0; i < size; i++){
		if(board[i][i] == c || board[i][size -1 - i] == c){
			count++;
		}
		if(count == size){
			return 1;
			break;
		}
	}
}

int toss(){
	int i = rand();
	if(i % 2 == 0){
		return 1;
	}
	else{
		return 2;
	}
}

void playGame(int board[][50], int size, char p1[20], char p2[20], int e, int x, char NameofWinner[20]){
	int move,y;
	int p;
	char player1[20], player2[20];
	int tracker,rch1,rcv1,rcd1,rch2,rcv2,rcd2;

	if(x == 88){
		y = 79;
	}
	else if(x == 79){
			y = 88;
		}
	
	//Nhap ten nguoi choi
	if(e == 1)
	{
		strcpy(player1, p1);
		player1[strlen(player1)] = '\0';

		strcpy(player2, p2);
		player2[strlen(player2)] = '\0';
	}else if(e == 2){
		strcpy(player2, p2);
		player2[strlen(player2)] = '\0';

		strcpy(player1, p1);
		player1[strlen(player1)] = '\0';
		}

	for(p = 1; p < size * size + 1; p++){
		tracker = 0;
		if(p % 2 != 0){
			cout << "\n" << player1 << " please enter the location you want: ";
			cin >> move;
			cout << move;
		}
		if(p % 2 == 0){
			cout << "\n" << player2 << " please enter the location you want: ";
			cin >> move;
			cout << move;
		}
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++){
				if(move == board[i][j] && p % 2 != 0){
					board[i][j] = x;
					tracker += 1;
				       rch1=check_horizontal(x, board, size);
				       rcv1=check_vertical(x, board, size);
				       rcd1=check_diagonal(x, board, size);
				}
				if(move == board[i][j] && p % 2 == 0){
					board[i][j] = y;
					tracker += 1;
				       rch2 = check_horizontal(y, board, size);
				       rcv2 = check_vertical(y, board, size);
				       rcd2 = check_diagonal(y, board, size);
				}
			}
		}
		if(tracker == 0){
			p--;
			cout << "Unacceptable input!! Please try again....";
		}
		else{
			system("cls");
			printBoard(board, size);
		}
		// Bất kì điều kiện nào trả về giá trị là 1 (có kí tự đã đủ 3 ô)
		if(rch1==1 || rcv1==1 || rcd1==1){
			drawsym('-',60);
			cout << player1 << " WINS THE GAME!!\n";
			strcpy (NameofWinner, player1);
			drawsym('-',60);
			break;
		}
		// Bất kì điều kiện nào trả về giá trị là 1 (có kí tự đã đủ 3 ô)
		if(rch2 == 1 || rcv2 == 1 || rcd2 == 1){
			drawsym('*',60);
			cout <<  player2 << " WINS THE GAME!!\n";
			strcpy (NameofWinner, player2);
			drawsym('*',60);
			break;
		}
	}
	if(p == size * size + 1){
		cout<<"\n\n!! Game over....No winner, no loser !!";
	}
}
// end ham ho tro tro choi

//-----------------------------------------------------------//
int main(){
	
	//Code for sound
	//PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC);

	int won,i = 1, x1 = 1, x2 = 1, x_;
	int count1 = 0, count2 = 0;
	char p1[20] = {0} , p2[20] = {0}, x;
	int size;
	int board[50][50];
	char WinnerName [20];

	//Vẽ tên game 
	cout << "\n\t\t\t\tTIC-TAC-TOE\n";
	drawsym('-',60);

	//Nhập tên người chơi
	while(x1 < 2){
		if(strlen(p1) == 0){
			cout<<"\nPlayer 1: Please enter your name: ";
			cin.getline(p1, 20);
			x1 = 1;
		}
		else{
			cout << "\n";
			drawsym('*',60);
			x1 = 2;
		}
	}
	while(x2 < 2){
		if(strlen(p2) == 0){
			cout<<"\nPlayer 2: Please enter your name: ";
			cin.getline(p2, 20);
			x2 = 1;
		}else{
			cout << "\n";
			drawsym('*',60);
			x2 = 2;
		}
	}

	char c;
    do{	
		srand(time(0));
		system("cls");
		cout << "\n";
		//Bắt đầu trò chơi tại đây
        

		//Chọn ngãu nhiên 1 người sẽ chơi trước
		won = toss();
		
		if(won == 1){
			cout << p1 <<" wins the toss!";
			while(i < 2){
				cout << "\nPlease enter your choice (X or O): ";
				cin >> x;
				if(x=='X' || x=='O' || x=='x' || x=='o'){
					i = 2;
				}
				else{
					i = 1;
				}
			}
		}
		else if(won == 2){
				cout<< p2 <<" wins the toss!";
				while(i < 2){
					cout << "\nPlease enter your choice (X or O): ";
					cin >> x;
					if(x=='X' || x=='O' || x=='x' || x=='o'){
						i = 2;
					}else{
						i = 1;
					}
				}
			}

		if(x == 'X' || x == 'x'){
			x_ = 88;
		}else if(x == 'O' || x == 'o'){
			x_ = 79;
		}

		cout << "\n\n\t\t===== MENU PICK SIZE=====";
        cout << "\n\t1. Grid 3x3";
        cout << "\n\t2. Grid 5x5";
        cout << "\n\t3. Grid 7x7";
        cout << "\n\n\t\t===== END MENU PICK SIZE=====";
    
        cout << "\nYour chosen: ";
        cin >> size;

		setSquare(board, size);

		printBoard(board, size);
		playGame(board, size, p1, p2, won, x_, WinnerName);
		//Statictical outconmes
		if (strcmp(WinnerName, p1) == 0){
			drawsym('*',60);
			count1++;
			cout << "\n" << p1 << " has wins " << count1 << " times" << "\n";
			cout << p2 << " has wins " << count2 << " times" << "\n";
			drawsym('*',60);
		}else{
			drawsym('-',60);
			count2++;
			cout << "\n" << p1 << " has wins " << count1 << " times" << "\n";
			cout << p2 << " has wins " << count2 << " times" << "\n";
			drawsym('-',60);
		}


        cout << "\nDo you want to play again?" << "\n";
        cout << "Press [y] to continue, [n] to exit the game!" << "\n";
        cin >> c;

		//Gan lai gia tri ban dau
		i = 1;
		x1 = 1;
		x2 = 1;
    } while (c == 'y'); 
return 0;
}