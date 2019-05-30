#ifndef TOPIC_SUBSCRIBER_LASER_SCAN_H
#define TOPIC_SUBSCRIBER_LASER_SCAN_H

#include <string>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <turtlebot_common/logging.h>

namespace turtlebot_common {      
	template <typename T>
	class Subscriber {
		public:
                        Subscriber();
			Subscriber(ros::NodeHandle& nh,
					const std::string& topic,
					const uint32_t queue_size);
                        virtual ~Subscriber();
                        void Subscribe();

		private:
			virtual void Callback(const T& msg) const = 0;
                        ros::NodeHandle nh_;
			ros::Subscriber sub_;
                        std::string topic_;
                        uint32_t queue_size_;
	};

        template <typename T>
        Subscriber<T>::Subscriber() : nh_{ }, topic_{ }, queue_size_{ } { }

        template <typename T>
        Subscriber<T>::Subscriber(ros::NodeHandle& nh,
                                        const std::string& topic,
                                        uint32_t queue_size)
                : nh_{ nh }, topic_{ topic }, queue_size_{ queue_size } { }

        template <typename T>
        Subscriber<T>::~Subscriber<T>() { }
        
        template <typename T>
        void Subscriber<T>::Subscribe()
        {
                sub_ = nh_.subscribe(topic_, queue_size_,
                                                &Subscriber<T>::Callback,
                                                this);
                if (!sub_) {
                        ROS_FATAL_STREAM("Subscribing to topic [" 
                                                << topic_ << "]: failed!");
                } else {
                        TURTLEBOT_LOG("Subscribing to topic [%s]: done.", topic_.c_str());
                }
        }
}

#endif /* TOPIC_SUBSCRIBER_LASER_SCAN_H */
