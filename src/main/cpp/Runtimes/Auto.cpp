#include "Robot.h"

#include <pathplanner/lib/auto/AutoBuilder.h>

using namespace pathplanner;

void Robot::AutonomousInit() {
  m_AmpDump.Init();

  m_autoSelected = m_chooser.GetSelected();
  
  path = PathPlannerPath::fromPathFile(m_autoSelected);
  
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  AutoBuilder::followPath(path);
}

void Robot::AutonomousPeriodic() {
  
}