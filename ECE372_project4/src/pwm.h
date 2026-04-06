



#ifndef PWM_H
#define PWM_H

void initPWMTimer3();
void initPWMTimer4();
void changeDutyCycle(int adcValue);
int readADC();
void setMotorClockwise();
void setMotorCounterClockwise();
int AnalogToDigital();
void stopMotor();
void AnalyzeADC();
void initMotorPins();
void initMotorDirectionPins();

#endif