#include "algo/tree_traversal.h"
#include <iostream>

using namespace std;

void printTreePretty(Node* node, int level) {
    if (node == nullptr) return;

    // 1. In node hiện tại
    // In khoảng trắng thụt đầu dòng
    for (int i = 0; i < level * 2; i++) {
        cout << " ";
    }

    // In tên và giá trị
    cout << node->name;
    if (!node->value.empty()) {
        cout << " : " << node->value;
    }
    cout << endl;

    // 2. Đệ quy xuống con đầu lòng (tăng level)
    printTreePretty(node->firstChild, level + 1);

    // 3. Đệ quy sang em kế tiếp (giữ nguyên level)
    // Lưu ý: Đệ quy này nằm ngoài if/else của con, để đảm bảo luôn được gọi
    printTreePretty(node->nextSibling, level);
}

void collectAllPaths(Node* node, string currentPath, vector<string>& results) {
    if (node == nullptr) return;

    // 1. Xây dựng đường dẫn hiện tại
    string newPath;
    if (currentPath.empty()) {
        newPath = node->name;
    } else {
        newPath = currentPath + "/" + node->name;
    }

    // 2. Kiểm tra nếu là Node Lá -> Lưu vào danh sách kết quả
    if (node->firstChild == nullptr) {
        // Format: "Device/Module/Param, 100"
        string fullLine = newPath;
        if (!node->value.empty()) {
             fullLine += ", " + node->value;
        }
        results.push_back(fullLine); 
        // LƯU Ý: Không được return ở đây! Phải đi tiếp để thăm anh em.
    }

    // 3. Đi xuống con (Depth First)
    collectAllPaths(node->firstChild, newPath, results);

    // 4. Đi sang anh em (Sibling) - Quan trọng: Giữ nguyên currentPath cũ
    collectAllPaths(node->nextSibling, currentPath, results);
}