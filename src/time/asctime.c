#include <time.h>
#include <stdio.h>

static const char* const weekDayStrings[] = {
  "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

static const char* const shWeekDayStrings[] = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static const char* const shMonthStrings[] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

char* asctime(const struct tm* date)
{
  char tmp[28];
  return asctime_r(date, tmp);
}

// FIXME use local
char* asctime_r(const struct tm* restrict date, char* restrict str)
{
  snprintf(str, 26, "%.3s %.3s %3d %.2d:%.2d:%.2d %d\n",
    shWeekDayStrings[date->tm_wday], shMonthStrings[date->tm_mon - 1],
    date->tm_mday, date->tm_hour,
    date->tm_min, date->tm_sec,
    1900 + date->tm_year);
  return str;
}

