/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeTimedRoll.h"
#include "../Robot.h"

IntakeTimedRoll::IntakeTimedRoll(float timeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intakeRollerSystem);
	seconds = timeout;
}

// Called just before this Command runs the first time
void IntakeTimedRoll::Initialize() {
	Robot::intakeRollerSystem->IntakeRoll(0.3);
	SetTimeout(seconds);
}

// Called repeatedly when this Command is scheduled to run
void IntakeTimedRoll::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeTimedRoll::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void IntakeTimedRoll::End() {
	Robot::intakeRollerSystem->IntakeRoll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeTimedRoll::Interrupted() {
	End();
}
