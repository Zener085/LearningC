#include <iostream>
#include <string>
#include <fstream>

struct Node {
    int value;
    Node* next;
};

/// swap 2 adjacent nodes
///@param head the first node from linked list
Node* swapPairs(Node* head) {
    if (head == nullptr) return nullptr; // if there is no elements in the linked list
    if (head -> next == nullptr) return head; // if there is only 1 element in the linked list

    Node* prev = nullptr; // previous element
    Node* current = head; // current element
    Node* next_ = head -> next; // next element

    while (next_ != nullptr) { // go while not finding the last element
        current -> next = next_ -> next;
        next_ -> next = current;

        if (prev == nullptr) { // swap the first 2 elements
            prev = next_;
            head = prev;
            prev = prev -> next;
        } else { // next elements swap with each other
            prev -> next = next_;
            prev = prev -> next -> next;
        }

        current = current -> next;

        if (current == nullptr) break; // if there is the last element

        next_ = next_ -> next -> next -> next; // go to the next pairs
    }
    return head;
}

/// Parse numbers from the string to an array + calculate size of the array
///@param str main string containing all numbers
///@param size_ size of the array
int* parse_string_to_nodes(const std::string& str, int& size_) {
    int* arr = new int[str.size() / 2]; // array for storing numbers
    int k = 0; // number of numbers stored to the array
    char temp = ' '; // previous character
    for (char c : str) {
        if ('0' <= c && c <= '9') {
            if ('0' <= temp && temp <= '9')
                arr[k] = arr[k] * 10 + (int) (c - '0'); // increase number if it's the same number (with no spaces between digits)
            else {
                arr[k] = (int) (c - '0');
            }
        }
        else k++; // increase number of numbers
        temp = c;
    }
    size_ = ++k; // save actual size
    return arr;
}

/// initialize the first element to the linked list
///@param head first Node
///@param val value of the first element
void initNode(int val, Node* (&head)){
    head -> value = val;
    head -> next = nullptr;
}

/// Add new element to linked list
///@param head actual node
///@param val value of the element
void addNode(int val, Node* (&head)){
    Node *nextNode = new Node; // temp Node
    nextNode -> value = val; // store value
    nextNode -> next = head; // and store pointer to the previous node
    head = nextNode;
}

/// read string from input.txt and write swapped numbers to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string str; // string with numbers
    Node* head = new Node; // main Node
    int* nums; // array of numbers
    int size; // size of array

    input.open("input.txt");
    std::getline(input, str); // read string with numbers
    input.close();

    nums = parse_string_to_nodes(str, size); // store all numbers to array
    initNode(nums[size - 1], head); // store the first number

    for (int i = size - 2; i >= 0; i--) {
        addNode(nums[i], head); // add next number to linked list
    }

    head = swapPairs(head); // swap numbers

    output.open("output.txt");
    while (head != nullptr) {
        output << head -> value << " "; // print all numbers
        head = head -> next;
    }
    output.close();
}

int main() {
    in_out_file();

    return 0;
}
