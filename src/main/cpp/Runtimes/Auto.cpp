#include "Robot.h"

#include <pathplanner/lib/auto/AutoBuilder.h>
#include <frc2/command/CommandScheduler.h>

using namespace pathplanner;

void Robot::AutonomousInit() {
  m_AmpDump.Init();

  m_autoSelected = m_chooser.GetSelected();
  
  pathGroup = PathPlannerAuto::getPathGroupFromAutoFile(m_autoSelected);

  
  
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  
}

void Robot::AutonomousPeriodic() {
  AutoBuilder::(pathGroup);
}