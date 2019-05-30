#ifndef LOGGING_H
#define LOGGING_H

//#include <ros/ros.h>

#ifndef NDEBUG
        #define TURTLEBOT_LOG(...) ROS_INFO(__VA_ARGS__)
#else
        #define TURTLEBOT_LOG(...) 
#endif

#endif /* LOGGING_H */
