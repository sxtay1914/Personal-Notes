### Commands
* ps : process state
* [process] & : put process in background 
* fg [%PID] : put process in foreground 
* kill: send signals to processes
* killall

### Common signals:
* HUP: usually use to restart daemon programs
* INT: Interrupt, basically to terminate program. graceful shutdown 
* KILL: Same as INT, but program not able to save its work, cannot be ignored
* TERM: quite similar to INT, but different semantic meaning, graceful shutdown also
* STOP: pause
* TSTP: STOP send from terminal, thus can be ignored 
