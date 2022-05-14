void printHorAxis(int size){
    for (int i = 0; i < size; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout << "    " << i << "   ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    cout << "\n";
}

void printHorizontalLine(int size, int r, int l, int w) {
	for (int i = 0; i < size; i++) {
		if (i == w && (r == l || r == l + 1)) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << " -------";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else
			cout << " -------";
	}
	cout << "\n";
}

void printVerticalLine(int size, int r, int l, int w) {
	for (int i = 0; i < size; i++) {
		if (r == l && (i == w || i == w - 1)) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << "       |";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else
			cout << "       |";
	}
	cout << "\n";
}
