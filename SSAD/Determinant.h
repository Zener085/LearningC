#ifndef SSAD_DETERMINANT_H
#define SSAD_DETERMINANT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> parse_string_to_matrix(const std::string& nums) {
    int num = 0, row = 0;
    int cols = (int) std::count(nums.begin(), nums.end(), '{') - 1;
    std::vector<std::vector<int>> matrix(cols);

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
            matrix[row].push_back(num);
            num = 0;
            if (prev == '}') {
                row++;
            }
        }
        prev = c;
    }
    matrix[row].push_back(num);

    return matrix;
}

int determinant(const std::vector<std::vector<int>>& matrix) {
    if (matrix.size() == 1) return matrix[0][0];

    int det = 0;

    for (int i = 0; i < matrix.size(); i++) {
        std::vector<std::vector<int>> sub(matrix.size() - 1);
        for (int j = 1; j < matrix.size(); j++) {
            for (int k = 0; k < matrix.size(); k++) {
                if (k != i) sub[j-1].push_back(matrix[j][k]);
            }
        }
        for (int j = 0; j < sub.size(); j++) {
            for (int k = 0; k < sub.size(); k++) {
                std::cout << sub[j][k] << " ";
            }
            std::cout << "\n";
        }

        det += (i % 2 == 0 ? determinant(sub) * matrix[0][i] : -determinant(sub) * matrix[0][i]);
    }
    return det;
}

int parse_and_find_det(const std::string& numbers) {
    std::vector<std::vector<int>> matrix = parse_string_to_matrix(numbers);

    return determinant(matrix);
}

/// read string with numbers for matrix from input.txt and write determinant of the matrix to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string numbers;

    input.open("input.txt");
    std::getline(input, numbers);
    input.close();

    output.open("output.txt");
    output << parse_and_find_det(numbers);
    output.close();
}

#endif //SSAD_DETERMINANT_H
