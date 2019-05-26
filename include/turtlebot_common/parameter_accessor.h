#ifndef PARAMETER_ACCESSOR_H
#define PARAMETER_ACCESSOR_H

#include <string>

#include <ros/ros.h>

namespace turtlebot_common {
	class ParameterAccessor {
		public:
			ParameterAccessor(ros::NodeHandle& nh);

			template <typename T>
			T GetParameter(const std::string& name) const;

		private:
			ros::NodeHandle nh_;
	};

	ParameterAccessor::ParameterAccessor(ros::NodeHandle& nh) : nh_{ nh } {}

	template <typename T>
	T ParameterAccessor::GetParameter(const std::string& name) const
	{
		T val;
		if (!nh_.getParam(name, val)) {
			ROS_ERROR_STREAM("Retrieving value for parameter [" 
                                                << name << "]: failed!");
		}
		return val;
	}
}

#endif /* PARAMETER_ACCESSOR_H */
