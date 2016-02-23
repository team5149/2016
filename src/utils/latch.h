#ifndef LATCHING_BUTTON
#define LATCHING_BUTTON

// latches a boolean
class Latch {
public:
	Latch(bool on = true){ latch_on = on; last = false; }

	// returns true if the input changed to the value we want
	bool operator()(bool value) { 
		bool ret = value != last && value == latch_on;
		last = value;
		return ret;
	}

protected:
	bool latch_on;
	bool last;
};

#endif 
