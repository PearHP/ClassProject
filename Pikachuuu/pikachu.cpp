#include "configBoard.h"

int main(){
    srand(time(0));
    Board B;
    B.cursor = 0;
    Point p1, p2;

    char c = ' ', replay;
    int num_char, size, count = 0;
    
	do{
        bool check = true;
        picksize(B);
        cout << "How many characters do you want? At least 1! ";
        cin >> num_char;
        setGrid(B, num_char);
        printBoard(B);
        
        while (check){
            system("cls");
            printBoard(B);
            c = _getch();
				switch (c) {
				case 72: {
					if (B.cursor >= B.L) {
						B.cursor -= B.L;
					}
					break;
				}
				case 80: {
					if (B.cursor <= B.L * (B.W - 1) - 1) {
						B.cursor += B.L;
					}
					break;
				}
				case 75: {
					if (B.cursor > 0) {
						B.cursor -= 1;
					}
					break;
				}
				case 77: {
					if (B.cursor < B.W * B.L - 1) {
						B.cursor += 1;
					}
					break;
				}
                case 13:{
                    int wid = B.cursor % B.L;
                    int len = B.cursor / B.L;
                    if (B.grid[len][wid] != 0 && count == 0){
                        p1.x = len;
                        p1.y = wid;
                        count++;
                    }
                    if (B.grid[len][wid] != 0 && count == 1){
                        p2.x = len;
                        p2.y = wid;
                        count++;
                    }
                    if (count == 2){
                        if (checkLineX(B, p1, p2) || checkLineY(B, p1, p2)){
                            B.grid[p1.x][p1.y] = 0;
                            B.grid[p2.x][p2.y] = 0;
                        }
                        count = 0;
                    }
                    break;
                }
                case 27:{
                    check = false;
                    break;
                }
                
            }
        }
        
        cout << "Do you want to continue? Yes(y)/No(n)" << "\n";
        cin >> replay;
    }while (replay == 'y' || replay == 'Y');

    for (int i = 0; i < B.W; i++){
		delete[] B.grid[i];
	}
    return 0;
}