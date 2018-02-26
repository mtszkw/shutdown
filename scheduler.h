#pragma once

#include <cstdlib>
#include <sstream>
#include "timer.h"

namespace caretaker
{
    class Scheduler
    {
    public:
        Scheduler()
        {
        }

        const Timer& getTime() const
        {
            return _time;
        }

        void addTime(int hours, int minutes)
        {
            _time.addTime(hours, minutes);
        }

        void scheduleShutdown() const
        {
            const int totalTimeSecs = 3600 * _time.hours + 60 * _time.minutes;
            std::ostringstream commandStream;
            commandStream << "shutdown -s -t " << totalTimeSecs;
            system(commandStream.str().c_str());
        }

        void abortShutdown() const
        {
            system("shutdown -a");
        }

    private:
        Timer _time;
    };
}

