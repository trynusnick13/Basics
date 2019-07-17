#pragma once
#include<windows.h>
#include "functions.h"
#include<conio.h>
#include<stdio.h>
#include <iostream>
# define N 5
#define ENTER 13
#define ESC 27
#define LEFT 75
#define SPACE 32
#define RIGHT 77

#define COLOR1 252
#define COLOR2 240
#define RED 4
void Menu(HANDLE h, int k) {
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(h, &Info);

	COORD left;
	left.X = (Info.dwSize.X - 34) / 2;
	left.Y = 0;
	SetConsoleCursorPosition(h, left);

	switch (k) {
	case 0: {

		SetConsoleTextAttribute(h, COLOR1);
		cout << "Draw vertices ";
		SetConsoleTextAttribute(h, COLOR2);
		cout << "|| About || HELP" << endl;
		break;
	}
	case 1: {
		SetConsoleTextAttribute(h, COLOR2);
		cout << "Draw vertices ||";
		SetConsoleTextAttribute(h, COLOR1);
		cout << " About ";
		SetConsoleTextAttribute(h, COLOR2);
		cout << "|| HELP" << endl;
		break;
	}
	case 2: {
		SetConsoleTextAttribute(h, COLOR2);
		cout << "Draw vertices || About ||";
		SetConsoleTextAttribute(h, COLOR1);
		cout << " HELP" << endl;
		SetConsoleTextAttribute(h, COLOR2);

		break;
	}

	}
	//printf("[ Vectors ] [ Matrices ] [ About ]\n");
}

void Draw_vertices(HANDLE h) {
	system("cls");
	Menu(h, 0);
	//cout << "Sir, Lord, Graph";
	HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"Thank you, dear D.Welsh and M.Powell !!");
	init_house();
	_init_brush();
	drawing_function();
	matrix_incd(matrix);
	draw_graph();
	print_matrix(matrix);
	system("pause");

	cout << quantity() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Vertex " << i << " has " << colors[vertices[i].get_COLOR()] << " color" << endl;
	}

	///////////////////
	cout << "\t\t\t\t\t\tThe result of our creativity( only " << counter << " colors were used):" << endl;
	for (int i = 0; i < N; i++) {

		sizep[i][1] += 150;
		sizep[i][3] += 150;

	}
	drawing_function();
	for (int i = 0; i < n; i++) {

		FillRect(hdc, &ver[i], brush[i]);

	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {


			if (matrix1[i][j] == 1)draw_line(i, j);


		}

	}
	///////////////////
	system("pause");
	//ReleaseDC(NULL, hdc);
	//cin.ignore();
}

void About(HANDLE h) {
	system("cls");
	Menu(h, 1);
	cout << "Algorithm. " << endl;
	SetConsoleTextAttribute(h, COLOR1);
	cout << "1. Finite Graph by the adjancecy matrix :   " << endl << endl;
	SetConsoleTextAttribute(h, COLOR2);
	cout << "\t 1) Enter amount of vetices that will take part in drawing" << endl << "\t(mind about 5 vertices limit for drawing)." << endl << endl;
	cout << "\t 2) Input vertices that are adjacent with the current vertex." << endl << "\t Mind that this program is created only for connected component." << endl << "\t Thus, if you have two connected components, you may find their colors separately" << endl << endl;
	cout << "Every vertex receives its own color and counter of colors = amount of vertices  " << endl;
	cout << "Matrix was finally built and corresponded graph can be easily noticed  " << endl << endl;
	SetConsoleTextAttribute(h, COLOR1);
	cout << "2. Let's exterminate colors ! ! !   " << endl << endl;
	SetConsoleTextAttribute(h, COLOR2);
	cout << "\t 1) Pay your attention to class 'Vertices' where you may" << endl << "\t see member 'amount' which contains" << endl <<
		"\t information about quantity of the adjacent vertices" << endl << "\t In the array 'verices[N]' we are looking for a" << endl << "\t vertex with the greatest member 'amount'" << endl << endl;
	cout << "\t 2) Than all the vertices that are not adjacent to the 'Greatest'" << endl << "\t will be painted in it's colors. Futhermore!!!" << endl << "\t Painted vertex will be 'crossed out' by '1' " << endl << endl;
	cout << "Well, well, well. Now you may see how each COLOR" << endl << "substitution is followed with the repainting " << endl << endl;
	SetConsoleTextAttribute(h, COLOR1);
	cout << "'THE' CHAPTER 3  " << endl << endl;
	SetConsoleTextAttribute(h, COLOR2);
	cout << "\t Graph is painted and part of the colors for ever lost. Thank you, Dear D.Welsh and M.Powell" << endl << endl;
}

void help(HANDLE h) {
	system("cls");
	Menu(h, 2);
	SetConsoleTextAttribute(h, COLOR1);
	cout << "Information about the graphs:" << endl;
	SetConsoleTextAttribute(h, COLOR2);
	cout << "\tAdjacency matrix - In graph theory and computer science, an " << endl << "adjacency matrix is a square matrix used to represent a finite graph." << endl << "The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph. " << endl;
	cout << "\tComponets in graph theory, a component, sometimes called a connected component," << endl << "of an undirected graph is a subgraph in which any two" << endl << "vertices are connected to each other by paths," << endl << "and which is connected to no additional vertices in the supergraph " << endl << endl;
	cout << "\tThe main goal graph painting follows is to find a chromatic number " << endl;
	cout << "Chromatic number - assigning distinct colors to distinct vertices" << endl << "always yields a proper coloring " << endl << endl;
	SetConsoleTextAttribute(h, COLOR1);
	cout << "Menu helper:" << endl;
	SetConsoleTextAttribute(h, COLOR2);
	cout << "\t Dear graph-explorer, welcome to the painting world" << endl;
	cout << "\t Use -> <- to move around the menu" << endl;
	cout << "\t Press 'Spase' to activate the chosen area " << endl;
	cout << "\t Press 'Esc' to exit the program " << endl << endl;

	cout << "\t Choose 'Draw vertices' to start building   " << endl;
	cout << "\t Choose 'About' to get familiar with the drawing  aspects " << endl;
	cout << "\t Choose 'HELP' if you are confused with all this painting algorithms" << endl;

	SetConsoleTextAttribute(h, COLOR1);
	cout << "Ask Spectorsky Igor Yakovich for the more information ";
	SetConsoleTextAttribute(h, COLOR2);
}

void HorizontalMenu(HANDLE h) {
	int k = 0, max = 2;
	int ch, fl = 1;
	Menu(h, k);
	while (fl) {
		if (_kbhit()) {
			ch = _getch();
			switch (ch) {

			case SPACE: {
				switch (k) {
				case 0: {
					Draw_vertices(h);

					break;
				}
				case 1: {
					About(h);
					break;
				}
				case 2: {
					help(h);
					break;
				}
				} break;
			}

			case LEFT: {
				if (k == 0) k = max; else k--;
				Menu(h, k); break;
			}
			case RIGHT: {
				if (k == max) k = 0; else k++;
				Menu(h, k); break;
			}
			case ESC: {fl = 0; break; }
			}
		}
	}
}
