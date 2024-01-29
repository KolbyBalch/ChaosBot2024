#include "Robot.h"

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);

    if (driver.GetAButton() == true) {
        DriveWithJoystick(true);
    } else {
        DriveWithJoystick(false);
    }
}