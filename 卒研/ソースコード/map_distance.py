import numpy as np
from math import pi
import matplotlib.pyplot as plt
import csv
with open('map_a_d_data.csv') as f:
    reader = csv.reader(f)
    scan_data = [row for row in reader]
x=[]
y=[]
for i in range(len(scan_data)):
    scan_data[i][0]=float(scan_data[i][0])
    scan_data[i][1]=float(scan_data[i][1])
    x.append(float(scan_data[i][0])*pi/180)
    y.append(float(scan_data[i][1]))
#print(x)
#print(y)
ax=plt.subplot(111,polar=True)
#ax.set_ylim(0.0, 500.0)
ax.scatter(x,y,color="red",s=1)
#ax.grid(axis='y', color='green', lw=1)
plt.show()    
    
    
