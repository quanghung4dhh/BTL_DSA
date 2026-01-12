#include <iostream>
#include "ds/TreeLogic.h" // Include logic vào để chạy

using namespace std;

int main() {
    cout << "=== TEST CAY VOI LINKED LIST (TU CAI DAT) ===" << endl;

    // 1. Test Tạo cây
    Node* root = createNode("Device1", ""); 
    Node* moduleA = createNode("ModuleA", "");
    Node* moduleB = createNode("ModuleB", ""); // Tạo thêm 1 module để test danh sách
    Node* sensor1 = createNode("Sensor1", "26C");

    cout << "[1] Tao Node: OK" << endl;

    // Nối dây: Device1 -> (ModuleA -> ModuleB)
    addChild(root, moduleA);
    addChild(root, moduleB);
    addChild(moduleA, sensor1); // ModuleA -> Sensor1

    cout << "[2] Add Child: OK" << endl;

    // 2. Test Tìm kiếm
    Node* found = findChildByName(root, "ModuleB");
    if (found != nullptr) {
        cout << "[3] Tim kiem (ModuleB): OK -> Thay " << found->name << endl;
    } else {
        cout << "[3] Tim kiem: FAILED" << endl;
    }

    // 3. Test Xóa
    // Xóa ModuleA (Con đầu), xem root có tự update firstChild sang ModuleB không
    cout << "Dang xoa ModuleA..." << endl;
    if (removeChild(root, "ModuleA")) {
        cout << "[4] Xoa ModuleA: OK" << endl;
    } else {
        cout << "[4] Xoa ModuleA: FAILED" << endl;
    }

    // Kiểm tra xem ModuleB còn đó không (Nó phải trở thành con đầu lòng mới)
    if (root->firstChild != nullptr && root->firstChild->name == "ModuleB") {
        cout << "[5] Kiem tra logic Linked List: OK (ModuleB da len lam con ca)" << endl;
    } else {
        cout << "[5] Kiem tra logic Linked List: FAILED" << endl;
    }

    // 4. Dọn dẹp
    freeTree(root);
    cout << "=== DA XOA BO NHO AN TOAN ===" << endl;

    return 0;
}