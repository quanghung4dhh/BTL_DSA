#ifndef PATH_RESOLVER_H
#define PATH_RESOLVER_H

#include "core/common_types.h"
#include <string>

// Tìm node, trả về nullptr nếu không thấy
Node* findNodeByPath(Node* root, const std::string& path);

// Tìm node, nếu thiếu node nào trên đường đi thì tự tạo mới
Node* ensurePath(Node* root, const std::string& path);

// Gán giá trị cho node theo đường dẫn (tự tạo path nếu thiếu)
bool setValueByPath(Node* root, const std::string& path, const std::string& value);

#endif