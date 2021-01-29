//This program is to test 5 pin out to a 5 different servos.
//
//Runs for only 1 sec and should result in servo being in full extension position.
//Must be exec in shell prior "echo 49 > /sys/class/gpio/export";
//Must be exec in shell prior "echo out > /sys/class/gpio/gpio49/direction";
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int print_menu() {
	
	return 0;
}

int main() {
	int LA1 = open("/sys/class/gpio/gpio50/value", O_WRONLY); //Linear Servo 1
	int LA3 = open("/sys/class/gpio/gpio51/value", O_WRONLY); //Linear Servo 3
	int LA2 = open("/sys/class/gpio/gpio22/value", O_WRONLY); //Linear Servo 2
	int LA4 = open("/sys/class/gpio/gpio23/value", O_WRONLY); //Linear Servo 4
	//int SR1 = open("/sys/class/gpio/gpio47/value", O_WRONLY); //Rotary Servo 1
	char choice;
	printf("Full Servo Testing\n");
	printf("f - Fully Extends 4 Legs.\n");
	printf("h - Half way Extends 4 Legs.\n");
	printf("r - Fully retracts 4 Legs.\n");
	printf("e - Exit\n");
	printf("Enter Choice:");
	scanf("%c", &choice);
	int i = 0;
	switch (choice) {
	case 'f':
		//drive 4 fully;
		
		while (i < 50) {
			write(LA1, "1", 1);
			write(LA3, "1", 1);
			write(LA2, "1", 1);
			write(LA4, "1", 1);
			usleep(2000);
			write(LA1, "0", 1);
			write(LA3, "0", 1);
			write(LA2, "0", 1);
			write(LA4, "0", 1);
			usleep(18000);
			i++;
		}
	case 'h':
		//drive 4 half
		
		while (i < 50) {
			write(LA1, "1", 1);
			write(LA3, "1", 1);
			write(LA2, "1", 1);
			write(LA4, "1", 1);
			usleep(1500);
			write(LA1, "0", 1);
			write(LA3, "0", 1);
			write(LA2, "0", 1);
			write(LA4, "0", 1);
			usleep(18500);
			i++;
		}
	case 'r':
		//retract all 4
		
		while (i < 50) {
			write(LA1, "1", 1);
			write(LA3, "1", 1);
			write(LA2, "1", 1);
			write(LA4, "1", 1);
			usleep(1000);
			write(LA1, "0", 1);
			write(LA3, "0", 1);
			write(LA2, "0", 1);
			write(LA4, "0", 1);
			usleep(19000);
			i++;
		}
	case 'e':
		//Exit

	default:
		break;




	}



	return 0;
}