#pragma once
#include <iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

# define N 5

using namespace std;
int matrix[N][N], matrix1[N][N], n, counter;
int sizep[5][4];
RECT ver[N];
HBRUSH brush[N];
HDC hdc = GetDC(GetConsoleWindow());
char colors[5][20] = { "Lemon","Orange","Terracotta","Fuchsia", "Olive" };


class Vertices {

	//	COORD coords;
	WORD COLOR;
	int amount;

public:

	Vertices() :COLOR(0), amount(0) {
	};

	~Vertices() {};
	Vertices& set_COLOR(WORD i) {

		COLOR = i;
		return *this;


	};
	Vertices& set_amount(int i) {

		amount = i;
		return *this;
	};

	WORD get_COLOR() { return COLOR; };
	int get_amount() { return amount; };

	void print() {

		cout << "Amount:" << amount << " color:" << COLOR;

	};
};

static Vertices vertices[N];


void _init_(int a[][N], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			//if(i==j) a[i][j] = 1;
			a[i][j] = 0;


		}


	}

}

int amount(int a[N]) {

	int am = 0;
	for (int i = 0; i < n; i++) {

		if (a[i] == 1)am++;

	}
	return am;

}

void init_house() {

	sizep[0][0] = 800;
	sizep[0][1] = 100;
	sizep[0][2] = 820;
	sizep[0][3] = 120;
	//////////////////
	sizep[1][0] = 850;
	sizep[1][1] = 150;
	sizep[1][2] = 870;
	sizep[1][3] = 170;
	//////////////////
	sizep[2][0] = 750;
	sizep[2][1] = 150;
	sizep[2][2] = 770;
	sizep[2][3] = 170;
	//////////////////
	sizep[3][0] = 750;
	sizep[3][1] = 200;
	sizep[3][2] = 770;
	sizep[3][3] = 220;
	//////////////////
	sizep[4][0] = 850;
	sizep[4][1] = 200;
	sizep[4][2] = 870;
	sizep[4][3] = 220;
	//////////////////


}

void draw_line(int, int);
void drawing_function();


void _init_brush() {

	brush[0] = CreateSolidBrush(RGB(253, 233, 16));// lemon
	brush[1] = CreateSolidBrush(RGB(243, 98, 35)); // orange
	brush[2] = CreateSolidBrush(RGB(0, 255, 0));// terracotta
	brush[3] = CreateSolidBrush(RGB(255, 0, 255)); // fuchsia 
	brush[4] = CreateSolidBrush(RGB(128, 128, 0)); // olive



}

void matrix_incd(int inc_matrix[][N]) {

	int   inc, count = 0;
	cout << "Enter amount of vertices : " << endl;
	while (true) {

		while (!(cin >> n)) {


			cout << "Incorrect input" << endl;
			cin.clear();
			while (getchar() != '\n');
			for (int i = 0; i < N; i++) {

				sizep[i][1] += 50;
				sizep[i][3] += 50;

			}
			drawing_function();
		}
		if ((n < N + 1) && (n > 1)) break;
		else {
			for (int i = 0; i < N; i++) {

				sizep[i][1] += 50;
				sizep[i][3] += 50;

			}
			drawing_function();
			cout << "Incorrect input" << endl;
		}
	}
	counter = n;
	_init_(inc_matrix, n);
	_init_(matrix1, n);
	for (int i = 0; i < n; i++) {

		vertices[i].set_COLOR(i);
		cout << "Enter vertices adjacent to V " << i << " and press Enter to proceed(at least 1): " << endl;

		while (true) {


			while (true) {


				while (!(cin >> inc)) {


					cout << "Incorrect input" << endl;
					cin.clear();
					while (getchar() != '\n');
					for (int i = 0; i < N; i++) {

						sizep[i][1] += 50;
						sizep[i][3] += 50;

					}
					drawing_function();

				}
				if ((inc < n) && (inc > -1) && (inc != i)) break;
				else {
					cout << "Incorrect input" << endl;
					for (int i = 0; i < N; i++) {

						sizep[i][1] += 50;
						sizep[i][3] += 50;

					}
					drawing_function();
				}
			}
			inc_matrix[i][inc] = inc_matrix[inc][i] = 1;
			matrix1[i][inc] = matrix1[inc][i] = 1;
			//draw_line(i, inc);
			char ch = getchar();
			if (ch == '\n') break;
			inc = 0;

		}

		vertices[i].set_amount(amount(matrix[i]));


	}

}

void print_matrix(int inc_matrix[][N]) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cout << inc_matrix[i][j];

		}

		cout << endl;

	}
	cout << endl;
}

int  max_el() {
	int max_el = 0, index = 0;
	for (int i = 0; i < n; i++) {

		if (vertices[i].get_amount() > max_el) {

			index = i;
			max_el = vertices[i].get_amount();
		}

	}

	return index;
}

void draw_graph();

int quantity() {

	int  j = 0, y = 0;

	while (y < n) {

		j = max_el();
		//cout << "max ver: " << j << endl;
		for (int i = 0; i < n; i++) {
			if (j != i) {

				if (matrix[j][i] == 0) {

					vertices[i].set_COLOR(vertices[j].get_COLOR());
					brush[i] = brush[j];

					vertices[j].set_amount(0);
					counter--;
					//cout << "Counter of colors:" << counter << endl;
					print_matrix(matrix);

					for (int i = 0; i < N; i++) {

						sizep[i][1] += 120;
						sizep[i][3] += 120;

					}
					drawing_function();
					draw_graph();
					system("pause");

					for (int k = 0; k < n; k++) {

						matrix[k][i] = 1;
						matrix[i][k] = 1;

					}

				}



			}

		}
		vertices[j].set_amount(0);
		y++;
	}

	return counter;

}




void draw_line(int k, int j) {

	int Xk, Yk, Xj, Yj;
	Xk = (sizep[k][0] + sizep[k][2]) / 2;
	Yk = (sizep[k][1] + sizep[k][3]) / 2;
	Xj = (sizep[j][0] + sizep[j][2]) / 2;
	Yj = (sizep[j][1] + sizep[j][3]) / 2;

	MoveToEx(hdc, Xk, Yk, NULL);
	LineTo(hdc, Xj, Yj);

}



void drawing_function() {
	for (int i = 0; i < N; i++) {

		ver[i] = { sizep[i][0],sizep[i][1], sizep[i][2], sizep[i][3] };

	}




}



void draw_graph() {

	for (int i = 0; i < n; i++) {

		FillRect(hdc, &ver[i], brush[i]);

	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {


			if (matrix[i][j] == 1)draw_line(i, j);


		}

	}


}
