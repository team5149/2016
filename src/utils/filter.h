#ifndef EXPONENTIAL_FILTER_H
#define EXPONENTIAL_FILTER_H

class ExponentialFilter {
public:
	ExponentialFilter(float a) { alpha = a; }

protected:
	float alpha;
};

#endif
