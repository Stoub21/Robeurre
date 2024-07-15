#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup()
{
  // Initialize the ROS node
  nh.initNode();

  // Advertise the "chatter" topic
  nh.advertise(chatter);
}

void loop()
{
  // Publish a message to the "chatter" topic
  str_msg.data = "Hello, ROS over Bluetooth 1!";
  chatter.publish(&str_msg);

  // Handle all communications and keep the node alive
  nh.spinOnce();

  // Delay to reduce the publishing rate
  delay(1000);
}

