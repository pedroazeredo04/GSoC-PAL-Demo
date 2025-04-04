# 🚧 GSoC-PAL-Demo

A simulation project demonstrating a basic intralogistics robot in **Gazebo Harmonic** with **ROS 2 Jazzy**, including a custom sensor plugin called `DummySensor`. This repo contains the full setup of a mobile robot and shows how to integrate and extend simulation capabilities using ROS 2 and gz-transport.

📹 **Demo video**: [YouTube Link](https://www.youtube.com/watch?v=ws5a9c4th8M)

---

## 📁 Package Structure

```
GSoC-PAL-Demo/
├── fws_robot_description/     # Robot URDF/XACRO and Gazebo config files
├── fws_robot_sim/             # Launch files and Gazebo world setup
├── velocity_pub/              # Node to publish velocity commands to the robot
└── dummy_sensor/              # Custom Gazebo Harmonic plugin (gz-transport) that publishes "Hello World"
```

---

## 🔍 About Each Package

### `fws_robot_description`
- Contains the robot’s URDF description.
- Files modified:
  - `robots/fws_robot.urdf.xacro`
  - `gazebo/fws_robot.gazebo.xacro`

### `fws_robot_sim`
- Sets up the simulation environment.
- Launches robot + world using Gazebo Harmonic.

### `velocity_pub`
- A ROS 2 node that publishes velocity commands to the robot (using `geometry_msgs/Twist`).

### `dummy_sensor`
- A **custom Gazebo plugin** written in C++.
- On load, it publishes `"Hello World"` to a ROS 2 topic using `gz-transport`.
- Demonstrates how to create and attach a custom sensor to your robot.

---

## ▶️ How to Use

### Clone into a ROS2 Workspace

```bash
mkdir -p demo_ws/src
cd demo_ws/src
git clone https://github.com/pedroazeredo04/GSoC-PAL-Demo.git
```

### Launch the Simulation

```bash
cd demo_ws
colcon build
source install/setup.bash
ros2 launch fws_robot_sim sim_launch.py
```

This will:
- Launch Gazebo Harmonic
- Spawn the `fws_robot`
- Include the custom `DummySensor` plugin
- Print the following stuff in terminal:

```
Dummy Sensor loaded and message published!
Message received: Hello world from dummy sensor
```

---

## 💡 Credits

The packages `fws_robot_description`, `fws_robot_sim` and `velocity_pub` were based on the [YouTube tutorial by Robot Mania](https://www.youtube.com/watch?v=b8VwSsbZYn0), and were adapted and modified for this project.

---

## 📬 Contact

If you have any questions, feel free to open an issue or contact me at [pedro_azeredo@usp.br].

---
