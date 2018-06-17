#pragma once

#include <sstream>
#include "timer.hpp"

class Scheduler
{
public:
    Scheduler() {}

    const Timer& getTime() const {
        return _time;
    }

    void addTime(const int hours, const int minutes) {
        _time.addTime(hours, minutes);
    }

    void scheduleShutdown() const {
        const int totalTimeSecs = 3600 * _time.getHours() + 60 * _time.getMinutes();
        std::ostringstream commandStream;
        commandStream << "shutdown -s -t " << totalTimeSecs;
        system(commandStream.str().c_str());
    }

    void abortShutdown() const {
        system("shutdown -a");
    }

private:
    Timer _time;
};