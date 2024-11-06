#include <chrono>
#include <ctime>
#include <rclcpp/rclcpp.hpp>
#include <builtin_interfaces/msg/time.hpp>

class UTCTimePublisher : public rclcpp::Node
{
public:
    UTCTimePublisher() : Node("utc_time_publisher")
    {
        // Create a publisher on the 'utc_time' topic with a queue size of 10
        publisher_ = this->create_publisher<builtin_interfaces::msg::Time>("utc_time", 10);
        
        // Set a timer to call the publish_utc_time function every second
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&UTCTimePublisher::publish_utc_time, this));
    }

private:
    void publish_utc_time()
    {
        // Get current time as time_t
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);

        // Convert to seconds and nanoseconds for the ROS 2 message
        auto now_seconds = std::chrono::duration_cast<std::chrono::seconds>(
            now.time_since_epoch()).count();
        auto now_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(
            now.time_since_epoch() - std::chrono::seconds(now_seconds)).count();

        // Create a Time message and set the seconds and nanoseconds fields
        builtin_interfaces::msg::Time utc_ros_time;
        utc_ros_time.sec = static_cast<int32_t>(now_seconds);
        utc_ros_time.nanosec = static_cast<uint32_t>(now_nanoseconds);

        // Publish the UTC time
        publisher_->publish(utc_ros_time);
        RCLCPP_INFO(this->get_logger(), "Published UTC Time: %d.%09d", utc_ros_time.sec, utc_ros_time.nanosec);
    }

    rclcpp::Publisher<builtin_interfaces::msg::Time>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<UTCTimePublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

