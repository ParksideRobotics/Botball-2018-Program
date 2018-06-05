#ifndef UTIL_H_
#define UTIL_H_

#include <kipr/botball.h>
#include <stdbool.h>

#define LINE_TRACKER 0

void init();

void shutDown();

bool isTracking();

void trackLine();

void trackEdge();

void skipLine(int direction, int linesToSkip);

void getToPos();

#endif /* UTIL_H_ */