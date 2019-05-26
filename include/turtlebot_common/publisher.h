#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>

#include <ros/ros.h>

namespace turtlebot_common {
	template <typename T>
	class Publisher {
		public:
                        Publisher();
			Publisher(ros::NodeHandle& nh,
				const std::string& topic,
				uint32_t queue_size);
			void Publish(const T& msg) const;

		private:
			ros::Publisher pub_;
	};

        template <typename T>
        Publisher<T>::Publisher() : pub_{ } { }

	template <typename T>
	Publisher<T>::Publisher(ros::NodeHandle& nh,
				const std::string& topic,
				uint32_t queue_size)
	{
		pub_ = nh.advertise<T>(topic, queue_size);
		if (!pub_) {
			ROS_FATAL_STREAM("Advertising topic [" 
                                                << topic << "]: failed!");
		}
	}

	template <typename T>
	void Publisher<T>::Publish(const T& msg) const
	{
		pub_.publish(msg);   
	}
}

#endif /* PUBLISHER_H */
