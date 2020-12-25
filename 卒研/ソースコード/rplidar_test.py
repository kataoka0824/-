from rplidar import RPLidar
import csv

lidar = RPLidar('/dev/ttyUSB0')
scan_list=[]
scan_all=[]
info = lidar.get_info()
print(info)
health = lidar.get_health()
print(health)

#data=lidar.iter_scans()
#print(data)
for i, scan in enumerate(lidar.iter_scans()):
    print('%d: Got %d measurments' % (i, len(scan)))
    scan_all.extend(scan)
    if i == 4:
        break
for i in range(len(scan_all)):
    scan_list.append(list(scan_all[i][1:3]))
print(scan_list)
with open('map_a_d_data.csv', 'w') as f:
    writer = csv.writer(f)
    writer.writerows(scan_list)
lidar.stop()
lidar.stop_motor()
lidar.disconnect()
