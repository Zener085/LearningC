#include <iostream>
#include <string>
#include <fstream>

struct Node {
    int value;
    Node* next;
};

Node* swapPairs(Node* head) {
    if (head == nullptr) return nullptr;
    if (head -> next == nullptr) return head;

    Node* prev = nullptr;
    Node* current = head;
    Node* next_ = head -> next;

    while (next_ != nullptr) {
        current -> next = next_ -> next;
        next_ -> next = current;

        if (prev == nullptr) {
            prev = next_;
            head = prev;
            prev = prev -> next;
        } else {
            prev -> next = next_;
            prev = prev -> next -> next;
        }

        current = current -> next;

        if (current == nullptr) break;

        next_ = next_ -> next -> next -> next;
    }
    return head;
}

int* parse_string_to_nodes(const std::string& str, int& size_) {
    int* arr = new int[str.size() / 2];
    int k = 0, size = 0;
    char temp = ' ';
    for (char c : str) {
        if ('0' <= c && c <= '9') {
            if ('0' <= temp && temp <= '9')
                arr[k] = arr[k] * 10 + (int) (c - '0');
            else {
                arr[k] = (int) (c - '0');
                size++;
            }
        }
        else k++;
        temp = c;
    }
    size_ = ++k;
    return arr;
}

void initNode(int val, Node* (&head)){
    head -> value = val;
    head -> next = nullptr;
}

void addNode(int val, Node* (&head)){
    Node *nextNode = new Node;
    nextNode -> value = val;
    nextNode -> next = head;
    head = nextNode;
}

/// read string from input.txt and write indices to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string str; // main string, for skipping string and string with words
    Node* head = new Node;
    int* nums;
    int size;

    input.open("input.txt");
    std::getline(input, str);
    input.close();

    nums = parse_string_to_nodes(str, size);
    initNode(nums[size - 1], head);

    for (int i = size - 2; i >= 0; i--) {
        addNode(nums[i], head);
    }

    head = swapPairs(head);

    output.open("output.txt");
    while (head != nullptr) {
        output << head -> value << " ";
        head = head -> next;
    }
//    output << head -> value << " ";
    output.close();
}

int main() {
    in_out_file();

    return 0;
}
