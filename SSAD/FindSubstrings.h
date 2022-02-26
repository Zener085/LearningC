#ifndef SSAD_FINDSUBSTRINGS_H
#define SSAD_FINDSUBSTRINGS_H

#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

///Creator vector of words from one string, taken from input file
///@param str string with words
///@return vector of words
std::vector<std::string> parse_string_to_vector(const std::string& str){
    std::vector<std::string> words; // vector of words
    std::string word; // one word

    for (auto c : str) {
        if (c == ' ') { // if word is ended
            words.push_back(word);
            word = "";
            continue;
        }
        word += c; // else increase word
    }
    words.push_back(word); // add the last word

    return words;
}

/// Create and return vector of indices, where there is substring starts
///@param str main string
///@return vector of indices, where each substring starts
std::vector<int> substring(const std::string& str, const std::string& words_) {
    std::vector<std::string> words = parse_string_to_vector(words_); // vector of all words the program has to find
    std::vector<int> result; // vector of indices of starting substring

    // size of one word, number of words in vector words and size of all substring
    int size = (int) words[0].size(), count = (int) words.size(), all_size = size * count;

    if (all_size > str.size()) // if the main string is smaller than size of all words in vector
        return result;

    std::unordered_map<std::string, int> hash_words; // stores words and indices of them

    for (int i = 0; i < count; i++) // initialize all words indices in hash map
        hash_words[words[i]]++;

    for (int i = 0; i <= str.size() - all_size; i++) {
        // create temp variables
        std::unordered_map<std::string, int> temp_hash(hash_words); // hash map
        int j = i, temp_count = count; // index of loop and number of words

        while (j < i + all_size) {
            std::string word = str.substr(j, size); // decrease size of string to 1 word

            if (hash_words.find(word) == hash_words.end() || temp_hash[word] == 0) // if we do not find word
                break;
            else {
                --temp_hash[word]; // else decrease for this word calculations
                --temp_count;
            }
            j += size;
        }
        if (temp_count == 0) // if the program found all words in substring
            result.push_back(i); // store index of start the iteration calculation
    }
    return result;
}

/// read string from input.txt and write indices to the output.txt
[[maybe_unused]] void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string str, null_str, words; // main string, for skipping string and string with words

    input.open("input.txt");
    std::getline(input, str); // read main string
    std::getline(input, null_str); // just skip one string
    std::getline(input, words); // read words that it has to find
    input.close();

    output.open("output.txt");
    std::vector<int> indices = substring(str, words);
    for (int index : indices) // write all indices
        output << index << " ";
    output.close();
}

#endif //SSAD_FINDSUBSTRINGS_H
