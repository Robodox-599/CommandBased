/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CatapultReset.h"
#include "../Robot.h"

CatapultReset::CatapultReset() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(globalRobot.chassis.get());
	Requires(&globalRobot.catapultSystem);
}

// Called just before this Command runs the first time
void CatapultReset::Initialize() {
	globalRobot.catapultSystem.ResetPiston();
	globalRobot.catapultSystem.PullBack(1);
}

// Called repeatedly when this Command is scheduled to run
void CatapultReset::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CatapultReset::IsFinished() {
	return globalRobot.catapultSystem.GetLimitSwitch();
}

// Called once after isFinished returns true
void CatapultReset::End() {
	globalRobot.catapultSystem.PullBack(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatapultReset::Interrupted() {
	End();
}
