#ifndef POLAR_POINT_H
#define POLAR_POINT_H

namespace turtlebot_common {
	struct PolarPoint {
		PolarPoint();
		PolarPoint(float dist, float angle);

		float dist, angle;
	};
}

#endif /* POLAR_POINT_H */
