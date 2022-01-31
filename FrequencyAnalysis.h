#ifndef LEARNINGC_FREQUENCYANALYSIS_H
#define LEARNINGC_FREQUENCYANALYSIS_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

void add_word(string &word, map<string, int> &words) {
    if (words.find(word) == words.end()) {
        words.insert(make_pair(word, 1));
    } else words[word]++;
}

string map_to_string(map<string, int> &words) {
    stringstream text;
    for (auto &word : words)
        text << word.first << " " << word.second << endl;
    return text.str();
}

void frequency_analysis() {
    string a;
    getline(cin, a);

    string str, word;
    getline(cin, str);

    map<string, int> words;

    for (char c : str) {
        if (c == ' ') {
            add_word(word, words);
            word = "";
        } else word += c;
    }
    add_word(word, words);
    cout << map_to_string(words);
}

#endif //LEARNINGC_FREQUENCYANALYSIS_H
