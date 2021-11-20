
#include "commands/DefaultDrive.h"
#include "subsystems/DrivetrainSubsystem.h"

DefaultDrive::DefaultDrive(DrivetrainSubsystem* subsystem,
                           std::function<double()> forward,
                           std::function<double()> rotation)
    : drive{subsystem}, forward{forward}, rotation{rotation} {
  AddRequirements({subsystem});
}

void DefaultDrive::Initialize() {
}

void DefaultDrive::Execute() {
  drive->Drive(forward(), rotation());
}

void DefaultDrive::End(bool interrupted) {
}

bool DefaultDrive::IsFinished() {
  return false;
}