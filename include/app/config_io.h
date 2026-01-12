#ifndef CONFIG_IO_H
#define CONFIG_IO_H

#include <string>
#include "core/common_types.h" // Cần để biết Node* là gì

/**
 * Đọc file cấu hình và nạp dữ liệu vào cây.
 * Format file: Path, Value (VD: System/Net/IP, 192.168.1.1)
 * @param filepath: Đường dẫn file (VD: "data/input/config.txt")
 * @param root: Node gốc của cây
 * @return: true nếu đọc thành công, false nếu lỗi mở file.
 */
bool loadConfigFile(const std::string& filepath, Node* root);

/**
 * Xuất toàn bộ cấu hình cây ra file.
 * @param filepath: Đường dẫn file cần lưu
 * @param root: Node gốc của cây
 * @return: true nếu ghi thành công.
 */
bool saveConfigFile(const std::string& filepath, Node* root);

#endif // CONFIG_IO_H