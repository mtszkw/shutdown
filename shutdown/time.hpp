#pragma once

#include <string>
#include <utility>

class Time
{
public:
    Time() : _hours{0}, _minutes{0} {}
    Time(const int hrs, const int min) : _hours{hrs}, _minutes{min} {}

    void add(const int hrs, const int min) {
        _minutes += min;
        if (_minutes >= 60) {
            ++_hours;
            _minutes -= 60;
        }
        else if (_minutes < 0) {
            --_hours;
            _minutes += 60;
        }
        _hours = max(0, _hours + hrs);
    }
    
    void reset() {
        _hours = 0;
        _minutes = 0;
    }

    std::pair<int, int> getTime() const {
        return { _hours, _minutes };
    }

    int hours() const {
        return _hours;
    }

    int minutes() const {
        return _minutes;
    }

    std::string toString() const {
        return std::to_string(_hours) + " hour(s) and " + std::to_string(_minutes) + " minute(s)";
    }

private:
    int _hours;
    int _minutes;
};