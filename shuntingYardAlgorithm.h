#ifndef LEARNINGC_SHUNTINGYARDALGORITHM_H
#define LEARNINGC_SHUNTINGYARDALGORITHM_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <optional>

using namespace std;

template <typename T>
class MyStack {
    vector<T> items;

public:
    void push(T value) {
        items.push_back(value);
    }

    int size() {
        return items.size();
    }

    bool isEmpty(){
        return items.size() <= 0;
    }

    T peek(){
        if (isEmpty())
            return NULL;
        return items.back();
    }

    T pop() {
        if (isEmpty())
            return NULL;

        T item = peek();
        items.pop_back();

        return item;
    }

};

template <class T>
class MyQueue{
    list<T> items;

public:
    int size(){
        return items.size();
    }

    bool isEmpty(){
        return items.empty();
    }

    void offer(T value){
        items.push_back(value);
    }

    T poll(){
        if (isEmpty())
            return {};

        T item = items.front();
        items.pop_front();

        return item;
    }

    T peek(){
        if (isEmpty())
            return {};

        return items.front();
    }
};

bool whatCharIs(char c) {
    if (c <= 57 and c >= 48) return true;
    return false;
}

void shunting_yard(){
    MyStack<char> operators;
    MyQueue<char> text;
    int size = -1;

    string equation;

    getline(cin, equation);

    for (char c : equation) {
        if (c == ' ') {
            if (text.size() == size)
                text.offer(c);
            continue;
        }
        if (whatCharIs(c)) { text.offer(c); size = text.size(); }
        else {
            if (c == '(') operators.push(c);
            else {
                if (c == ')') {
                    while (operators.peek() != '(')
                        text.offer(operators.pop());
                    operators.pop();
                }
                else {
                    if (c == '+' or c == '-') {
                        while (operators.size() > 0 and operators.peek() != '(') {
                            text.offer(' '); text.offer(operators.pop());
                        }
                    } operators.push(c);
                }
            }
        }
    }
    for (int i = 0; i < operators.size(); i+=0) { text.offer(' '); text.offer(operators.pop()); }
    while (!text.isEmpty())
        cout << text.poll();
}

#endif //LEARNINGC_SHUNTINGYARDALGORITHM_H
