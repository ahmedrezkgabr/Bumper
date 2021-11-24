#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*ADC Multiplexer Selection Register*/
#define       ADMUX                         (*(volatile u8 *)0x27)

#define       ADMUX_MUX0                       0
#define       ADMUX_MUX1                       1
#define       ADMUX_MUX2                       2
#define       ADMUX_MUX3                       3
#define       ADMUX_MUX4                       4
#define       ADMUX_ADLAR                      5
#define       ADMUX_REFS0                      6
#define       ADMUX_REFS1                      7

/*ADC Control and Status Register A*/

#define       ADCSRA                        (*(volatile u8 *)0x26)
#define       ADCSRA_ADEN                     7
#define       ADCSRA_ADSC                     6
#define       ADCSRA_ADATE                    5
#define       ADCSRA_ADIF                     4
#define       ADCSRA_ADIE                     3
#define       ADCSRA_ADPS2                    2
#define       ADCSRA_ADPS1                    1
#define       ADCSRA_ADPS0                    0

#define       ADCL                           (*(volatile u8 *)0x24)

#define       ADCH                           (*(volatile u8 *)0x25)

#define       SFIOR                          (*(volatile u8 *)0x23)
#define       SFIOR_ADTS2                     7
#define       SFIOR_ADTS1                     6
#define       SFIOR_ADTS0                     5



/* ADJUST SELECTION*/

#define       LEFT_ADJUST_RESULT              100
#define       RIGHT_ADJUST_RESULT             110


/*VOLTAGE REFERNCE*/

#define       AREF                            0
#define       AVCC                            1
#define       RESERVED                        2
#define       INTERNAL                        3

/*AUTO TRIGGER */
#define      ENABLE                           1
#define      DISABLE                          0
/*source trigger*/
#define      FREE_RUNNING                      0
#define      Analog_Comparator                 1
#define      External_Interrupt_Request_0      2
#define      Timer/Counter0_Compare Match      3
#define      Timer/Counter0_Overflow           4
#define      Timer/Counter1_Compare Match B    5
#define      Timer/Counter1_Overflow           6
#define      Timer/Counter1_Capture Event      7


#endif
