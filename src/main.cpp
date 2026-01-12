#include <iostream>
#include "core/common_types.h"  // Cần struct Node
#include "ds/TreeLogic.h"       // Cần hàm createNode, freeTree
#include "app/cli_menu.h"       // Cần hàm runApp

using namespace std;

int main() {
    // 1. Khởi tạo cây với Node gốc
    // Tên gốc có thể là "SystemConfig", "Root", hoặc tên thiết bị
    cout << "[Init] Dang khoi tao he thong..." << endl;
    Node* root = createNode("SystemConfig", "");

    // 2. Chạy ứng dụng (Vòng lặp menu nằm trong này)
    // Chương trình sẽ kẹt ở đây cho đến khi user chọn "Exit"
    runApp(root);

    // 3. Dọn dẹp bộ nhớ trước khi tắt hẳn
    // Đây là bước quan trọng để tránh Memory Leak
    cout << "[Exit] Dang giai phong tai nguyen..." << endl;
    freeTree(root);
    
    cout << "Bye bye!" << endl;
    return 0;
}