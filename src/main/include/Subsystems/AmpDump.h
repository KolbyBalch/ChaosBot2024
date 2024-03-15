#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>

class AmpDump {
    public:
        AmpDump();

        void Init();

        void Load();
        void Toggle();
        void Dump();
        void Reset();
    
    private:
        frc::DoubleSolenoid m_solenoid;
        frc::Compressor m_compressor;
};