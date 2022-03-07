#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

#define N 3

/// parse string to matrix of numbers
void parse_string_to_matrix(const std::string& nums, int matrix[N][N]) {
    int num = 0, col = 0, row = 0;

    // store numbers to matrix
    char prev = ' ';
    for (char c : nums) {
        if ('0' <= c && c <= '9') {
            if ('0' <= prev && prev <= '9') {
                num = num * 10 + (int) (c - '0');
            } else {
                num = (int) (c - '0');
            }
        } else if (c == ',') {
            matrix[row][col++] = num;
            num = 0;
            if (prev == '}') { row++; col = 0; }
        }
        prev = c;
    }
    matrix[row][col] = num;
}

/// Get cofactor of a matrix
///@param matrix origin matrix
///@param temp temporary matrix
///@param n number of rows/cols of origin matrix
///@param r number of row of cofactor
///@param c number of column of cofactor
void getCofactor(int matrix[N][N], int temp[N][N], int r, int c, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != r && col != c) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/// Calculate determinant of a matrix
///@param matrix matrix from what the program find determinant
///@param n number of rows/columns in matrix
int determinant(int matrix[N][N], int n) {
    int D = 0;

    if (n == 1)
        return matrix[0][0];

    int temp[N][N];

    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        getCofactor(matrix, temp, 0, f, n);
        D += sign * matrix[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }

    return D;
}

/// Get adjudicate matrix
///@param matrix matrix from what the program calculate adjudicate matrix
///@param adj adjudicate matrix
void adJoint(int matrix[N][N],int adj[N][N]) {
    int temp[N][N];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            getCofactor(matrix, temp, i, j, N);

            adj[j][i] = (((i+j)%2==0) ? determinant(temp, N-1) : -determinant(temp, N-1));
        }
    }
}

/// Get inverse matrix
///@param matrix origin matrix
///@param inverse inverse matrix
void get_inverse(int matrix[N][N], float inverse[N][N]) {
    int det = determinant(matrix, N);

    int ad_joint[N][N];
    adJoint(matrix, ad_joint);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = (float) ad_joint[i][j] / (float) det;
}

/// read string with numbers for matrix from input.txt and write determinant of the matrix to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string numbers;

    input.open("input.txt");
    std::getline(input, numbers);
    input.close();

    int matrix[N][N];

    parse_string_to_matrix(numbers, matrix);

    float inverse[N][N];

    get_inverse(matrix, inverse);

    output.open("output.txt");
    output << std::fixed;
    for (auto & row : inverse) {
        for (float num : row)
            output << std::setprecision(2) << std::fixed << num << " ";
        output << "\n";
    }
    output.close();
}

int main() {
    in_out_file();

    return 0;
}
