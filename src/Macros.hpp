#ifndef DSIGHT_MACROS_HPP_INCLUDED
#define DSIGHT_MACROS_HPP_INCLUDED

#define DSIGHT_SET_UNIQUE_IDENTIFIER(VAR_NAME) \
struct timeval tp; \
gettimeofday(&tp, NULL); \
VAR_NAME = tp.tv_sec * 1000 + tp.tv_usec / 1000

#endif
