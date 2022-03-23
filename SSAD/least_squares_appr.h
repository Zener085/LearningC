#ifndef SSAD_LEAST_SQUARES_APPR_H
#define SSAD_LEAST_SQUARES_APPR_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int n, m;

void transpose(vector<vector<double>>& A_T, const vector<vector<double>>& A) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A_T[j].push_back(A[i][j]);
}

void squared(vector<vector<double>>& A_S, const vector<vector<double>>& A_T, const vector<vector<double>>& A) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            double factor = 0;
            for (int k = 0; k < m; k++)
                factor += A_T[i][k] * A[k][j];
            A_S[i].push_back(factor);
        }
}

vector<vector<double>> getCofactor(const vector<vector<double>> A_S, int p, int q, int size) {
    vector<vector<double>> temp(size);
    int i = 0, j = 0;

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++) {
            if (row != p && col != q) {
                temp[i].push_back(A_S[row][col]);
                j++;
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    return temp;
}

double determinant(vector<vector<double>> A, const int size) {
    if (size == 1) return A[0][0];

    double det = 0;
    int sign = 1;

    for (int f = 0; f < size; f++) {
        det += sign * A[0][f] * determinant(getCofactor(A, 0, f, size), size - 1);
        sign = -sign;
    }

    return det;
}

void adJoint(vector<vector<double>>& A_AJ, const vector<vector<double>>& A_S) {
    if (n == 1) {
        A_AJ[0][0] = 1;
        return;
    }

    int sign;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            A_AJ[j].push_back((sign) * determinant(getCofactor(A_S, i, j, n), n-1));
        }
}

void inverse(vector<vector<double>>& A_I, const vector<vector<double>>& A_AJ, const double& det) {
    if (det == 0) return;

    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            A_I[i].push_back(A_AJ[i][j] / (det));
}

void multiply(vector<vector<double>>& A_IT, const vector<vector<double>>& A_T, const vector<vector<double>>& A_I) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double factor = 0;
            for (int k = 0; k < n; k++)
                factor += A_I[i][k] * A_T[k][j];
            A_IT[i].push_back(factor);
        }
    }
}

void findX(vector<double>& x, const vector<vector<double>>& A_IT, const vector<double>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double factor = 0;
            for (int k = 0; k < m; k++)
                factor += A_IT[i][k] * b[k];
            x[i] = factor;
        }
    }
}

/// read string with numbers for matrix from input.txt and write determinant of the matrix to the output.txt
void in_out_file() {
    ifstream input; // input file
    ofstream output; // output file

    input.open("input.txt");
    input >> n >> m;
    n += 1;

// matrix A, matrix b, matrix A transpose, matrix A squared, determinant, adJoint matrix A, matrix A inverse, matrix x
    vector<vector<double>> A(m), A_T(n), A_S(n), A_AJ(n), A_I(n), A_IT(n);
    vector<double> b(m), x(n);
    double a, det;

    for (int i = 0; i < m; i++) {
        A[i].push_back(1.00);
        for (int j = 1; j < n; j++) {
            input >> a;
            A[i].push_back(a);
        }
        input >> b[i];
    }

    input.close();

    // transpose matrix A
    transpose(A_T, A);

    // squared matrix
    squared(A_S, A_T, A);

    // determinant
    det = determinant(A_S, n);

    // adJoint matrix
    adJoint(A_AJ, A_S);

    // inverse matrix
    inverse(A_I, A_AJ, det);

    // transpose of inverse matrix
    multiply(A_IT, A_T, A_I);

    // x
    findX(x, A_IT, b);

    output.open("output.txt");

    // print matrix A
    output << "A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            output << setprecision(2) << fixed << A[i][j] << ' ';
        output << endl;
    }

    output << endl;

    // print matrix b
    output << "b:" << endl;
    for (int i = 0; i < m; i++)
        output << setprecision(2) << fixed << b[i] << endl;

    output << endl;

    // print matrix A transpose times A
    output << "A_T*A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            output << setprecision(2) << fixed << A_S[i][j] << ' ';
        output << endl;
    }

    output << endl;

    // print matrix (A transpose times A) inverse
    output << "(A_T*A)_-1:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            output << setprecision(2) << fixed << A_I[i][j] << ' ';
        output << endl;
    }

    output << endl;

    // print matrix (A transpose times A) inverse times A transpose
    output << "(A_T*A)_-1*A_T:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            output << setprecision(2) << fixed << A_IT[i][j] << ' ';
        output << endl;
    }

    output << endl;

    // print matrix (A transpose times A) inverse times A_T
    output << "x" << endl;
    for (int i = 0; i < n; i++)
        output << setprecision(2) << fixed << x[i] << endl;

    output.close();
}

#endif //SSAD_LEAST_SQUARES_APPR_H