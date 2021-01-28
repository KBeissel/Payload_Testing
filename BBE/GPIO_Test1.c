//This program is to test a single pin out to a single servo.
//Created "PWM" like signal to P9_23 pin (49 is the GPIO#)
//Runs for only 1 sec and should result in servo being in full extension position.

#include <unistd.h>
#include <stdlib.h>
#include <fntl.h>

int main() {
	system("echo 49 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio49/direction");
	int fd = open("/sys/class/gpio/gpio/value", O_WRONLY);
	int i = 0;
	while (i < 50) {
		write(fd, "1", 1);
		usleep(2000);
		write(fd, "0", 0);
		usleep(18000);
		i++;
	}
}
