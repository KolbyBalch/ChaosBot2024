#include "Subsystems/AmpDump.h"
#include "Constants/SubsystemConstants.h"

using namespace PneumaticsConstants;

AmpDump::AmpDump() : m_solenoid{kPCMCanId, frc::PneumaticsModuleType::CTREPCM, kDumpForward, kDumpReverse},
    m_compressor{kPCMCanId, frc::PneumaticsModuleType::CTREPCM} {}

void AmpDump::Init() {
    m_compressor.EnableDigital();
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
}

void AmpDump::Load() {};

void AmpDump::Toggle() {
    m_solenoid.Toggle();
};

void AmpDump::Dump() {
    m_solenoid.Set(frc::DoubleSolenoid::kForward);
};

void AmpDump::Reset() {
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
};