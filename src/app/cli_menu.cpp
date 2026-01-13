#include "app/cli_menu.h"

// Include tất cả các module đã viết
#include <iostream>
#include <limits>  // Để dùng numeric_limits
#include <string>
#include <vector>

#include "algo/path_resolver.h"   // Để tìm/thêm theo path
#include "algo/tree_traversal.h"  // Để in cây
#include "app/config_io.h"        // Để đọc/ghi file
#include "core/string_utils.h"    // Để cắt chuỗi xử lý logic xóa
#include "ds/TreeLogic.h"         // Để Add/Remove child

using namespace std;

// --- CÁC HÀM TIỆN ÍCH NỘI BỘ (HELPER FUNCTIONS) ---

// Xóa màn hình cho sạch (Hỗ trợ cả Windows và Linux/Mac)
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Dừng màn hình chờ người dùng đọc xong
void waitForKey() {
  cout << "\nAn Enter de tiep tuc...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa bộ đệm
  cin.get();                                            // Chờ nhấn phím
}

// Hàm nhập chuỗi an toàn (tránh bị trôi lệnh khi dùng chung với cin >> int)
string getLineSafe() {
  string str;
  getline(cin >> ws, str);  // ws giúp bỏ qua khoảng trắng thừa còn sót
  return trimString(str);
}

// Hàm tách logic Xóa Node phức tạp ra riêng
// Input: "Device/Module/Sensor" -> Tìm node cha "Device/Module" -> Xóa con "Sensor"
void handleRemovePath(Node* root) {
  cout << "Nhap duong dan can xoa (VD: System/Network): ";
  string path = getLineSafe();

  // 1. Tách chuỗi để lấy tên con cần xóa và đường dẫn cha
  // Ví dụ: "A/B/C" -> ParentPath: "A/B", ChildName: "C"
  size_t lastSlash = path.find_last_of('/');

  string parentPath;
  string childName;
  Node* parentNode = nullptr;

  if (lastSlash == string::npos) {
    // Trường hợp xóa node ngay dưới root (VD: "System")
    // Parent chính là root hiện tại (theo logic của bạn root là Node ảo hoặc tên hệ thống)
    // Tuy nhiên hàm removeChild cần parent cụ thể.
    // Giả sử path nhập vào là con trực tiếp của root:
    parentNode = root;
    childName = path;
  } else {
    parentPath = path.substr(0, lastSlash);
    childName = path.substr(lastSlash + 1);

    // Tìm node cha
    parentNode = findNodeByPath(root, parentPath);
  }

  if (parentNode == nullptr) {
    cout << "[Loi] Khong tim thay node cha cua duong dan nay!\n";
    return;
  }

  // Gọi hàm từ module DS
  bool result = removeChild(parentNode, childName);
  if (result) {
    cout << "[Thanh cong] Da xoa node: " << childName << endl;
  } else {
    cout << "[Loi] Khong tim thay node con: " << childName << " trong " << parentNode->name << endl;
  }
}

// --- HÀM CHÍNH ---

void runApp(Node* root) {
  int choice = 0;
  string path, value, filepath;

  while (true) {
    clearScreen();
    cout << "========================================\n";
    cout << "    HE THONG QUAN LY CAU HINH (TREE)    \n";
    cout << "========================================\n";
    cout << "Node Goc: " << root->name << "\n\n";

    cout << "1. Hien thi cay cau hinh (Print)\n";
    cout << "2. Tim kiem thong tin Node (Query)\n";
    cout << "3. Them hoac Sua Node (Add/Update)\n";
    cout << "4. Xoa Node (Remove Subtree)\n";
    cout << "5. Nap du lieu tu File (Load)\n";
    cout << "6. Luu du lieu ra File (Save)\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "========================================\n";
    cout << "Lua chon cua ban: ";

    // Kiểm tra nhập liệu số nguyên
    if (!(cin >> choice)) {
      cout << "Vui long nhap so!\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      waitForKey();
      continue;
    }

    cout << "\n----------------------------------------\n";

    switch (choice) {
      case 1:  // Print
        cout << "Cay hien tai:\n";
        printTreePretty(root, 0);
        break;

      case 2:  // Query
        cout << "Nhap duong dan (VD: SystemConfig/System/Net/IP): ";
        path = getLineSafe();
        {
          Node* result = findNodeByPath(root, path);
          if (result) {
            cout << "-> Tim thay Node: " << result->name << "\n";
            cout << "-> Gia tri (Value): " << (result->value.empty() ? "(Empty)" : result->value) << "\n";
            if (result->firstChild) {
              cout << "-> Node nay co chua node con.\n";
              cout << "\n--- CAU TRUC CAY CON (SUBTREE) ---\n";
              cout << result->name << endl;
              printTreePretty(result->firstChild, 1);  // In ra cây con
              cout << "----------------------------------\n";
            } else
              cout << "-> Day la node la.\n";
          } else {
            cout << "[!] Khong tim thay duong dan nay.\n";
          }
        }
        break;

      case 3:  // Add/Update
        cout << "Nhap duong dan (VD: SystemConfig/System/Limit): ";
        path = getLineSafe();
        cout << "Nhap gia tri (Value): ";
        value = getLineSafe();

        {
          bool success = setValueByPath(root, path, value);
          if (success) cout << "[Thanh cong] Da cap nhat node.\n";
        }
        break;

      case 4:  // Remove
        handleRemovePath(root);
        break;

      case 5:  // Load
        cout << "Nhap duong dan file (VD: data/input/config.txt): ";
        filepath = getLineSafe();
        loadConfigFile(filepath, root);
        break;

      case 6:  // Save
        cout << "Nhap ten file xuat ra (VD: config_out.csv): ";
        filepath = getLineSafe();
        saveConfigFile(filepath, root);
        break;

      case 0:  // Exit
        cout << "Dang thoat chuong trinh...\n";
        return;

      default:
        cout << "Lua chon khong hop le!\n";
    }

    waitForKey();  // Dừng màn hình để user xem kết quả
  }
}