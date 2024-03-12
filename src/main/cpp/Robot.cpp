// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <pathplanner/lib/auto/NamedCommands.h>

#include <memory>
#include <functional>

using namespace pathplanner;

void Robot::RobotInit() {

  NamedCommands::registerCommand("Intake on", frc2::cmd::Run([&] { m_Intake.Set(1); }));

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
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