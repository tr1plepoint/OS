// OS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void multiply(vector<vector <int>>& matrixA, vector<vector <int>>& matrixB,
	vector<vector <int>>& matrixC, int row, int column, int n) {

	int sum = 0;

	for (int i = 0, j = 0; i < n; ++i, ++j) {
		sum += matrixA[row][i] * matrixB[j][column];
	}

	matrixC[row][column] = sum;
}

int main()
{
	int m = 3, n = 3;

	vector<vector<int> > a(n, vector<int>(m));
	vector<vector<int> > b(n, vector<int>(m));
	vector<vector<int> > c(n, vector<int>(m));


	cout << "Enter matrix A" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	cout << "Print matrix A" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "Enter matrix B" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}

	cout << "Print matrix B" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}

	//multiply


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			thread th1 = thread(multiply, ref(a), ref(b), ref(c), i, j, n);
			th1.join();

			//c[i][j] = multiply(a, b, i, j, n);

			//c[i][j] = 0;
			//for (int k = 0; k < n; k++)
				//c[i][j] += a[i][k] * b[k][j];
		}
	}

	cout << "Print matrix C" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}


}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
