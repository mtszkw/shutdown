#pragma once

#include <sstream>
#include "time.hpp"

class Scheduler
{
public:
    Scheduler() {}

    Time& time() {
        return _time;
    }

    void addTime(const int hours, const int minutes) {
        _time.add(hours, minutes);
    }

    void scheduleShutdown() const {
        const int totalTimeSecs = 3600 * _time.hours() + 60 * _time.minutes();
        std::ostringstream commandStream;
        commandStream << "shutdown -s -t " << totalTimeSecs;
        system(commandStream.str().c_str());
    }

    void abortShutdown() const {
        system("shutdown -a");
    }

private:
    Time _time;
};