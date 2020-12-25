from math import cos, sin, pi, floor
from rplidar import RPLidar
import matplotlib as plt
lidar = RPLidar('/dev/ttyUSB0')
scan = lidarScan(ranges,angles);
plot(scan)
lidar.stop()
lidar.disconnect()
