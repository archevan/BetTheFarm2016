#pragma config(Motor,  port2,           extensionBase, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           armBase,       tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           rightDrive,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           leftDrive,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           pinServo,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           clawRight,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           clawLeft,      tmotorServoStandard, openLoop)
// Motor Initialization

/*
 * @desc: New Tech High School's 2016 BEST robotics source code
 * @authors: Evan Seils, Tanner Luce
 */

task main()
{

	// Servo Limit Variables

	int servoMax = 127;
	int servoMin = -127;

	// Servo Reset Variables

	int pinServoInitial = -127; // Closed Position for the Seed Dispenser
	int leftClawInitial = 25; // Offset to align both sides of the claw

	// Intial Servo Position Reset

	motor[pinServo] = pinServoInitial;
	motor[clawLeft] = leftClawInitial;

	//Main Input Response Loop
	while(true)
	{

		// Drive Motor Configuration and Mapping
		motor[rightDrive] = vexRT[Ch3];
		motor[leftDrive] = vexRT[Ch2];

		// Arm Vertical Extension
		if(vexRT(Btn6D))
		{
			motor[armBase] = -80;
		} else {
			motor[armBase] = 0;
		}

		if(vexRT(Btn5D))
		{
			motor[armBase] = 80;
		} else {
			motor[armBase] = 0;
		}

		// Arm Horizontal Extension
		if(vexRT(Btn6U))
		{
			motor[extensionBase] = 80;
		} else {
			motor[extensionBase] = 0;
		}
		if(vexRT(Btn5U))
		{
			motor[extensionBase] = -80;
		} else {
			motor[extensionBase] = 0;
		}

		// Pin Servo Button
		if(vexRT[Btn8D])
		{
			motor[pinServo] = servoMax;
		}
		if(vexRT[Btn8U])
		{
			motor[pinServo] = servoMin;
		}

		//Right Claw Configuration
		if(vexRT[Btn8L])
		{
			 motor[clawRight]	= servoMin;
		}
		if(vexRT[Btn8R])
		{
			motor[clawRight] = servoMax;
		}

		//Left Claw Configuration
		if(vexRT[Btn7L])
		{
			motor[clawLeft] = servoMin;
		}
		if(vexRT[Btn7R])
		{
			motor[clawLeft] = servoMax;
		}
	}
}
