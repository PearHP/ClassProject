#include "function.h"
#include "drawSyms.h"

struct Board{
	int L, W;
	int **grid;
	int cursor;
};

struct Point{
	int x;
	int y;
};

struct Line{
	Point A;
	Point B;
};

void printBoard(Board B){
    int i;
    int wid = B.cursor % B.L;
	int len = B.cursor / B.L;
	int space;
	cout << "\n";
    printHorAxis(B.L);
    for (i = 0; i < B.W; i++){
        printHorizontalLine(B.L, i, len, wid);
        if (i == len && wid == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "|";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else
			cout << "|";

        printVerticalLine(B.L, i, len, wid);

		if (i == len && wid == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "|";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else
			cout << "|";

        for (int j = 0; j < B.L; j++){
            if (B.grid[i][j] != 0){
                if (i == len && (j == wid || j == wid - 1)) {
                    cout << "   ";
                    if (j == wid){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                        cout << char(B.grid[i][j]);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    }else
                        cout << char(B.grid[i][j]);
                    
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    cout << "   |";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                }else{
					cout << "   ";
                    cout << char(B.grid[i][j]);
					cout << "   |";
			    }
            }else{
                    cout << "       |";

            }
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << " " << i; 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            
        cout << "\n";
        if (i == len && wid == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "|";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else
			cout << "|";

        printVerticalLine(B.L, i, len, wid);
    }
    printHorizontalLine(B.L, i, len, wid);
}

void picksize(Board &B){
    int size;
    cout << "\n\n\t\t===== MENU PICK SIZE=====";
    cout << "\n\t1. Grid 16x9";
    cout << "\n\t2. Grid 16x10";
    cout << "\n\t3. Grid 4x3";
    cout << "\n\t4. Grid 8x5";
    cout << "\n\n\t\t===== END MENU PICK SIZE=====";

    cout << "\nYour chosen: ";
    cin >> size;
    switch (size){
        case 1:
            B.L = 16;
            B.W = 9;
            break;
        case 2:
            B.L = 16;
            B.W = 10;
            break;
        case 3:
            B.L = 4;
            B.W = 3;
            break;
        case 4:
            B.L = 8;
            B.W = 5;
            break;
        
        default:
            break;
    }
    B.grid = new int *[B.W];
    for (int i = 0; i < B.W; i++){
        B.grid[i] = new int [B.L];
    }
}

void setGrid(Board &B, int num_char){
    for (int i = 0; i < B.W; i++){
        for (int j = 0; j < B.L; j++){
            B.grid[i][j] = rand() % num_char + 65;
        }
    }
}

bool checkLineX(Board B, Point p1, Point p2) {
    if (p1.x == p2.x){
        int min = findMin(p1.y, p2.y);
	    int max = findMax(p1.y, p2.y);
	    for (int y = min; y < max; y++){
		    if (B.grid[p1.x][y] != 0 ) {
			    return false;
		    }
	    }
	    return true;
    }
    return false;
}

bool checkLineY(Board B, Point p1, Point p2){
    if (p1.y == p2.y){
        int min = findMin(p1.x, p2.x);
	    int max = findMax(p1.x, p2.x);
    
        for (int x = min; x < max; x++){
		    if (B.grid[x][p1.y] != 0 ) {
			    return false;
		    }
	    }
	    return true;
    }
    return false;
}
