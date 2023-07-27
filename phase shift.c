#include "F28x_Project.h"
void Gpio_select(void);
void Setup_ePWM(void);

void main(void)
{
   InitSysCtrl();
   DINT;
   Gpio_select();
   Setup_ePWM();
   while(1);
   {
   }
}
//
void Gpio_select(void)
{
    EALLOW;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0=1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2=1;

    EDIS;
}

void Setup_ePWM(void)
{
        EPwm1Regs.TBCTL.bit.CLKDIV = 1;
        EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;
        EPwm1Regs.TBCTL.bit.CTRMODE = 0;
        EPwm1Regs.TBPRD = 25000;
        EPwm1Regs.CMPA.bit.CMPA = 75000;
        EPwm1Regs.AQCTLA.all = 0x0012;

        EPwm1Regs.TBCTL.bit.PHSEN = 0;
        EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;

        EPwm2Regs.TBCTL.bit.CLKDIV = 1;
        EPwm2Regs.TBCTL.bit.HSPCLKDIV = 1;
        EPwm2Regs.TBCTL.bit.CTRMODE = 0;
        EPwm2Regs.TBPRD = 25000;
        EPwm2Regs.CMPA.bit.CMPA = 75000;
        EPwm2Regs.AQCTLA.all = 0x0012;

        EPwm2Regs.TBCTL.bit.PHSEN = 1;
        EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;
        EPwm2Regs.TBPHS.bit.TBPHS = 2083;

}
