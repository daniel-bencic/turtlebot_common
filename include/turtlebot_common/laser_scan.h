#ifndef LASER_SCAN_H
#define LASER_SCAN_H

#include <vector>

namespace turtlebot_common {
        struct LaserScan {
                std::vector<float> ranges;
                std::vector<float> intensities;
                float angle_min;
                float angle_inc;
        };
}

#endif /* LASER_SCAN_H */
