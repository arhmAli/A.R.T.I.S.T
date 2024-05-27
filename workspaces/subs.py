import rospy as rp
from sensor_msgs.msg import LaserScan

def lidar_data(msg):
	rp.loginfo("Lidar data %s",msg.range)
def lidar_listener():
	rp.init_node("lidar_listner",anonymous=True)
	lidar_topic='/scan'
	rp.Subscriber(lidar_topic,LaserScan,lidar_data)
	rp.loginfo("Listening lidar data on topic %s",lidar_topic)
	rp.spin()
if __name__=='__main__':
	try:
	    lidar_listener()
	except rp.ROSInterruptException:
	    pass
