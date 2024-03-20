#include "Subsystems/Shooter.h"
#include "Constants/SubsystemConstants.h"

using namespace ShooterConstants;

Shooter::Shooter() : m_shooterOne{kShooterCANId}, 
    m_shooterTwo{kFollowerOneCANId}, 
    m_shooterThree{kFollowerTwoCANId}, m_solenoid{kPCMCanId, frc::PneumaticsModuleType::CTREPCM, kDumpForward, kDumpReverse},
    m_compressor{kPCMCanId, frc::PneumaticsModuleType::CTREPCM}
    {};

void Shooter::init() {
    m_compressor.EnableDigital();
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Shooter::load() {
    m_shooterOne.Set(-0.075);
    m_shooterTwo.Set(-0.2);
    m_shooterThree.Set(-0.3);
    if (dumpTimer.Get() > units::second_t(0.25)) {
        m_solenoid.Set(frc::DoubleSolenoid::kForward);
    }
}

void Shooter::shoot() {
    m_shooterOne.Set(-1);
    m_shooterTwo.Set(-1);
    m_shooterThree.Set(-.2);
}

void Shooter::zero() {
    m_shooterOne.Set(0);
    m_shooterTwo.Set(0);
    m_shooterThree.Set(0);
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Shooter::Set(double speed) {
    m_shooterOne.Set(speed);
    m_shooterTwo.Set(speed);
    m_shooterThree.Set(speed);
}

void Shooter::TimerStart() {
    dumpTimer.Reset();
    dumpTimer.Start();
}