#include "../include/turtlebot_common/polar_point.h"

namespace turtlebot_common {
	PolarPoint::PolarPoint() : dist{ 0 }, angle{ 0 } {}

	PolarPoint::PolarPoint(float dist, float angle) 
                : dist{ dist }, angle{ angle } {}
}
