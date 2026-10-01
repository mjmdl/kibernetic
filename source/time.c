#include "log.h"
#include "time.h"

void loop_timer_reset(Loop_Timer *timer) {
    *timer = (Loop_Timer){
        .running_seconds_elapsed = 0.0,
        .seconds_per_tick = 1.0 / 20.0,
        .last_second = wallclock_seconds(),
        .seconds_since_last_tick = 0.0,
        .tick_scale = 1.0,
        .maximum_frame_seconds = 1.0 / 4.0,
        .target_frame_seconds = 0.0,
        .debug_frame_count = 0,
        .debug_seconds_elapsed = 0.0,
    };
}

void loop_timer_begin(Loop_Timer *timer) {
    double current_second = wallclock_seconds();
    timer->frame_seconds = current_second - timer->last_second;

    if (timer->frame_seconds > timer->maximum_frame_seconds) {
        timer->frame_seconds = timer->maximum_frame_seconds;
    }

    timer->last_second = current_second;
    timer->seconds_since_last_tick += timer->frame_seconds;
}

void loop_timer_end(Loop_Timer *timer) {
    ++timer->debug_frame_count;
    timer->debug_seconds_elapsed += timer->frame_seconds;

    if (timer->debug_seconds_elapsed >= 1.0) {
        int frame_count = timer->debug_frame_count;
        double milliseconds = (frame_count > 0 ? 1000.0 / frame_count : 0.0);

        LOG_DEBUG("FPS: %d, %.0f ms", frame_count, milliseconds);

        timer->debug_frame_count = 0;
        timer->debug_seconds_elapsed = 0.0;
    }

    if (timer->target_frame_seconds <= 0.0) {
        return;
    }

    double elapsed = wallclock_seconds() - timer->last_second;
    double remaining = timer->target_frame_seconds - elapsed;

    if (remaining > 0.0) {
        wallclock_sleep_seconds(remaining);
    }
}

bool loop_timer_drain(Loop_Timer *timer) {
    if (timer->seconds_since_last_tick >= timer->seconds_per_tick) {
        double drain_seconds = timer->seconds_per_tick * timer->tick_scale;

        timer->seconds_since_last_tick -= timer->seconds_per_tick;
        timer->running_seconds_elapsed += drain_seconds;
        return true;
    } else {
        return false;
    }
}
