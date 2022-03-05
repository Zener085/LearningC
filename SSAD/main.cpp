#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> parse_string_to_matrix(const std::string& nums) {
    int num = 0, row = 0;
    int cols = 3;
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

std::vector<std::vector<int>> parse_and_find_inverse(const std::string& numbers) {
    std::vector<std::vector<int>> matrix = parse_string_to_matrix(numbers);

    return matrix;
}

/// read string with numbers for matrix from input.txt and write determinant of the matrix to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string numbers;

    input.open("input.txt");
    std::getline(input, numbers);
    input.close();

    std::vector<std::vector<int>> inverse = parse_and_find_inverse(numbers);

    output.open("output.txt");
    for (int i = 0; i < inverse.size(); i++) {
        for (int j = 0; j < inverse.size(); j++)
            output << inverse[i][j] << " ";
        output << "\n";
    }
    output.close();
}

int main() {
    in_out_file();

    return 0;
}
