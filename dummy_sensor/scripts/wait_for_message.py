#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class MessageWaiter(Node):
    def __init__(self):
        super().__init__('message_waiter')
        self.get_logger().info("Waiting for message in topic '/dummy_sensor_topic'...")
        
        try:
            msg = self.create_subscription(
                String, '/dummy_sensor_topic', self.callback, 10
            )
            rclpy.spin_once(self, timeout_sec=10.0)  # Wait for 10 seconds
        except Exception as e:
            self.get_logger().error(f"Error in waiting for message: {e}")

    def callback(self, msg):
        self.get_logger().info(f"Message received: {msg.data}")
        rclpy.shutdown()


def main():
    rclpy.init()
    node = MessageWaiter()
    rclpy.spin(node)


if __name__ == '__main__':
    main()
