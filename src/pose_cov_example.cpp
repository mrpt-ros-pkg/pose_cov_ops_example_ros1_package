#include <geometry_msgs/PoseWithCovariance.h>
#include <pose_cov_ops/pose_cov_ops.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pose_cov_example_node");
  ros::NodeHandle nh;

  // Create two PoseWithCovariance messages
  geometry_msgs::PoseWithCovariance pose1;
  geometry_msgs::PoseWithCovariance pose2;
  geometry_msgs::PoseWithCovariance result_pose;

  // Initialize pose1 and pose2 with some dummy values
  pose1.pose.position.x = 1.0;
  pose1.pose.position.y = 2.0;
  pose1.pose.position.z = 0.0;
  pose1.pose.orientation.w = 1.0;

  pose2.pose.position.x = 0.5;
  pose2.pose.position.y = 1.5;
  pose2.pose.position.z = 0.0;
  pose2.pose.orientation.w = 1.0;

  // Use pose_cov_ops to compose pose1 and pose2
  pose_cov_ops::compose(pose1, pose2, result_pose);

  // Print out the result
  ROS_INFO_STREAM("Resulting pose position: ("
                  << result_pose.pose.position.x << ", "
                  << result_pose.pose.position.y << ", "
                  << result_pose.pose.position.z << ")");

  ros::spinOnce(); // Not strictly needed for this example
  return 0;
}
