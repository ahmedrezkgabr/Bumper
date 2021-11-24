#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*selection channel and gain bits*/
#define ADC0                  0
#define ADC1                  1
#define ADC2                  2
#define ADC3                  3
#define ADC4                  4
#define ADC5                  5
#define ADC6                  6
#define ADC7                  7
#define ADC0_ADC0_10X         8
#define ADC1_ADC0_10X         9
#define ADC0_ADC0_200X        10
#define ADC1_ADC0_200X        11
#define ADC2_ADC2_10X         12
#define ADC3_ADC2_10X         13
#define ADC2_ADC2_200X        14
#define ADC3_ADC2_200X        15
#define ADC0_ADC1_1X          16
#define ADC1_ADC1_1X          17
#define ADC2_ADC1_1X          18
#define ADC3_ADC1_1X          19
#define ADC4_ADC1_1X          20
#define ADC5_ADC1_1X          21
#define ADC6_ADC1_1X          22
#define ADC7_ADC1_1X          23
#define ADC0_ADC2_1X          24
#define ADC1_ADC2_1X          25
#define ADC2_ADC2_1X          26
#define ADC3_ADC2_1X          27
#define ADC4_ADC2_1X          28
#define ADC5_ADC2_1X          29
#define NULL                   0

void ADC_vidinit();
u8 ADC_u8readchannel_synchronous(u8 copy_u8channel);
u8 ADC_u8readchannel_asynchronous(u8 copy_u8channel);
#endif
