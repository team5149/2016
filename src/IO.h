#ifndef IO_H
#define IO_H

#include "WPILib.h"

// IO reads inputs from the drivers and uses them to
// control the subsystems.
class IO {
public:
	IO();	

	// Called periodically by the main robot loop
	void Run();

private:
	// use shared_ptr because it is easier than unique
	// not sure if these need to have ptrs, but the 
	// auto gen code from other teams has it...
	std::shared_ptr<Joystick> r_stick, l_stick;
};

#endif // io
