#include <iostream>
#include <vector>

using namespace std;

// Функции для вывода матрицы
bool isMatrixEmpty(const vector<vector<double>>& matrix) {
    return matrix.empty() || matrix[0].empty();
}


void printMatrix(const vector<vector<double>>& matrix) {
    if (!(isMatrixEmpty(matrix))) {
        cout << "\n" << "result:" << "\n";
        for (const auto& row : matrix) {
            for (double element : row) {
                cout << element << "\t";
            }
            cout << endl;
        }

    }
    
}

// Функция для вычисления минора матрицы
vector<vector<double>> getMinor(const vector<vector<double>>& matrix, int row, int col) {
    vector<vector<double>> minor;
    for (int i = 0; i < matrix.size(); ++i) {
        if (i != row) {
            vector<double> tempRow;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (j != col) {
                    tempRow.push_back(matrix[i][j]);
                }
            }
            minor.push_back(tempRow);
        }
    }
    return minor;
}

//  функция для вычисления определителя матрицы
double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();

    // Проверка на квадратность матрицы
    if (n != matrix[0].size()) {
        cerr << "Error: Matrix is not square." << endl;
        return 0.0;
    }

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    for (int i = 0; i < n; ++i) {
        vector<vector<double>> minor = getMinor(matrix, 0, i);
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(minor);
    }

    return det;
}

// Функция для нахождения обратной матрицы методом Гаусса-Жордана
vector<vector<double>> inverseMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();

    // Проверка на квадратность матрицы и ограничение размера до 3x3
    if (n != matrix[0].size() || n > 3) {
        cerr << "Error: The inverse of the matrix cannot be found because the matrix is not square or the maximum size of 3x3 has been exceeded." << endl;
        return vector<vector<double>>();
    }

    // Проверка на ненулевой детерминант
    double det = determinant(matrix);
    if (det == 0.0) {
        cerr << "Error: The inverse matrix cannot be found because the determinant is zero." << endl;
        return vector<vector<double>>();  // Возвращаем пустую матрицу
    }

    vector<vector<double>> augmentedMatrix(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = matrix[i][j];
            augmentedMatrix[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; ++i) {
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmentedMatrix[i][j] /= pivot;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmentedMatrix[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                }
            }
        }
    }

    vector<vector<double>> inverse(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverse;
}

// Функция для сложения двух матриц
vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();  // Предполагаем, что матрицы имеют одинаковый размер
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // Проверка на размеры матриц и ограничение на размер до 3x3
    if (rows1 != rows2 || cols1 != cols2 || rows1 > 3 || cols1 > 3) {
        cerr << "Error: Matrices are of different sizes or exceed the maximum size of 3x3." << endl;
        return vector<vector<double>>();  // Возвращаем пустую матрицу
    }

    vector<vector<double>> result(rows1, vector<double>(cols1, 0.0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Функция для умножения двух матриц
vector<vector<double>> multiplyMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // Проверка на возможность умножения матриц и ограничение на размер до 3x3
    if (cols1 != rows2 || rows1 > 3 || cols1 > 3 || cols2 > 3) {
        cerr << "Error: The matrices cannot be multiplied because the size conditions are not met or the maximum size of 3x3 is exceeded." << endl;
        return vector<vector<double>>();
    }

    vector<vector<double>> result(rows1, vector<double>(cols2, 0.0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

vector<vector<double>> readMatrixFromInput() {
    int rows, cols;

    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;

    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    vector<vector<double>> matrix(rows, vector<double>(cols, 0.0));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

