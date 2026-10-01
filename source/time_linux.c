#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <math.h>
#include <string.h>

#include <unistd.h>
#include <time.h>

#include "log.h"
#include "time.h"

double wallclock_seconds(void) {
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    return (double)time.tv_sec + (double)time.tv_nsec * 1e-9;
}

void wallclock_sleep_seconds(double seconds) {
    if (seconds <= 0.0) {
        return;
    }

    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);

    double remain = 0.0;
    double fract = modf(seconds, &remain);
    time.tv_sec += (time_t)remain;
    time.tv_nsec += (long)(fract * 1e9);

    if (time.tv_nsec >= (1e9)) {
        time.tv_sec += time.tv_nsec / 1e9;
        time.tv_nsec %= (long)1e9;
    }

    int result = 0;
    do {
        result = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &time, 0);
    } while (result == EINTR);

    if (result != 0) {
        LOG_WARN("Failed to sleep %.2f seconds: %s", seconds, strerror(result));
    }
}
