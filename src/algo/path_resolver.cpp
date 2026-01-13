#include "algo/path_resolver.h"  // 1. Header của chính nó

#include <iostream>
#include <vector>

#include "core/string_utils.h"  // 3. Để dùng hàm splitString
#include "ds/TreeLogic.h"       // 2. Để dùng các hàm findChildByName, createNode, addChild

using namespace std;

Node* findNodeByPath(Node* root, const string& path) {
  if (root == nullptr || path.empty()) return nullptr;

  // SỬ DỤNG VECTOR thay vì mảng động để không lo memory leak
  vector<string> parts = splitString(path, '/');

  Node* current = root;

  // Kiểm tra xem phần đầu của path có trùng tên Root không
  // Ví dụ: Root là "System", path là "System/Net/IP" -> OK
  // Nếu path là "Net/IP" -> Lỗi (tuỳ quy ước, ở đây code bạn đang bắt buộc có Root)
  if (parts.empty() || parts[0] != root->name) {
    return nullptr;
  }

  // Duyệt từ phần tử thứ 2 (index 1) trở đi
  for (size_t i = 1; i < parts.size(); i++) {
    current = findChildByName(current, parts[i]);
    if (current == nullptr) {
      return nullptr;  // Đường dẫn bị đứt đoạn
    }
  }

  return current;
}

Node* ensurePath(Node* root, const string& path) {
  if (root == nullptr || path.empty()) return nullptr;

  vector<string> parts = splitString(path, '/');

  Node* current = root;

  // Kiểm tra root
  if (parts.empty() || parts[0] != root->name) {
    // Có thể in lỗi hoặc trả về null tùy ý
    return nullptr;
  }

  // Duyệt từ index 1
  for (size_t i = 1; i < parts.size(); i++) {
    // Tìm thử xem có chưa
    Node* child = findChildByName(current, parts[i]);

    // Nếu chưa có thì tạo mới
    if (child == nullptr) {
      // Nếu thêm con vào nút lá thì sẽ xóa value nút ấy trước khi thêm con
      if (!current->value.empty()) {
        cout << "[Warning] Node '" << current->name << "' chuyen tu La thanh Cha. Xoa value cu: " << current->value << endl;
        current->value = "";  // XÓA GIÁ TRỊ CŨ
      }
      child = createNode(parts[i], "");  // Tạo node mới, value rỗng
      addChild(current, child);
    }

    // Đi xuống tầng tiếp theo
    current = child;
  }

  return current;
}

void setValueByPath(Node* root, const string& path, const string& value) {
  // Tận dụng hàm ensurePath để lấy node đích (nếu chưa có thì nó tự tạo)
  Node* node = ensurePath(root, path);

  if (node != nullptr) {
    // Nếu là nút cha thì sẽ không được thêm value
    if (node->firstChild != nullptr) {
      cout << "[Loi Logic] Node '" << node->name << "' dang la Node Cha (Module). Khong the gan gia tri!" << endl;
      return;
    }
    node->value = value;
    cout << "[Thanh cong] Da cap nhat node.\n";
  } else {
    // Có thể in log lỗi ở đây nếu muốn
    // cout << "Error: Cannot resolve path " << path << endl;
  }
}