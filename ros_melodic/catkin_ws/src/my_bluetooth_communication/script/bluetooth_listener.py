#!/usr/bin/env python

import rospy
from std_msgs.msg import String
import serial

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + " I heard %s", data.data)

def bluetooth_listener():
    ser = serial.Serial('/dev/rfcomm0', 9600)
    rospy.init_node('bluetooth_listener', anonymous=True)
    pub = rospy.Publisher('chatter', String, queue_size=10)

    while not rospy.is_shutdown():
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            rospy.loginfo(line)
            pub.publish(line)

    ser.close()

if __name__ == '__main__':
    try:
        bluetooth_listener()
    except rospy.ROSInterruptException:
        pass
