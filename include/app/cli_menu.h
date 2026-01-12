#ifndef CLI_MENU_H
#define CLI_MENU_H

#include "core/common_types.h"

/**
 * Hàm chạy vòng lặp chính của chương trình.
 * Hiển thị menu, nhận input và gọi các chức năng tương ứng.
 * @param root: Node gốc của cây cấu hình.
 */
void runApp(Node* root);

#endif // CLI_MENU_H