/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: interrupt.c
 *
 * Code generated for Simulink model 'interrupt'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 17:01:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "interrupt.h"
#include "interrupt_private.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_interrupt_T interrupt_B;

/* Block states (default storage) */
DW_interrupt_T interrupt_DW;

/* Real-time model */
static RT_MODEL_interrupt_T interrupt_M_;
RT_MODEL_interrupt_T *const interrupt_M = &interrupt_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(interrupt_DW.FunctionCallSubsystem_SubsysRan);

    /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
    interrupt_B.TmpRTBAtFunctionCallSubsystemIn = interrupt_B.NOT;

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (interrupt_M->Timing.rtmDbBufWriteBuf1) {
     case 0:
      interrupt_M->Timing.rtmDbBufReadBuf1 = 1;
      break;

     case 1:
      interrupt_M->Timing.rtmDbBufReadBuf1 = 0;
      break;

     default:
      interrupt_M->Timing.rtmDbBufReadBuf1 =
        interrupt_M->Timing.rtmDbBufLastBufWr1;
      break;
    }

    interrupt_M->Timing.clockTick1 = interrupt_M->
      Timing.rtmDbBufClockTick1[interrupt_M->Timing.rtmDbBufReadBuf1];
    interrupt_M->Timing.rtmDbBufReadBuf1 = 0xFF;

    /* SignalConversion generated from: '<S1>/In1' */
    interrupt_B.In1 = interrupt_B.TmpRTBAtFunctionCallSubsystemIn;
    interrupt_DW.FunctionCallSubsystem_SubsysRan = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }

  currentTime = (extmodeSimulationTime_T) interrupt_M->Timing.clockTick0;
  extmodeEvent(1,currentTime);
}

/* Model step function */
void interrupt_step(void)
{
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (interrupt_DW.clockTickCounter <
                        interrupt_P.PulseGenerator_Duty) &&
    (interrupt_DW.clockTickCounter >= 0L) ? interrupt_P.PulseGenerator_Amp : 0.0;
  if (interrupt_DW.clockTickCounter >= interrupt_P.PulseGenerator_Period - 1.0)
  {
    interrupt_DW.clockTickCounter = 0L;
  } else {
    interrupt_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Cast To Boolean' */
  interrupt_B.CastToBoolean = (rtb_PulseGenerator != 0.0);

  /* Logic: '<Root>/NOT' incorporates:
   *  Delay: '<Root>/Delay'
   */
  interrupt_B.NOT = !interrupt_DW.Delay_DSTATE;

  /* RateTransition: '<Root>/Rate Transition' */
  interrupt_B.RateTransition = interrupt_B.In1;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(12, (uint8_T)interrupt_B.RateTransition);

  /* Update for Delay: '<Root>/Delay' */
  interrupt_DW.Delay_DSTATE = interrupt_B.RateTransition;

  {                                    /* Sample time: [0.5s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  interrupt_M->Timing.taskTime0 =
    ((time_T)(++interrupt_M->Timing.clockTick0)) * interrupt_M->Timing.stepSize0;
  switch (interrupt_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    interrupt_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    interrupt_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    interrupt_M->Timing.rtmDbBufWriteBuf1 =
      !interrupt_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  interrupt_M->Timing.rtmDbBufClockTick1[interrupt_M->Timing.rtmDbBufWriteBuf1] =
    interrupt_M->Timing.clockTick0;
  interrupt_M->Timing.rtmDbBufLastBufWr1 = interrupt_M->Timing.rtmDbBufWriteBuf1;
  interrupt_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void interrupt_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(interrupt_M, -1);
  interrupt_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  interrupt_M->Sizes.checksums[0] = (2004701758U);
  interrupt_M->Sizes.checksums[1] = (247239447U);
  interrupt_M->Sizes.checksums[2] = (1230442763U);
  interrupt_M->Sizes.checksums[3] = (1326499308U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    interrupt_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&interrupt_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(interrupt_M->extModeInfo,
      &interrupt_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(interrupt_M->extModeInfo, interrupt_M->Sizes.checksums);
    rteiSetTPtr(interrupt_M->extModeInfo, rtmGetTPtr(interrupt_M));
  }

  interrupt_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  interrupt_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  interrupt_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  interrupt_DW.Delay_DSTATE = interrupt_P.Delay_InitialCondition;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (interrupt_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    interrupt_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    interrupt_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    interrupt_M->Timing.rtmDbBufReadBuf1 =
      interrupt_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  interrupt_M->Timing.clockTick1 = interrupt_M->
    Timing.rtmDbBufClockTick1[interrupt_M->Timing.rtmDbBufReadBuf1];
  interrupt_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* SystemInitialize for SignalConversion generated from: '<S1>/In1' incorporates:
   *  Outport: '<S1>/Out1'
   */
  interrupt_B.In1 = interrupt_P.Out1_Y0;
  pinMode(2, INPUT_PULLUP);

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  interrupt_DW.obj.matlabCodegenIsDeleted = false;
  interrupt_DW.obj.isInitialized = 1L;
  digitalIOSetup(12, 1);
  interrupt_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void interrupt_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!interrupt_DW.obj.matlabCodegenIsDeleted) {
    interrupt_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
