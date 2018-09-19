#include <iostream>
using namespace std;

int main()
{
	int buf;
	int x, y, z;
	cin >> x >> y >> z;

	int **a = new int*[x];
	for (int i = 0; i < x; i++) {
		a[i] = new int[y];
	}

	int **b = new int*[x];
	for (int i = 0; i < x; i++) {
		b[i] = new int[y];
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < z; j++) {
			cin >> b[i][j];
		}
	}

	// matrix multiplication
	int **c = new int*[x];
	for (int i = 0; i < x; i++) {
		c[i] = new int[z];
	}

	for (int i = 0; i < x; i++){
		for (int j = 0; j < z; j++) {
			c[i][j] = 0;
			for (int k = 0; k < y; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
			}
		}
	}

	// show result array 
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < z; j++) {
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}