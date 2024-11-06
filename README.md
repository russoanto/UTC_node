# UTC Time Example

This package provides two ROS 2 nodes, `utc_time_publisher` and `utc_time_subscriber`, that demonstrate how to publish and subscribe to UTC time on a distributed ROS 2 system. These nodes are useful for synchronizing time-sensitive operations across multiple devices or for providing a consistent time reference across different nodes.

## Nodes

### 1. `utc_time_publisher`

The `utc_time_publisher` node retrieves the current UTC time from the system clock and publishes it at regular intervals (every second) on the `/utc_time` topic. The UTC time is published as a `builtin_interfaces/msg/Time` message, which includes seconds and nanoseconds for precise time representation.

**Purpose**:

- Provides a common UTC time reference that can be used across multiple nodes or devices.
- Useful for synchronizing distributed systems that require a shared time source, especially in applications with multiple boards, sensors, or processes that need to stay in sync.

#### Published Topic

- `/utc_time` (type: `builtin_interfaces/msg/Time`): The current UTC time in seconds and nanoseconds since the Unix epoch.

### 2. `utc_time_subscriber`

The `utc_time_subscriber` node listens to the `/utc_time` topic and logs the received UTC time. This node demonstrates how to subscribe to and utilize the published UTC time data.

**Purpose**:

- Allows other nodes to receive and use the synchronized UTC time for time-sensitive tasks.
- Serves as an example of how distributed nodes can access a centralized time source for coordinated actions.

#### Subscribed Topic

- `/utc_time` (type: `builtin_interfaces/msg/Time`): Receives the current UTC time from the `utc_time_publisher`.
