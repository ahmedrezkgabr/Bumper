   #include "liberary/STD_TYPES.h"
   #include "liberary/BIT_MATH.h"
   #include"ADC_config.h"
   #include"ADC_private.h"
   #include"ADC_interface.h"
 //  #include"GIE_interface.h"

   void (* func)(void)=NULL;
   void ADC_vidinit()
   {

   	/*SELECT REF*/


   	SET_BIT(ADMUX,ADMUX_REFS0);
   	CLEAR_BIT(ADMUX,ADMUX_REFS1);

   	/*ACTIVATE ADIJUST*/
       #if ADJUST_RESULT  ==   LEFT_ADJUST_RESULT
   	   SET_BIT(ADMUX,ADMUX_ADLAR);
       #elif ADJUST_RESULT  ==   RIGHT_ADJUST_RESULT
   	   CLEAR_BIT(ADMUX,ADMUX_ADLAR);
      #else
           #warning("wrong adjust!")

      #endif
   	   /*select 128 prescaler*/
      #if ADC_PRESCALAR ==  128
   	    SET_BIT(ADCSRA,ADCSRA_ADPS0);
   	   	SET_BIT(ADCSRA,ADCSRA_ADPS1);
   	   	SET_BIT(ADCSRA,ADCSRA_ADPS2);
       #elif ADC_PRESCALAR ==  64
   		CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
   		SET_BIT(ADCSRA,ADCSRA_ADPS1);
   	    SET_BIT(ADCSRA,ADCSRA_ADPS2);
       #elif ADC_PRESCALAR ==  32

   		SET_BIT(ADCSRA,ADCSRA_ADPS0);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
   	    SET_BIT(ADCSRA,ADCSRA_ADPS2);
      #elif ADC_PRESCALAR ==  16

   		CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
   	    SET_BIT(ADCSRA,ADCSRA_ADPS2);
     #elif ADC_PRESCALAR ==  8

   		SET_BIT(ADCSRA,ADCSRA_ADPS0);
   	    SET_BIT(ADCSRA,ADCSRA_ADPS1);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
     #elif ADC_PRESCALAR ==  4

   		CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
   	    SET_BIT(ADCSRA,ADCSRA_ADPS1);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
     #elif ADC_PRESCALAR ==  2

   		SET_BIT(ADCSRA,ADCSRA_ADPS0);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
   	    CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
       #else
            #warning("wrong Prescalar!")

       #endif

       /*interrupt enable*/
      #if   INTERRUPT  ==  ENABLE
   	    SET_BIT(ADCSRA,ADCSRA_ADIE);
      #endif
   	/*ENABLE MODULE*/
   	SET_BIT(ADCSRA,ADCSRA_ADEN);

   }

   u8 ADC_u8readchannel_synchronous(u8 copy_u8channel)
   {
   	/*choose channel*/
     //f32 volt;
   	ADMUX = ADMUX & 0b11100000 ;  /*clear firt five bits*/
   	ADMUX = ADMUX | copy_u8channel;  /*put value in five bits*/

   	/*start conversion*/
   	SET_BIT(ADCSRA,ADCSRA_ADSC);

   	/*WAIT FLAG*/
   	while( !GIT_BIT(ADCSRA,ADCSRA_ADIF));

       #if   INTERRUPT  ==  DISABLE
   	   /*clear flag*/
   	   SET_BIT(ADCSRA,ADCSRA_ADIF);
      #endif
   	   /*volt=(ADCH*5.0)/(255.0);*/
   	return ADCH;

   }
   void callback_func(void(* callback)(void))
   {
   	if(callback !=NULL)
   	{
   		func=callback;
   	}
   }

   void __vector_16__(void)__attribute__((signal));
   void __vector_16__(void)
   {

   	if(func !=NULL)
   	{
   		func();
   	}
   }


