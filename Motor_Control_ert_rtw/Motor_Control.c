/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Control.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Oct 15 14:07:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_Control.h"
#include "Motor_Control_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Motor_Control_T Motor_Control_B;

/* Block states (default storage) */
DW_Motor_Control_T Motor_Control_DW;

/* Real-time model */
static RT_MODEL_Motor_Control_T Motor_Control_M_;
RT_MODEL_Motor_Control_T *const Motor_Control_M = &Motor_Control_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Motor_Control_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      real_T b_rem;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (Motor_Control_M->Timing.rtmDbBufWriteBuf1) {
       case 0:
        Motor_Control_M->Timing.rtmDbBufReadBuf1 = 1;
        break;

       case 1:
        Motor_Control_M->Timing.rtmDbBufReadBuf1 = 0;
        break;

       default:
        Motor_Control_M->Timing.rtmDbBufReadBuf1 =
          Motor_Control_M->Timing.rtmDbBufLastBufWr1;
        break;
      }

      Motor_Control_M->Timing.clockTick1 =
        Motor_Control_M->Timing.rtmDbBufClockTick1
        [Motor_Control_M->Timing.rtmDbBufReadBuf1];
      Motor_Control_M->Timing.rtmDbBufReadBuf1 = 0xFF;

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S1>/Constant'
       *  UnitDelay: '<S1>/Unit Delay'
       */
      Motor_Control_DW.UnitDelay_DSTATE += Motor_Control_P.Constant_Value;

      /* MATLAB Function: '<S1>/MATLAB Function' */
      if (rtIsNaN(Motor_Control_DW.UnitDelay_DSTATE)) {
        b_rem = (rtNaN);
      } else if (rtIsInf(Motor_Control_DW.UnitDelay_DSTATE)) {
        b_rem = (rtNaN);
      } else if (Motor_Control_DW.UnitDelay_DSTATE == 0.0) {
        b_rem = 0.0;
      } else {
        b_rem = fmod(Motor_Control_DW.UnitDelay_DSTATE, 2.0);
        if (b_rem == 0.0) {
          b_rem = 0.0;
        } else if (Motor_Control_DW.UnitDelay_DSTATE < 0.0) {
          b_rem += 2.0;
        }
      }

      Motor_Control_B.y = !(b_rem == 0.0);

      /* End of MATLAB Function: '<S1>/MATLAB Function' */
      Motor_Control_DW.FunctionCallSubsystem_SubsysRan = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* RateTransition: '<Root>/Rate Transition1' */
    switch (Motor_Control_DW.RateTransition1_read_buf) {
     case 0:
      Motor_Control_DW.RateTransition1_write_buf = 1;
      break;

     case 1:
      Motor_Control_DW.RateTransition1_write_buf = 0;
      break;

     default:
      Motor_Control_DW.RateTransition1_write_buf = (int8_T)
        (Motor_Control_DW.RateTransition1_last_buf_wr == 0);
      break;
    }

    if (Motor_Control_DW.RateTransition1_write_buf != 0) {
      Motor_Control_DW.RateTransition1_Buffer1 = Motor_Control_B.y;
    } else {
      Motor_Control_DW.RateTransition1_Buffer0 = Motor_Control_B.y;
    }

    Motor_Control_DW.RateTransition1_last_buf_wr =
      Motor_Control_DW.RateTransition1_write_buf;
    Motor_Control_DW.RateTransition1_write_buf = -1;

    /* End of RateTransition: '<Root>/Rate Transition1' */
  }

  currentTime = (extmodeSimulationTime_T) Motor_Control_M->Timing.clockTick0;
  extmodeEvent(1,currentTime);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Motor_Control_step(void)
{
  real_T tmp;
  uint16_T b_varargout_1;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Motor_Control_DW.obj.SampleTime != Motor_Control_P.AnalogInput_SampleTime)
  {
    Motor_Control_DW.obj.SampleTime = Motor_Control_P.AnalogInput_SampleTime;
  }

  Motor_Control_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (Motor_Control_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  Motor_Control_B.DataTypeConversion = (uint8_T)(((uint32_T)
    Motor_Control_P.Gain_Gain * b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/PWM' */
  Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      Motor_Control_B.DataTypeConversion);

  /* RateTransition: '<Root>/Rate Transition1' */
  switch (Motor_Control_DW.RateTransition1_write_buf) {
   case 0:
    Motor_Control_DW.RateTransition1_read_buf = 1;
    break;

   case 1:
    Motor_Control_DW.RateTransition1_read_buf = 0;
    break;

   default:
    Motor_Control_DW.RateTransition1_read_buf =
      Motor_Control_DW.RateTransition1_last_buf_wr;
    break;
  }

  if (Motor_Control_DW.RateTransition1_read_buf != 0) {
    /* RateTransition: '<Root>/Rate Transition1' */
    Motor_Control_B.RateTransition1 = Motor_Control_DW.RateTransition1_Buffer1;
  } else {
    /* RateTransition: '<Root>/Rate Transition1' */
    Motor_Control_B.RateTransition1 = Motor_Control_DW.RateTransition1_Buffer0;
  }

  Motor_Control_DW.RateTransition1_read_buf = -1;

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(Motor_Control_B.RateTransition1);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Motor_Control_M->Timing.taskTime0 =
    ((time_T)(++Motor_Control_M->Timing.clockTick0)) *
    Motor_Control_M->Timing.stepSize0;
  switch (Motor_Control_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    Motor_Control_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    Motor_Control_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    Motor_Control_M->Timing.rtmDbBufWriteBuf1 =
      !Motor_Control_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  Motor_Control_M->Timing.rtmDbBufClockTick1
    [Motor_Control_M->Timing.rtmDbBufWriteBuf1] =
    Motor_Control_M->Timing.clockTick0;
  Motor_Control_M->Timing.rtmDbBufLastBufWr1 =
    Motor_Control_M->Timing.rtmDbBufWriteBuf1;
  Motor_Control_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void Motor_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Motor_Control_M, -1);
  Motor_Control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Motor_Control_M->Sizes.checksums[0] = (2589683628U);
  Motor_Control_M->Sizes.checksums[1] = (3351072239U);
  Motor_Control_M->Sizes.checksums[2] = (2733541458U);
  Motor_Control_M->Sizes.checksums[3] = (451698450U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Motor_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &Motor_Control_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)
      &Motor_Control_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Motor_Control_M->extModeInfo,
      &Motor_Control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Motor_Control_M->extModeInfo,
                        Motor_Control_M->Sizes.checksums);
    rteiSetTPtr(Motor_Control_M->extModeInfo, rtmGetTPtr(Motor_Control_M));
  }

  Motor_Control_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  Motor_Control_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  Motor_Control_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  Motor_Control_DW.RateTransition1_Buffer0 =
    Motor_Control_P.RateTransition1_InitialConditio;
  Motor_Control_DW.RateTransition1_write_buf = -1;
  Motor_Control_DW.RateTransition1_read_buf = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Motor_Control_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    Motor_Control_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    Motor_Control_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    Motor_Control_M->Timing.rtmDbBufReadBuf1 =
      Motor_Control_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  Motor_Control_M->Timing.clockTick1 =
    Motor_Control_M->Timing.rtmDbBufClockTick1
    [Motor_Control_M->Timing.rtmDbBufReadBuf1];
  Motor_Control_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* InitializeConditions for Sum: '<S1>/Sum' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Motor_Control_DW.UnitDelay_DSTATE = Motor_Control_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S1>/Out1' */
  Motor_Control_B.y = Motor_Control_P.Out1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  Motor_Control_DW.obj.matlabCodegenIsDeleted = false;
  Motor_Control_DW.obj.SampleTime = Motor_Control_P.AnalogInput_SampleTime;
  Motor_Control_DW.obj.isInitialized = 1L;
  Motor_Control_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  Motor_Control_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  Motor_Control_DW.obj_m.matlabCodegenIsDeleted = false;
  Motor_Control_DW.obj_m.isInitialized = 1L;
  Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  Motor_Control_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  Motor_Control_DW.obj_e.matlabCodegenIsDeleted = false;
  Motor_Control_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Motor_Control_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void Motor_Control_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!Motor_Control_DW.obj.matlabCodegenIsDeleted) {
    Motor_Control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Motor_Control_DW.obj.isInitialized == 1L) &&
        Motor_Control_DW.obj.isSetupComplete) {
      Motor_Control_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (Motor_Control_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!Motor_Control_DW.obj_m.matlabCodegenIsDeleted) {
    Motor_Control_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Motor_Control_DW.obj_m.isInitialized == 1L) &&
        Motor_Control_DW.obj_m.isSetupComplete) {
      Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Motor_Control_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Motor_Control_DW.obj_e.matlabCodegenIsDeleted) {
    Motor_Control_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
