import rospy as rp
from sensor_msgs.msg import LaserScan

def scan_callback(msg):
	#front_distance=msg.ranges[len(msg.ranges)//2]
	ind=msg.ranges
	print(len(msg.ranges))
	lst=[]
	for i in msg.ranges:
		if i<=1.0:
			lst.append(i)
			print("The object is close at {} angle".format(ind.index(i)))
	print (lst)
	print ("There are total of {} angles in which there is something close".format(len(lst)))
rp.init_node('lidar_distance_monitor')
rp.Subscriber('/scan',LaserScan,scan_callback)
rp.spin()
