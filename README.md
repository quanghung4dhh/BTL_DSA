# Bài tập lớn Cấu trúc dữ liệu và giải thuật
## Cấu trúc thư mục:
-	build: Folder chứa file .exe được build ra
-	data: Folder chứa file dữ liệu test
-	docs: Folder chứa file báo cáo bài tập lớn
-	include: Folder chứa các folder con: algo, app, core, ds. Đây là nơi chứa các file thư viện header .h
-	scripts: Folder chứa file generate.py là file để tạo ra file test dữ liệu
-	src: Folder chứa các source code, chứa các file .cpp viết logic các hàm đã định nghĩa trong các file .h trên. Bên trong có file main.cpp là file chạy chính
-	tests: Folder chứa các file test độc lập các file .h và .cpp tương ứng
-	.gitignore: File ignore của git để không track các folder rác, không cần thiết
-	Makefile: File tự động hóa quá trình biên dịch (compile) và xây dựng (build) phần mềm ra .exe
-	README.md: File text gồm các hướng dẫn chạy, các chi tiết khác của dự án như tính năng, giải thích cây thư mục…

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
cd scripts
python generate.py
cd ..
```
File dữ liệu `test.txt` sẽ được tạo ra trong thư mục `data/input/`
### 5. Chạy chương trình chính
```bash
.\build\btl_dsa.exe
```
Sau khi chạy chương trình cần nạp dữ liệu đã tạo bằng cách chọn option `5` và nhập `data/input/test.txt` <br>
## Lưu ý: 
1. Khi chạy chương trình chính thì phải chạy từ thư mục gốc là `BTL_DSA`, nếu không khi nạp dữ liệu sẽ bị lỗi
2. Nếu chạy thẳng trực tiếp file `btl_dsa.exe` thì phải nhập đường dẫn là `../data/input/test.txt`
3. Sau khi nạp xong dữ liệu thì có thể dùng các option khác với dữ liệu đã nạp
# ENJOY!




