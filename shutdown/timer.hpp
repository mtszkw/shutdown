#pragma once

#include <utility>

class Timer
{
public:
    Timer() : hours{ 0 }, minutes{ 0 } {}
    Timer(const int hrs, const int min) : hours{ hrs }, minutes{ min } {}

    void addTime(const int hrs, const int min) {
        minutes += min;
        if (minutes >= 60) {
            ++hours;
            minutes -= 60;
        }
        hours += hrs;
    }

    std::pair<int, int> getTime() const {
        return { hours, minutes };
    }

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

private:
    int hours, minutes;
};