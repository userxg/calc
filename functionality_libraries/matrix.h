#pragma once
#include "commands.h"

using namespace std;





class Matrix
{
private:
    enum complex_cmds { stop = 0, back = 1, cls = 2, this_secetion = 3, det = 101, rev = 102, add = 103, mult = 104 };
    commands cmds;

public:
    Matrix() : cmds(this_secetion) {}
    void work(bool& st)
    {
        bool back = true;
        bool& bk = back;
        matrix_interface();
        while (st && bk)
        {
            matrix(st, bk);
        }
    }

private:

    void matrix(bool& st, bool& bk)
    {
        string entered_command = "";
        cin >> entered_command;


        for (int i = 0; i < entered_command.length(); ++i)
            entered_command[i] = tolower(entered_command[i]);

        int chosen_command = cmds.identify(entered_command);

        switch (chosen_command)
        {
        case stop:
            cout << "-----------------------[ stop ]-----------------------" << "\n";
            st = false;
            break;
        case back:
            system("cls");
            bk = false;
            break;
        case cls:
            system("cls");
            matrix_interface();
            break;
        case det:
            determinant();
            break;
        case rev:
            reverse();
            break;
        case add:
            addition();
            break;
        case mult:
            multiplication();
            break;
        default:
            wrong_command();
            break;
        }
    }


    void determinant()
    {
        cout << "--------------------{ determinant }-------------------" << "\n";
        vector<vector<ld>> matrix = readMatrixFromInput();
        ld result = determinant(matrix);
        cout << "result:\n" << result;
    }

    void reverse()
    {
        cout << "-----------{ reverse matrix implementation }----------" << "\n";
        vector<vector<ld>> matrix = readMatrixFromInput();
        vector<vector<ld>> result = inversematrix(matrix);
        if (result.size())
            printMatrix(result);

    }

    void addition()
    {
        cout << "-------------{ mat + mat implementation }-------------" << "\n";
        vector<vector<ld>> matrix1 = readMatrixFromInput();
        vector<vector<ld>> matrix2 = readMatrixFromInput();
        vector<vector<ld>> result = addmatrices(matrix1, matrix2);
        if (result.size())
            printMatrix(result);
    }

    void multiplication()
    {
        cout << "-------------{ mat * mat implementation }-------------" << "\n";
        vector<vector<ld>> matrix1 = readMatrixFromInput();
        vector<vector<ld>> matrix2 = readMatrixFromInput();
        vector<vector<ld>> result = multiplymatrices(matrix1, matrix2);
        if (result.size())
            printMatrix(result);
    }


private:

    //interfaces
    //complex start interface
    void matrix_interface() const;

    void printMatrix(const vector<vector<ld>>& matrix)const
    {
        cout << "\n" << "result:" << "\n";
        for (const auto& row : matrix) {
            for (ld element : row) {
                cout << element << "\t";
            }
            cout << endl;
        }
    }

    vector<vector<ld>> readMatrixFromInput() {
        int rows, cols;

        cout << "Enter the number of rows in the matrix: ";
        cin >> rows;

        cout << "Enter the number of columns in the matrix: ";
        cin >> cols;

        vector<vector<ld>> matrix(rows, vector<ld>(cols, 0.0));

        cout << "---------{ Enter the elements of the matrix: }--------" << "\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }

        return matrix;
    }


    vector<vector<ld>> getminor(const vector<vector<ld>>& matrix, int row, int col) {
        vector<vector<ld>> minor;
        for (int i = 0; i < matrix.size(); ++i) {
            if (i != row) {
                vector<ld> temprow;
                for (int j = 0; j < matrix[i].size(); ++j) {
                    if (j != col) {
                        temprow.push_back(matrix[i][j]);
                    }
                }
                minor.push_back(temprow);
            }
        }
        return minor;
    }


    ld determinant(const vector<vector<ld>>& matrix) {
        int n = matrix.size();

        if (n != matrix[0].size()) {
            cerr << "error: matrix is ​​not square.\n" << endl;
            return 0.0;
        }

        if (n == 1) {
            return matrix[0][0];
        }

        if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }

        ld det = 0.0;
        for (int i = 0; i < n; ++i) {
            vector<vector<ld>> minor = getminor(matrix, 0, i);
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(minor);
        }

        return det;
    }

    vector<vector<ld>> inversematrix(const vector<vector<ld>>& matrix) {
        int n = matrix.size();


        if (n != matrix[0].size() || n > 3) {
            cerr << "error: the inverse of the matrix cannot be found because" << "\n" << "the matrix is ​​not square or the maximum size of 3x3 has been exceeded.\n" << endl;
            return vector<vector<ld>>();
        }

        ld det = determinant(matrix);
        if (det == 0.0) {
            cerr << "error: the inverse matrix cannot be found because the determinant is zero.\n" << endl;
            return vector<vector<ld>>();
        }


        vector<vector<ld>> augmentedmatrix(n, vector<ld>(2 * n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                augmentedmatrix[i][j] = matrix[i][j];
                augmentedmatrix[i][j + n] = (i == j) ? 1.0 : 0.0;
            }
        }


        for (int i = 0; i < n; ++i) {

            ld pivot = augmentedmatrix[i][i];
            for (int j = 0; j < 2 * n; ++j) {
                augmentedmatrix[i][j] /= pivot;
            }


            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    ld factor = augmentedmatrix[k][i];
                    for (int j = 0; j < 2 * n; ++j) {
                        augmentedmatrix[k][j] -= factor * augmentedmatrix[i][j];
                    }
                }
            }
        }


        vector<vector<ld>> inverse(n, vector<ld>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inverse[i][j] = augmentedmatrix[i][j + n];
            }
        }

        return inverse;
    }


    vector<vector<ld>> addmatrices(const vector<vector<ld>>& matrix1, const vector<vector<ld>>& matrix2) {
        int rows1 = matrix1.size();
        int cols1 = matrix1[0].size();
        int rows2 = matrix2.size();
        int cols2 = matrix2[0].size();

        if (rows1 != rows2 || cols1 != cols2 || rows1 > 3 || cols1 > 3) {
            cerr << "error: matrices are of different sizes or exceed the maximum size of 3x3.\n" << endl;
            return vector<vector<ld>>();
        }

        vector<vector<ld>> result(rows1, vector<ld>(cols1, 0.0));

        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        return result;
    }


    vector<vector<ld>> multiplymatrices(const vector<vector<ld>>& matrix1, const vector<vector<ld>>& matrix2) {
        int rows1 = matrix1.size();
        int cols1 = matrix1[0].size();
        int rows2 = matrix2.size();
        int cols2 = matrix2[0].size();


        if (cols1 != rows2 || rows1 > 3 || cols1 > 3 || cols2 > 3) {
            cerr << "error: the matrices cannot be multiplied because the size" << "\n" << "conditions are not met or the maximum size of 3x3 is exceeded.\n" << endl;
            return vector<vector<ld>>();
        }

        vector<vector<ld>> result(rows1, vector<ld>(cols2, 0.0));

        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                for (int k = 0; k < cols1; ++k) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }


        return result;
    }

    vector<vector<ld>> readmatrixfrominput() {
        int rows, cols;

        cout << "enter the number of rows in the matrix: ";
        cin >> rows;

        cout << "enter the number of columns in the matrix: ";
        cin >> cols;

        vector<vector<ld>> matrix(rows, vector<ld>(cols, 0.0));

        cout << "enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }

        return matrix;
    }


    //wrong
    void wrong_command() const;
};


