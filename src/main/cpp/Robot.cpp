// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(leftAmp, leftAmp);
  m_chooser.AddOption(rightAmp, rightAmp);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);

  m_AmpDump.Init();
}
void Robot::RobotPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif