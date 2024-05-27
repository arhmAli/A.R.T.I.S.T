import rospy as rp
from sensor_msgs.msg import LaserScan
import math as mt

def lidar_pub():
	rp.init_node('lidar_publisher',anonymous=True)
	lidar_pub=rp.Publisher('/lidar_data',LaserScan,queue_size=5)
	rate=rp.Rate(20)
	
	while not rp.is_shutdown():
		lidar_data=LaserScan()
		lidar_data.header.stamp=rp.Time.now()
		lidar_data.header.frame_id='lidar_frame'
		lidar_data.angle_min=0.0
		lidar_data.angle_max=2*mt.pi
		lidar_data.angle_increment=2*(mt.pi)/360
		lidar_data.range_min=0.1
		lidar_data.range_max=10
		lidar_data.ranges=[1.0*mt.sin(i*mt.pi/180)for i in range(0,180)]
		lidar_pub.publish(lidar_data)
		rate.sleep()
		
if __name__=='__main__':
	try:
	    lidar_pub()
	except rp.ROSInterruptException:
	   pass
		
