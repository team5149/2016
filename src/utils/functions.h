#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <cmath> // for fabs

namespace utils {
	// to range [-1.0, 1.0]
	float bound(const float lhs){
		if(lhs < -1.0) { return -1.0; }
		if(lhs > 1.0) { return 1.0; }
		return lhs;
	}

	// absolute min value
	float deadband(const float val, const float band = 0.1){
		if(fabs(val) < band) { return 0.0; }
		return val;
	}
}

#endif
