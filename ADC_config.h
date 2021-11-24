#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*selection adjust*/

 /*1-LEFT_ADJUST_RESULT  2-RIGHT_ADJUST_RESULT*/

#define            ADJUST_RESULT     LEFT_ADJUST_RESULT

/* voltage reference */
/*
1-AREF, Internal Vref turned off
2-AVCC with external capacitor at AREF pin
3-RESERVED
4-Internal 2.56V Voltage Reference with external capacitor at AREF pin
 */
#define             VOLTAGE_REFERNCE         RESERVED

/*prescalar*/
#define             ADC_PRESCALAR            128

#define             AUTO_TRIGGER             DISABLE
/*TRIGGER SOURCE */
/*
 1-FREE RUNNING
 2-Analog Comparator
 3-External Interrupt Request 0
 4-Timer/Counter0 Compare Match
 5-Timer/Counter0 Overflow
 6-Timer/Counter1 Compare Match B
 7-Timer/Counter1 Overflow
 8-Timer/Counter1 Capture Event*/
#define TRIGGER_SOURCE  FREE_RUNNING

/*enterrupt */
#define  INTERRUPT                            DISABLE



#endif
