What and why 
------

This is a simpiler and toned down version of a repo [lowlvl-ioctl](zhttps://github.com/worthless443?tab=repositories) I created (which fatally diverged into a different objective than soly making modulated ioctl requets) 

### Running
Make sure that you have `CAP_SYS_ADMIN` enabled or in superuser mode (current=ep) when you run the executable.

### Issues 

* Breaking requests for `dev/tty` into type,nr and size using `_IOWR`creates a bad ioctl example (this is not necessary but got to create a macro that performs operation to the command flag, this is just for a proof of concept)

* Can't seem to find a bound for input `RNDADDTOENTCNT` for ioctl.
