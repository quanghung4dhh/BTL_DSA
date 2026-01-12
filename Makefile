# Makefile đơn giản cho Windows
CXX = g++
CXXFLAGS = -Iinclude -Wall -g

# Tên file chạy
TARGET = build/btl_dsa.exe

# Danh sách file nguồn
SRCS = src/main.cpp \
       src/core/string_utils.cpp \
       src/ds/TreeLogic.cpp \
       src/algo/path_resolver.cpp \
       src/algo/tree_traversal.cpp \
       src/app/config_io.cpp \
       src/app/cli_menu.cpp

# Quy tắc build: Gom tất cả build 1 lần (đỡ phải tạo folder .o lằng nhằng)
all: dir $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@echo "Build xong! Chay: $(TARGET)"

# Tạo thư mục build nếu chưa có (lệnh Windows)
dir:
	@if not exist build mkdir build

# Lệnh clean cho Windows
clean:
	@if exist build rmdir /s /q build