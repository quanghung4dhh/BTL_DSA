#include "app/config_io.h"

// 1. Include các module cần thiết
#include "core/string_utils.h"   // Để trim chuỗi
#include "algo/path_resolver.h"  // Để gọi setValueByPath (quan trọng nhất)
#include "algo/tree_traversal.h" // Để gọi collectAllPaths
#include <iostream>
#include <fstream>              // Thư viện đọc ghi file
#include <vector>

using namespace std;

bool loadConfigFile(const string& filepath, Node* root) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "[Error] Khong the mo file: " << filepath << endl;
        return false;
    }

    string line;
    int lineCount = 0;

    // Đọc từng dòng
    while (getline(file, line)) {
        lineCount++;
        
        // 1. Dọn dẹp dòng (xóa khoảng trắng thừa 2 đầu)
        string cleanLine = trimString(line);

        // Bỏ qua dòng trống hoặc dòng comment (bắt đầu bằng #)
        if (cleanLine.empty() || cleanLine[0] == '#') continue;

        // 2. Tìm vị trí dấu phẩy phân cách
        size_t commaPos = cleanLine.find(',');

        if (commaPos == string::npos) {
            // Nếu không có dấu phẩy -> Dòng lỗi, bỏ qua
            // cout << "[Warning] Line " << lineCount << " sai format (thieu dau phay)" << endl;
            continue;
        }

        // 3. Tách Path và Value
        // "System/IP , 1.1.1.1" 
        // -> pathStr = "System/IP "
        // -> valueStr = " 1.1.1.1"
        string pathStr = cleanLine.substr(0, commaPos);
        string valueStr = cleanLine.substr(commaPos + 1);

        // 4. Trim lần nữa cho chắc chắn sạch sẽ
        pathStr = trimString(pathStr);
        valueStr = trimString(valueStr);

        // 5. Gọi module Algo để đưa vào cây
        if (!pathStr.empty()) {
            setValueByPath(root, pathStr, valueStr);
        }
    }

    file.close();
    cout << "[Info] Da load xong file: " << filepath << endl;
    return true;
}

bool saveConfigFile(const string& filepath, Node* root) {
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "[Error] Khong the tao file: " << filepath << endl;
        return false;
    }

    // 1. Lấy toàn bộ danh sách đường dẫn từ cây
    vector<string> allLines; // Mảng lưu các đường dẫn từ cây
    // Gọi hàm collectAllPaths (đã viết ở module tree_traversal)
    collectAllPaths(root, "", allLines); 

    // 2. Ghi từng dòng vào file
    for (const string& line : allLines) {
        file << line << endl;
    }

    file.close();
    cout << "[Info] Da luu file thanh cong: " << filepath << endl;
    return true;
}