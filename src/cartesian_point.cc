#include "../include/turtlebot_common/cartesian_point.h"

namespace turtlebot_common {
	CartesianPoint::CartesianPoint() 
                : x{ 0 }, y{ 0 }, z{ 0 }, w{ 1 } {}

	CartesianPoint::CartesianPoint(float x, float y) 
                : x{ x }, y{ y }, z{ 0 }, w{ 1 } {}

	CartesianPoint::CartesianPoint(float x, float y, float z) 
                : x{ x }, y{ y }, z{ z }, w{ 1 } {}

	CartesianPoint::CartesianPoint(float x, float y, float z, float w) 
                : x{ x }, y{ y }, z{ z }, w{ w } {}
}
