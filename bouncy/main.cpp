#define REPEAT_TIMES(times,symbol) for (size_t symbol = 0; symbol < times; symbol++)

#define BALL_AMOUNT 5
#define XRES 100
#define YRES 50
#define BOUNCE_SPEED_KEEP 0.75

#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <math.h>

using namespace std;

struct ball {
	double	xPosition = XRES/2;
	double	yPosition = YRES/2;
	double	xSpeed = 0;
	double	ySpeed = 0;
};

void drawScreen(ball* objects)
{
	//Initialization
	char screen[XRES][YRES];
	REPEAT_TIMES(YRES, i)
		REPEAT_TIMES(XRES, j)
			screen[j][i] = '.';
	
	//Balls
	REPEAT_TIMES(BALL_AMOUNT, i) {
		size_t xAccess = floor(objects[i].xPosition);
		size_t yAccess = floor(objects[i].yPosition);
		screen[xAccess][yAccess] = '#';
	}

	REPEAT_TIMES(YRES, i) {
		REPEAT_TIMES(XRES, j)
			cout << screen[j][i];
		cout << endl;
	}
	cout << endl << endl << flush;
}

void doPhysics(ball *objects, int xgravity, int ygravity)
{
	REPEAT_TIMES(BALL_AMOUNT, i) {
		objects[i].xSpeed += xgravity;
		objects[i].ySpeed += ygravity;

		objects[i].xPosition += objects[i].xSpeed;
		objects[i].yPosition += objects[i].ySpeed;
		
		if (objects[i].xPosition < 0)		{objects[i].xPosition = 0;	objects[i].xSpeed *= -BOUNCE_SPEED_KEEP;}
		if (objects[i].xPosition > XRES)	{objects[i].xPosition = XRES-1;	objects[i].xSpeed *= -BOUNCE_SPEED_KEEP;}

		if (objects[i].yPosition < 0)		{objects[i].yPosition = 0;	objects[i].ySpeed *= -BOUNCE_SPEED_KEEP;}
		if (objects[i].yPosition > YRES)	{objects[i].yPosition = YRES-1;	objects[i].ySpeed *= -BOUNCE_SPEED_KEEP;}

	}
}

void logPositions(ball object, uint16_t id)
{
	cout << 	"Info of ball '"	<< id << "':"		<< endl;
	cout << 	"\tXPOS:\t"		<< object.xPosition	<< endl;
	cout <<		"\tYPOS:\t"		<< object.yPosition	<< endl;
	cout <<		"\tXSPEED:\t"		<< object.xSpeed	<< endl;
	cout <<		"\tYSPEED:\t"		<< object.ySpeed	<< endl;
}

int main()
{
	int xgravity = 0;
	int ygravity = 1;
	ball *objects = new ball[BALL_AMOUNT];

	time_t* seed = new time_t;
	srand(time(seed));
	REPEAT_TIMES(BALL_AMOUNT, i) {
		seed++;
		objects[i].xSpeed = rand() % 30 - 15;
		seed++;
		objects[i].ySpeed = rand() % 30 - 15;
	}

	REPEAT_TIMES(100, i) {
		doPhysics(objects, xgravity, ygravity);
		//REPEAT_TIMES(BALL_AMOUNT, i) logPositions(objects[i], i);
		drawScreen(objects);
		this_thread::sleep_for(100ms);
	}
	delete[] objects;
	return 0;
}
