import rospy as rp
from sensor_msgs.msg import LaserScan  # Using the standard ROS message type

def lid_data(data):
    lst = data.ranges
    arr = []
    for i in lst:
        if i <= 1:  # Adjust the threshold as needed
            arr.append(i)

    print("There are {} obstacles in the way".format(len(arr)))
    for i in arr:
        print("Obstacle detected at {} angle".format(i))  # Print angle of each obstacle

if __name__ == '__main__':
    rp.init_node('lidar_data')  # Initialize ROS node
    rp.Subscriber('/scan', LaserScan, lid_data)  # Subscribe to /scan topic
    rp.spin()  # Keep the node running
