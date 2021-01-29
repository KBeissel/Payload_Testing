//This program is to test a single pin out to a single servo.
//Created "PWM" like signal to P9_23 pin (49 is the GPIO#)
//Runs for only 1 sec and should result in servo being in full extension position.
//Must be exec in shell prior "echo 49 > /sys/class/gpio/export";
//Must be exec in shell prior "echo out > /sys/class/gpio/gpio49/direction";
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int fd = open("/sys/class/gpio/gpio49/value", O_WRONLY);
	int i = 0;
	while (i < 50) {
		write(fd, "1", 1);
		usleep(2000);
		write(fd, "0", 1);
		usleep(18000);
		i++;
	}
}
