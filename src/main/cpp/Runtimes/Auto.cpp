#include "Robot.h"

void Robot::AutonomousInit() {
  m_Shooter.init();
  //m_AmpDump.Init();
  
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  autoTimer = frc::Timer();
  autoTimer.Start();

  if (m_autoSelected == leftAmp) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {

  // std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  // targetOffsetH = table->GetNumber("tx", 0.0);

  // if (m_autoSelected == leftAmp) {
  //   if(autoTimer.Get() < units::second_t{10}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   } else if (autoTimer.Get() < units::second_t{11}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{-0.6}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   } else if (autoTimer.Get() < units::second_t{12}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.2},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{1.0 * targetOffsetH / 27}, 
  //       false, true
  //     );
  //   } else if (autoTimer.Get() < units::second_t{14}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_Shooter.load();

  //   } else if (autoTimer.Get() < units::second_t{15}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_Shooter.zero();
  //     m_AmpDump.Dump();

  //   } else if (autoTimer.Get() < units::second_t{16}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{-2.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_AmpDump.Reset();

  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }

  // } else if (m_autoSelected == rightAmp) {
  //   if(autoTimer.Get() < units::second_t{10}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   } else if(autoTimer.Get() < units::second_t{11}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.6}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   } else if (autoTimer.Get() < units::second_t{13}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.2},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{1.0 * targetOffsetH / 27}, 
  //       false, true
  //     );
  //   } else if (autoTimer.Get() < units::second_t{14}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_Shooter.load();

  //   } else if (autoTimer.Get() < units::second_t{15}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_Shooter.zero();
  //     m_AmpDump.Dump();

  //   } else if (autoTimer.Get() < units::second_t{16}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{2.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_AmpDump.Reset();

  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }

  // } else if (m_autoSelected == leftSpeaker) {
  //   if(autoTimer.Get() < units::second_t{2}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );

  //     m_Intake.Set(1);
  //     m_Shooter.shoot();
  //   } else if(autoTimer.Get() < units::second_t{5}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{1.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{M_PI / 12}, 
  //       false, true
  //     );

  //     m_Intake.Set(0);
  //     m_Shooter.zero();
  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }

  // } else if (m_autoSelected == rightSpeaker) {
  //   if(autoTimer.Get() < units::second_t{2}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );

  //     m_Intake.Set(1);
  //     m_Shooter.shoot();
  //   } else if(autoTimer.Get() < units::second_t{5}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{1.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{-M_PI / 12}, 
  //       false, true
  //     );

  //     m_Intake.Set(0);
  //     m_Shooter.zero();
  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }
  // } else if (m_autoSelected == centerSpeaker) {
  //   if(autoTimer.Get() < units::second_t{2}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //     m_Intake.Set(1);
  //     m_Shooter.shoot();

  //   } else if (autoTimer.Get() < units::second_t{5}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.5},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );

  //     m_Intake.Set(0);
  //     m_Shooter.zero();
  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }
  // } else {
  //   if(autoTimer.Get() < units::second_t{3}) {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{1.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   } else {
  //     m_Drivetrain.Drive(
  //       units::meters_per_second_t{0.0},
  //       units::meters_per_second_t{0.0}, 
  //       units::radians_per_second_t{0.0}, 
  //       false, true
  //     );
  //   }
  // }
}