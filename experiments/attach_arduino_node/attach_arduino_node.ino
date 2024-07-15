#include <ros.h>
#include <std_msgs/String.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup() {
  bluetooth.begin(9600);
  nh.getHardware()->setClient(&bluetooth);
  nh.initNode();
  nh.advertise(chatter);
}

void loop() {
  if (nh.connected()) {
    str_msg.data = "Hello, world!";
    chatter.publish(&str_msg);
    nh.spinOnce();
  }
  delay(1000);
}
