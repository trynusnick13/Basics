
#include "pch.h"
#include "functions.h"
#include "interface.h"
#include <windows.h>
#include <iostream>
int main() {
HANDLE h;
h = GetStdHandle(STD_OUTPUT_HANDLE);
HorizontalMenu(h);
ReleaseDC(NULL, hdc);
cin.ignore();
return 0;
}
