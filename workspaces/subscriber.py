import rospy as rp
from sensor_msgs.msg import LaserScan

def process_lid(data):
	dist=data.ranges[0]
	if abs(dist-1.0)<0.9:
		rp.loginfo("distance is {} mtere".format(dist))
	else:
		rp.loginfo("far {} meter".format(dist))
		rp.loginfo("far {} meter".format(data.ranges))
		
def lid_call(data):
	try:
	    process_lid(data)
	except Exception as e:
 	    rp.logerr("error".format(e))
def lid_subs():
 	rp.init_node('lidar_subs',anonymous=True)
 	rp.Subscriber('/scan',LaserScan,lid_call)
 	rp.spin()
if __name__=='__main__':
 	lid_subs()
