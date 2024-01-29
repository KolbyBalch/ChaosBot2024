// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(followBot, followBot);
  m_chooser.AddOption(spinnyBoi, spinnyBoi);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}
void Robot::RobotPeriodic() {}

void Robot::DriveWithJoystick(bool fieldRelative) {
  // Get the x speed. We are inverting this because Xbox controllers return
  // negative values when we push forward.
  const auto xSpeed = -m_xspeedLimiter.Calculate(
                          frc::ApplyDeadband(driver.GetLeftY(), 0.02)) *
                      Drivetrain::kMaxSpeed;

  // Get the y speed or sideways/strafe speed. We are inverting this because
  // we want a positive value when we pull to the left. Xbox controllers
  // return positive values when you pull to the right by default.
  const auto ySpeed = -m_yspeedLimiter.Calculate(
                          frc::ApplyDeadband(driver.GetLeftX(), 0.02)) *
                      Drivetrain::kMaxSpeed;

  // Get the rate of angular rotation. We are inverting this because we want a
  // positive value when we pull to the left (remember, CCW is positive in
  // mathematics). Xbox controllers return positive values when you pull to
  // the right by default.
  const auto rot = -m_rotLimiter.Calculate(
                        frc::ApplyDeadband(driver.GetRightX(), 0.02)) *
                    Drivetrain::kMaxAngularSpeed;

  m_swerve.Drive(xSpeed, ySpeed, rot, fieldRelative, GetPeriod());
}

void Robot::DriveAuto(float xInput, float yInput, float rotationalInput) {
  const auto xSpeed = xInput * Drivetrain::kMaxSpeed;
  const auto ySpeed = yInput * Drivetrain::kMaxSpeed;
  const auto rot = rotationalInput * Drivetrain::kMaxAngularSpeed;

  m_swerve.Drive(xSpeed, ySpeed, rot, true, GetPeriod());
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif