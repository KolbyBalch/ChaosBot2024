#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include "ctre/Phoenix.h"

class Shooter {
    public:
        Shooter();

        void init();

        void load();
        void shoot();
        void zero();
        void Set(double speed);

        void TimerStart();
    private:
        WPI_TalonFX m_shooterOne;
        WPI_TalonFX m_shooterTwo;
        WPI_TalonFX m_shooterThree;

        frc::DoubleSolenoid m_solenoid;
        frc::Compressor m_compressor;

        frc::Timer dumpTimer;
};