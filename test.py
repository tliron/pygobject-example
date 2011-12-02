#!/usr/bin/env python

from gi.repository import Logging

logger = Logging.Logger()

logger.set_property('name', 'chipy')
logger.log("ChiPy thanks crowdSPRING for hosting!")
logger.log("And can't wait for 'beer time'.")
logger.log("The Ruby folk are probably drinking vitamin water right now.")
logger.increment()
logger.log("ChiPy does not have a drinking problem.")
