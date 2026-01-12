#include "ds/TreeLogic.h"       // Include header của chính nó
#include "core/common_types.h"   // Include nơi chứa struct Node
#include <iostream>

#include <string>

using namespace std;

// 1. Hàm tạo Node mới
Node* createNode(string name, string value) {
    return new Node(name, value);
}

// 2. Hàm thêm con (Nối vào cuối danh sách liên kết của cha)
void addChild(Node* parent, Node* child) {
    if (parent == nullptr || child == nullptr) return;

    // Đảm bảo node con mới chưa dính dáng đến ai
    child->nextSibling = nullptr; 

    if (parent->firstChild == nullptr) {
        // Trường hợp 1: Cha chưa có con nào -> Đứa này làm con cả
        parent->firstChild = child;
    } else {
        // Trường hợp 2: Cha đã có con -> Phải chạy tìm đứa con út
        Node* current = parent->firstChild;
        while (current->nextSibling != nullptr) {
            current = current->nextSibling; // Nhảy sang đứa em tiếp theo
        }
        // Nối dây: Đứa út cũ trỏ sang đứa mới
        current->nextSibling = child;
    }
}

// 3. Hàm tìm con theo tên (Duyệt danh sách liên kết)
Node* findChildByName(Node* parent, string name) {
    if (parent == nullptr) return nullptr;

    Node* current = parent->firstChild; // Bắt đầu từ con cả
    while (current != nullptr) {
        if (current->name == name) {
            return current; // Tìm thấy
        }
        current = current->nextSibling; // Chuyển sang đứa em kế
    }
    return nullptr; // Đi hết danh sách mà không thấy
}

// 4. Hàm hủy cây (Đệ quy xóa sạch sẽ)
void freeTree(Node* root) {
    if (root == nullptr) return;

    // Bước 1: Duyệt và xóa tất cả các con của mình
    Node* child = root->firstChild;
    while (child != nullptr) {
        Node* nextNode = child->nextSibling; // Lưu lại địa chỉ đứa em trước khi xóa đứa anh
        freeTree(child); // Đệ quy: Xóa đứa anh và toàn bộ con cháu của nó
        child = nextNode; // Chuyển sang xử lý đứa em
    }

    // Bước 2: Xóa chính mình
    // cout << "Deleted: " << root->name << endl; // Bật dòng này nếu muốn xem log xóa
    delete root;
}

// 5. Hàm xóa một node con theo tên khỏi danh sách con của cha
bool removeChild(Node* parent, string childName) {
    if (parent == nullptr || parent->firstChild == nullptr) return false;

    Node* current = parent->firstChild;
    Node* prev = nullptr; // Con trỏ lưu node đứng ngay trước current

    while (current != nullptr) {
        if (current->name == childName) {
            // -- TÌM THẤY node cần xóa --
            
            // A. Ngắt kết nối khỏi danh sách
            if (prev == nullptr) {
                // Nếu nó là con đầu lòng: Cha trỏ thẳng sang đứa thứ 2
                parent->firstChild = current->nextSibling;
            } else {
                // Nếu nó ở giữa/cuối: Nối thằng trước với thằng sau (bỏ qua current)
                prev->nextSibling = current->nextSibling;
            }

            // Quan trọng: Cắt đứt dây với em của nó để hàm freeTree không xóa nhầm sang em
            current->nextSibling = nullptr; 

            // B. Hủy bộ nhớ của nhánh đó
            freeTree(current);
            return true;
        }

        // Cập nhật vị trí để duyệt tiếp
        prev = current;
        current = current->nextSibling;
    }

    return false; // Không tìm thấy
}