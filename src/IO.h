#ifndef IO_H
#define IO_H

#include "WPILib.h"
#include "utils/latch.h"

// IO reads inputs from the drivers and uses them to
// control the subsystems.
class IO {
public:
	IO();	

	// Called periodically by the main robot loop
	void Run();

private:
	std::shared_ptr<Joystick> driver_stick, manip_stick;

	// defaults to true
	Latch shootLatch, angleLatch, dirLatch;

	bool dir_switch;
};

#endif // io
