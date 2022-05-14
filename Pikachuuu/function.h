#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int findMax(int x, int y){
	if (x > y)
		return x;
	return y;
}

int findMin(int x, int y){
	if (x < y)
		return x;
	return y;
}
