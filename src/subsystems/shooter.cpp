#include "shooter.h"
#include "../utils/constants.h"

Shooter::Shooter(){ 
	fire_double.reset(new DoubleSolenoid {Constants::SHOOTER_FIRE_SOLENOID_A, Constants::SHOOTER_RETRACT_SOLENOID_A});
	fire_single.reset(new Solenoid {Constants::SHOOTER_FIRE_SOLENOID_B});

	pos_sol.reset(new DoubleSolenoid {Constants::SHOOTER_RAISE_SOLENOID, Constants::SHOOTER_LOWER_SOLENOID });

	printf("Created shooter\n");
}

void Shooter::fire() {
	fire_double->Set(DoubleSolenoid::Value::kForward);
	fire_single->Set(true);
}

void Shooter::retract() {
	fire_double->Set(DoubleSolenoid::Value::kReverse);
	fire_single->Set(false);
}

void Shooter::up() {
	pos_sol->Set(DoubleSolenoid::Value::kForward);
}

void Shooter::down() {
	pos_sol->Set(DoubleSolenoid::Value::kReverse);
}
