
# 导入所需库
import psutil  # 用于获取CPU和内存信息
import serial  # 用于串口通信
import time    # 用于延时
import struct  # 用于数据打包

# 获取GPU占用率，优先使用GPUtil库
try:
    import GPUtil
    def get_gpu_usage():
        """
        获取GPU占用率（百分比）。如无GPU或未安装GPUtil则返回0。
        """
        gpus = GPUtil.getGPUs()
        if gpus:
            return gpus[0].load * 100  # 百分比
        else:
            return 0.0
except ImportError:
    def get_gpu_usage():
        """
        未安装GPUtil时，返回0。
        """
        return 0.0

def get_cpu_usage():
    """
    获取CPU占用率（百分比）。
    """
    return psutil.cpu_percent(interval=1)

def get_mem_usage():
    """
    获取内存占用率（百分比）。
    """
    return psutil.virtual_memory().percent

def make_packet(cpu, gpu, mem):
    """
    构造数据包：
    [帧头(2字节)] [CPU(4字节float)] [GPU(4字节float)] [MEM(4字节float)] [校验(1字节)]
    校验为数据部分所有字节求和后取低8位。
    """
    header = b'\xAA\x55'  # 帧头
    data = struct.pack('fff', cpu, gpu, mem)  # 数据部分
    checksum = (sum(data) & 0xFF).to_bytes(1, 'little')  # 校验
    return header + data + checksum

def main():
    """
    主函数：循环获取系统资源占用率并通过串口发送数据包。
    串口参数请根据实际情况修改（如COM口号、波特率等）。
    """
    ser = serial.Serial('COM3', 115200, timeout=1)  # 打开串口
    try:
        while True:
            cpu = get_cpu_usage()  # 获取CPU占用率
            gpu = get_gpu_usage()  # 获取GPU占用率
            mem = get_mem_usage()  # 获取内存占用率
            packet = make_packet(cpu, gpu, mem)  # 构造数据包
            ser.write(packet)  # 发送数据包
            print(f"Sent: CPU={cpu:.1f}%, GPU={gpu:.1f}%, MEM={mem:.1f}%")  # 打印发送内容
            time.sleep(1)  # 每秒发送一次
    except KeyboardInterrupt:
        ser.close()  # 关闭串口

# 程序入口
if __name__ == "__main__":
    main()
