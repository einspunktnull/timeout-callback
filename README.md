# TimeoutCallback - Arduino library

# Changelog

## Version 1.1.0

* Changed start() function and moved parameters to the constructor 
* Timeout timer can now being restarted with restart(). It restarts an already finished timeout also.
* Timeout timer can now being resetted with reset(). A already finished timeout will not fire again. You have to call start() or restart() to start timer.

## Version 1.0.0

Initial version