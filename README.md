# Bài tập lớn Cấu trúc dữ liệu và giải thuật
## Yêu cầu cần có trước khi chạy: 
1. [Git](https://git-scm.com/)
2. C/C++ compiler, ở đây bọn em đang sử dụng [GCC with MinGW](https://www.msys2.org/)
3. [Python](https://www.python.org/)
## Hướng dẫn chạy 
### 1. Clone repo hoặc tải repo này về máy
   ```bash
   git clone https://github.com/quanghung4dhh/BTL_DSA.git
   cd BTL_DSA
   ```
### 2. Build file .exe, nếu sử dụng MinGW thì chạy lệnh
   ```bash
   mingw32-make
   ```
File `.exe` sẽ được build trong thư mục `build/`
### 3. Tạo file test
Chỉnh sửa dòng thứ 4 trong file `scripts/generate.py` số lượng dòng dữ liệu cần test <br>
```python
NUM_LINES = 20
```
### 4. Chạy file python để tạo dữ liệu
```bash
python scripts/generate.py
```
File dữ liệu `test.txt` sẽ được tạo ra trong thư mục `data/input/`
### 5. Chạy chương trình chính
```bash
.\build\btl_dsa.exe
```
Sau khi chạy chương trình cần nạp dữ liệu đã tạo bằng cách chọn option `5` và nhập `data/input/test.txt` <br>
**Lưu ý:** Khi chạy chương trình chính thì phải chạy từ thư mục gốc là `BTL_DSA`, nếu không khi nạp dữ liệu sẽ bị lỗi <br>
Sau khi nạp xong dữ liệu thì có thể dùng các option khác với dữ liệu đã nạp
# ENJOY!


