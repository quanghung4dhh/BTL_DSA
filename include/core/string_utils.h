#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

/**
 * Cắt chuỗi thành các phần nhỏ dựa trên ký tự ngăn cách.
 * @param str: Chuỗi đầu vào (VD: "A/B/C")
 * @param delimiter: Ký tự ngăn cách (VD: '/')
 * @return: Vector chứa các chuỗi con (VD: {"A", "B", "C"})
 */
std::vector<std::string> splitString(const std::string& str, char delimiter);

/**
 * Xóa khoảng trắng thừa ở đầu và cuối chuỗi.
 * Rất quan trọng khi đọc file text để tránh lỗi so sánh chuỗi.
 * @param str: Chuỗi đầu vào (VD: "  System Config  ")
 * @return: Chuỗi sạch (VD: "System Config")
 */
std::string trimString(const std::string& str);

#endif // STRING_UTILS_H