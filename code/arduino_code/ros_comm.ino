#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;
geometry_msgs::Twist twist_msg;
ros::Publisher pub_cmd_vel("cmd_vel", &twist_msg);
geometry_msgs::Twist curr_vel_msg;
ros::Subscriber<geometry_msgs::Twist> sub_curr_vel("curr_vel", &currVelCallback);

float desired_velocity = 0.5;
float kp = 1.0, ki = 0.0, kd = 0.0;
float previous_error = 0.0, integral = 0.0;

void currVelCallback(const geometry_msgs::Twist& msg) {
  curr_vel_msg = msg;
}

float computePID(float target, float current) {
  float error = target - current;
  integral += error;
  float derivative = error - previous_error;
  previous_error = error;
  return (kp * error) + (ki * integral) + (kd * derivative);
}

void setup() {
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.advertise(pub_cmd_vel);
  nh.subscribe(sub_curr_vel);

  while (!nh.connected()) {
    nh.spinOnce();
  }

  nh.loginfo("Motor velocity control node started");
}

void loop() {
  nh.spinOnce();

  float motor1_output = computePID(desired_velocity, curr_vel_msg.linear.x);
  float motor2_output = computePID(desired_velocity, curr_vel_msg.linear.y);

  if (curr_vel_msg.linear.x < desired_velocity) {
    twist_msg.linear.x = motor1_output * 0.8;
    twist_msg.linear.y = motor2_output;
  } else if (curr_vel_msg.linear.y < desired_velocity) {
    twist_msg.linear.x = motor1_output;
    twist_msg.linear.y = motor2_output * 0.8;
  } else {
    twist_msg.linear.x = motor1_output;
    twist_msg.linear.y = motor2_output;
  }

  twist_msg.angular.z = 0.0;
  pub_cmd_vel.publish(&twist_msg);

  delay(100);
}
