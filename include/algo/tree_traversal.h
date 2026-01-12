#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#include "core/common_types.h"
#include <string>
#include <vector>

// In cây ra màn hình console (thụt đầu dòng theo level)
void printTreePretty(Node* node, int level);

// Duyệt cây để lấy tất cả đường dẫn (Dùng để Save file)
// Input: node gốc, đường dẫn cha (ban đầu để rỗng)
// Output: results (vector chứa các chuỗi "Path, Value")
void collectAllPaths(Node* node, std::string currentPath, std::vector<std::string>& results);

#endif