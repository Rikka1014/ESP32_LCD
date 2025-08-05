import psutil
import GPUtil
import serial
import time
import json

# 串口设置，根据实际情况修改 COM 端口号和波特率
SERIAL_PORT = "COM3"
BAUD_RATE = 115200

def get_system_stats():
    # 获取 CPU 利用率
    cpu_percent = psutil.cpu_percent(interval=1)
    # 获取 RAM 使用率
    ram_percent = psutil.virtual_memory().percent
    # 获取 GPU 利用率，如果系统中没有 GPU 则返回 0
    try:
        gpus = GPUtil.getGPUs()
        if gpus:
            # 只取第一个 GPU 的负载，转换为百分比
            gpu_percent = gpus[0].load * 100
        else:
            gpu_percent = 0
    except Exception:
        gpu_percent = 0
    # 获取风扇转速（取第一个风扇的第一个转速值）
    try:
        fans = psutil.sensors_fans()
        if fans:
            # fans 是字典，取第一个风扇列表的第一个转速
            first_fan = next(iter(fans.values()))
            fan_speed = first_fan[0].current if first_fan else 0
        else:
            fan_speed = 0
    except Exception:
        fan_speed = 0

    return cpu_percent, gpu_percent, ram_percent, fan_speed

def main():
    # 打开串口连接
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    while True:
        cpu, gpu, ram, fan = get_system_stats()
        # 构造数据包（JSON 格式字符串）
        data = {
            "cpu": cpu,
            "gpu": gpu,
            "ram": ram,
            "fan": fan
        }
        data_packet = json.dumps(data)
        # 发送数据
        ser.write(data_packet.encode("utf-8"))
        print("数据已发送：", data_packet)
        time.sleep(0.2)

if __name__ == "__main__":
    main()
