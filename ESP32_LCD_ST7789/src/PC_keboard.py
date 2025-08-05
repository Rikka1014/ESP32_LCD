# python
# 导入串口和键盘监听库
import serial
from pynput import keyboard

# 打开串口，端口号和波特率需根据实际情况修改
ser = serial.Serial('COM3', 115200)

# 键盘按下事件处理函数
def on_press(key):
    try:
        # 普通字符键，发送其字符
        data = str(key.char).encode()
        print(f"发送字符: {key.char}")
        ser.write(data)
    except AttributeError:
        # 特殊键（如方向键、回车等），发送其名称
        data = str(key).encode()
        print(f"发送特殊键: {key}")
        ser.write(data)

# 启动键盘监听，按下键时调用 on_press
with keyboard.Listener(on_press=on_press) as listener:
    print("开始监听键盘输入，按下任意键将发送到串口...")
    listener.join()