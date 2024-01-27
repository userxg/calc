#include <iostream>
#include <vector>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            cout << element << "\t";
        }
        cout << endl;
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
    if (matrix.size() == 1) {
        return matrix[0][0];
    }

    if (matrix.size() == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    for (int i = 0; i < matrix.size(); ++i) {
        vector<vector<double>> minor = getMinor(matrix, 0, i);
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(minor);
    }

    return det;
}
// Функция для нахождения обратной матрицы методом Гаусса-Жордана
vector<vector<double>> inverseMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
   
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
    int rows = matrix1.size();
    int cols = matrix1[0].size();  // Предполагаем, что матрицы имеют одинаковый размер

    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
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

    // Проверка на возможность умножения матриц
    if (cols1 != rows2) {
        cerr << "It is not possible to multiply matrices: the number of columns of the first matrix does not match the number of rows of the second matrix." << endl;
        return vector<vector<double>>();  // Возвращаем пустую матрицу
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
