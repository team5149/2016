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
	Joystick driver_stick, manip_stick;
};

#endif // io
