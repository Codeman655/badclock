# Clock Service "Randsomware"

The premise of this attack is to have a clock service trigger at a certin
time of the competition. 

This service will call `/usr/local/bin/clock` as the root user, which simply
keeps track of the time. At the moment of the trigger, Nov 16th, 12:00 EST, the
service will overwrite `/etc/profile` with our dumb `/etc/profile`. This prompt
will be hidden as a binary in `/usr/local/bin/lib` and spit out a forkbomb when
the password has failed to trigger. It also traps several signals to be super
annoying.
