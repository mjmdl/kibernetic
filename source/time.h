#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

double wallclock_seconds(void);

void wallclock_sleep_seconds(double seconds);

typedef struct Loop_Timer {
    double running_seconds_elapsed;
    double seconds_per_tick;
    double last_second;
    double frame_seconds;
    double seconds_since_last_tick;
    double tick_scale;
    double maximum_frame_seconds;
    double target_frame_seconds;
    int debug_frame_count;
    double debug_seconds_elapsed;
} Loop_Timer;

void loop_timer_reset(Loop_Timer *timer);

void loop_timer_begin(Loop_Timer *timer);

void loop_timer_end(Loop_Timer *timer);

bool loop_timer_drain(Loop_Timer *timer);

#endif // TIME_H
