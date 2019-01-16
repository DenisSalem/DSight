#! /usr/bin/python3

import dsight

try:
    c = dsight.ContextHandler(dsight.DSIGHT_CONTEXT_GLFW3,3,3)
    c = dsight.ContextHandler(dsight.DSIGHT_CONTEXT_GLFW3,3,3)

except dsight.DSightBaseException as e:
    print(e)

