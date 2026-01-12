# 1. Trình biên dịch và Cờ
CXX = g++
CXXFLAGS = -Iinclude -Wall -g

# 2. Thiết lập thư mục đầu ra
BUILD_DIR = build
TARGET_NAME = btl_dsa
# Đường dẫn đầy đủ đến file exe: build/config_tree_app.exe
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

# 3. Danh sách file nguồn (Source)
SRCS = src/main.cpp \
       src/core/string_utils.cpp \
       src/ds/TreeLogic.cpp \
       src/algo/path_resolver.cpp \
       src/algo/tree_traversal.cpp \
       src/app/config_io.cpp \
       src/app/cli_menu.cpp

# 4. Tạo danh sách file object (.o) tương ứng trong thư mục build
# Ví dụ: src/main.cpp -> build/src/main.o
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# 5. Quy tắc biên dịch file chạy (Link)
$(TARGET): $(OBJS)
	@echo "Dang lien ket (Linking)..."
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "=========================================="
	@echo "Build thanh cong! File chay nam tai:"
	@echo "   $(TARGET).exe"
	@echo "=========================================="

# 6. Quy tắc biên dịch từng file .cpp thành .o
# $@: Tên file mục tiêu (build/src/.../file.o)
# $<: Tên file nguồn (src/.../file.cpp)
# $(dir $@): Lấy đường dẫn thư mục chứa file .o để tạo folder nếu chưa có
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Dang bien dich: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 7. Lệnh chạy nhanh (gõ: make run)
run: $(TARGET)
	./$(TARGET)

# 8. Lệnh dọn dẹp (Xóa toàn bộ thư mục build)
clean:
	rm -rf $(BUILD_DIR)

# Hỗ trợ Windows (nếu lệnh rm -rf không chạy được trên CMD thường)
clean_win:
	rmdir /s /q $(BUILD_DIR)