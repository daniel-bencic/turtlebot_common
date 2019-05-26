#ifndef CARTESIAN_POINT_H
#define CARTESIAN_POINT_H

namespace turtlebot_common {
	struct CartesianPoint {
		CartesianPoint();
		CartesianPoint(float x, float y);
		CartesianPoint(float x, float y, float z);
		CartesianPoint(float x, float y, float z, float w);

		float x, y, z, w;
	};
}

#endif /* CARTESIAN_POINT_H */
