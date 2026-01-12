#include "core/string_utils.h"
#include <sstream>
#include <iostream>

using namespace std;

// Hàm cắt chuỗi
vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);

    // Dùng getline để đọc từng phần dựa trên delimiter
    while (getline(ss, token, delimiter)) {
        // Trước khi thêm vào, nên trim luôn để sạch đẹp
        string cleanToken = trimString(token);
        
        // Chỉ thêm nếu chuỗi không rỗng (tránh trường hợp "A//B")
        if (!cleanToken.empty()) {
            tokens.push_back(cleanToken);
        }
    }
    return tokens;
}

// Hàm xóa khoảng trắng đầu/cuối
string trimString(const string& str) {
    if (str.empty()) return "";

    // Tìm vị trí ký tự đầu tiên không phải là khoảng trắng
    size_t first = str.find_first_not_of(" \t\n\r");
    
    // Nếu toàn bộ chuỗi là khoảng trắng
    if (first == string::npos) return "";

    // Tìm vị trí ký tự cuối cùng không phải là khoảng trắng
    size_t last = str.find_last_not_of(" \t\n\r");

    // Cắt chuỗi con từ first đến last
    return str.substr(first, (last - first + 1));
}