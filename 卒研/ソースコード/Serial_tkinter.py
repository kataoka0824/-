# coding:utf-8
import serial
import time
import tkinter as tk
import sys
ser = serial.Serial('/dev/ttyACM0', 115200)

def close():
        sys.exit()
def move_left(event):
        ser.write(b'l')
def move_right(event):
        ser.write(b'r')
def move_up(event):
        ser.write(b'u')
def move_down(event):
        ser.write(b'd')
def move_stop(event):
        ser.write(b's')
#GUI
root=tk.Tk()
root.title("serial")
root.geometry("500x300")
text_explain=tk.Label(text="右,左,上,下の4つの方向キーで操作を行います")
text_explain.grid(row=0,column=0)
frame=tk.Frame(root,width=500,height=300)
root.bind('<Left>',move_left)
root.bind('<Right>',move_right)
root.bind('<Up>',move_up)
root.bind('<Down>',move_down)
root.bind('<space>',move_stop)
root.mainloop()
ser.close()
#シリアル通信
#ser.write('u'.encode('utf-8'))
#ser.write(b'u')
#time.sleep(0.5)
#ser.write('d'.encode('utf-8'))
#ser.write(b'd')
#time.sleep(0.5)
#ser.close()
