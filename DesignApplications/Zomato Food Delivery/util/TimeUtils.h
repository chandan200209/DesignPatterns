#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <ctime>
#include <string>
using namespace std;
class TimeUtils
{
public:
    static string getCurrentTime()
    {
        time_t now = time(0);   // time returns no. of seconds since January 1, 1970 (Unix Epoch).
        char *dt = ctime(&now); // ctime converts the time in seconds in human readable form
        string s(dt);           // since, ctime returns in c like string, we need to convert this in c++ like string
        if (!s.empty() && s.back() == '\n')
        {
            s.pop_back(); // If the string isn't empty and its last character is a newline, remove it.
        }
        return s;
    }
};
#endif // TIME_UTILS_H