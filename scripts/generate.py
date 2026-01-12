import random

# Cấu hình số lượng dòng muốn tạo
NUM_LINES = 10000
FILENAME = "../data/input/test.txt"

# Các từ khóa mẫu để ghép thành đường dẫn
roots = ["System", "Network", "Device", "App", "Log", "User"]
modules = ["Core", "Interface", "Driver", "Display", "Sound", "Power"]
sub_modules = ["Setting", "Config", "Param", "Status", "Error", "Buffer"]
params = ["Value", "ID", "Name", "Rate", "Min", "Max", "Mode"]

def generate_line():
    # Tạo path ngẫu nhiên: Root/Module/Sub/Param
    path = f"{random.choice(roots)}/{random.choice(modules)}/{random.choice(sub_modules)}/{random.choice(params)}_{random.randint(1, 100)}"
    
    # Tạo giá trị ngẫu nhiên
    value = random.randint(0, 9999)
    
    return f"{path}, {value}"

print(f"Dang tao {NUM_LINES} dong cau hinh...")

with open(FILENAME, "w") as f:
    for _ in range(NUM_LINES):
        line = generate_line()
        f.write(line + "\n")

print(f"Xong! File duoc luu tai: {FILENAME}")