#include "Subsystems/Climber.h"
#include "Constants/SubsystemConstants.h"

using namespace ClimberConstants;

Climber::Climber() :
    m_climbingMotor{kClimberCANId, rev::CANSparkMax::MotorType::kBrushless}
    {};

void Climber::setClimber(const double speed) {
    m_climbingMotor.Set(speed);
};