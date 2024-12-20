#ifndef FOC_H
#define FOC_H

#include "cfg.h"
typedef struct
{
	float Iq;
	float Id;
}Park;

typedef struct
{
	float Ialpha;
	float Ibeta;
}Clark;

typedef struct
{
	float Ia;
	float Ib;
	float Ic;
}Raw;

typedef struct
{
	float theta;
	Park motor_p;
	Clark motor_c;
	Raw motor_r;
	uint8_t sector;
	float atan_now;
	float T1;
	float T2;
	float angle;
	float cal_angle;
	uint8_t idx1;
}Foc;

typedef struct
{
	float alpha;
	float s_last;
	float s_now;
	uint8_t trig;
}Filt;


uint8_t phase_check(uint8_t a, uint8_t b);
void ParkConv(void);
void ClarkConv(void);
void ParkConvT(void);
void SVPWM(void);
float LowPass(float x);
void FiltConf(void);

#endif
