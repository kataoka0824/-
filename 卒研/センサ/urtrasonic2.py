import serial   #モジュール名はpyserialだが, importする際はserialである
import csv
def main():
    data=0
    inp=0
    str_data=[]
    l_str_data=[]
    l_float_data=[]
    with serial.Serial('/dev/ttyACM0',9600,timeout=1) as ser:
        while True:
            if inp==0:
                flag=bytes(input(),'utf-8')
                #シリアル通信で文字を送信する際は, byte文字列に変換する
                #input()する際の文字列はutf-8

                ser.write(flag)
                inp=1
            #シリアル通信:送信
                if(flag==bytes('q','utf-8')):
                    break;
            data=ser.readline()
            #str_data.append(data.decode('utf-8'))
            str_data1=data.decode('utf-8')
            l_str_data.append(str_data1.split())
            #print(l_str_data)
            if data.decode('utf-8')=="stop\r\n":
                inp=0
        ser.close()
    for i in range(19):
        l_float_data.append([])
        for j in range(10):
            l_float_data[i].append(float(l_str_data[i*10+j+1][1]))
    print(l_float_data)    
    with open("sonicdata.csv","w") as f:
        writer=csv.writer(f)
        writer.writerows(l_float_data)
if __name__ == "__main__":
    main()
