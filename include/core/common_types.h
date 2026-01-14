#ifndef COMMON_TYPES_H 
#define COMMON_TYPES_H

#include <string>   


struct Node {
    std::string name;
    std::string value;     
    Node* firstChild;   // Con đầu tiên (Head of list con) Singly linked list
    Node* nextSibling;  // Người em kế tiếp (Next trong list con) Singly linked list

    // Constructor
    Node(std::string n, std::string v = "") {
        name = n;
        value = v;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

enum ErrorCode {
    SUCCESS = 0,
    ERR_NOT_FOUND = 1,
    ERR_INVALID_PATH = 2
};

#endif