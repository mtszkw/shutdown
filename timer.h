#pragma once

namespace caretaker
{
    class Timer
    {
    public:
        int hours;
        int minutes;

        Timer() : hours{0}, minutes{0}
        {
        }

        Timer(int hrs, int min) : hours{hrs}, minutes{min}
        {
        }

        void addTime(int hrs, int min)
        {
            minutes += min;
            if(minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }
            hours += hrs;
        }

        std::pair<int, int> getTime() const
        {
            return {hours, minutes};
        }
    };
}
