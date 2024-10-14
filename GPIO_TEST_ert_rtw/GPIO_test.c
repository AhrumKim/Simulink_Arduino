/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GPIO_TEST.c
 *
 * Code generated for Simulink model 'GPIO_TEST'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Oct 14 13:46:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GPIO_TEST.h"
#include "GPIO_TEST_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_GPIO_TEST_T GPIO_TEST_B;

/* Block states (default storage) */
DW_GPIO_TEST_T GPIO_TEST_DW;

/* Real-time model */
static RT_MODEL_GPIO_TEST_T GPIO_TEST_M_;
RT_MODEL_GPIO_TEST_T *const GPIO_TEST_M = &GPIO_TEST_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(GPIO_TEST_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      /* local block i/o variables */
      real_T rtb_Sum;
      real_T rtb_DiscreteStateSpace;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (GPIO_TEST_M->Timing.rtmDbBufWriteBuf1) {
       case 0:
        GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 1;
        break;

       case 1:
        GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 0;
        break;

       default:
        GPIO_TEST_M->Timing.rtmDbBufReadBuf1 =
          GPIO_TEST_M->Timing.rtmDbBufLastBufWr1;
        break;
      }

      GPIO_TEST_M->Timing.clockTick1 = GPIO_TEST_M->
        Timing.rtmDbBufClockTick1[GPIO_TEST_M->Timing.rtmDbBufReadBuf1];
      GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 0xFF;

      /* DiscreteStateSpace: '<S2>/Discrete State Space' */
      {
        rtb_DiscreteStateSpace = GPIO_TEST_P.DiscreteStateSpace_C*
          GPIO_TEST_DW.DiscreteStateSpace_DSTATE;
      }

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S1>/Constant'
       */
      rtb_Sum = GPIO_TEST_P.Constant_Value + rtb_DiscreteStateSpace;

      /* MATLAB Function: '<S1>/MATLAB Function' */
      GPIO_TEST_B.y = rtb_Sum;

      /* Update for DiscreteStateSpace: '<S2>/Discrete State Space' */
      {
        GPIO_TEST_DW.DiscreteStateSpace_DSTATE = rtb_Sum +
          (GPIO_TEST_P.DiscreteStateSpace_A)*
          GPIO_TEST_DW.DiscreteStateSpace_DSTATE;
      }

      GPIO_TEST_DW.FunctionCallSubsystem_SubsysRan = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* RateTransition: '<Root>/Rate Transition' */
    switch (GPIO_TEST_DW.RateTransition_read_buf) {
     case 0:
      GPIO_TEST_DW.RateTransition_write_buf = 1;
      break;

     case 1:
      GPIO_TEST_DW.RateTransition_write_buf = 0;
      break;

     default:
      GPIO_TEST_DW.RateTransition_write_buf = (int8_T)
        (GPIO_TEST_DW.RateTransition_last_buf_wr == 0);
      break;
    }

    if (GPIO_TEST_DW.RateTransition_write_buf != 0) {
      GPIO_TEST_DW.RateTransition_Buffer1 = GPIO_TEST_B.y;
    } else {
      GPIO_TEST_DW.RateTransition_Buffer0 = GPIO_TEST_B.y;
    }

    GPIO_TEST_DW.RateTransition_last_buf_wr =
      GPIO_TEST_DW.RateTransition_write_buf;
    GPIO_TEST_DW.RateTransition_write_buf = -1;

    /* End of RateTransition: '<Root>/Rate Transition' */
  }

  currentTime = (extmodeSimulationTime_T) GPIO_TEST_M->Timing.clockTick0;
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
void GPIO_TEST_step(void)
{
  real_T tmp;
  uint16_T b_varargout_1;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (GPIO_TEST_DW.obj.SampleTime != GPIO_TEST_P.AnalogInput_SampleTime) {
    GPIO_TEST_DW.obj.SampleTime = GPIO_TEST_P.AnalogInput_SampleTime;
  }

  GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (54UL);
  MW_AnalogInSingle_ReadResult
    (GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  GPIO_TEST_B.DataTypeConversion = (uint8_T)(((uint32_T)GPIO_TEST_P.Gain_Gain *
    b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/PWM1' */
  GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      GPIO_TEST_B.DataTypeConversion);

  /* RateTransition: '<Root>/Rate Transition' */
  switch (GPIO_TEST_DW.RateTransition_write_buf) {
   case 0:
    GPIO_TEST_DW.RateTransition_read_buf = 1;
    break;

   case 1:
    GPIO_TEST_DW.RateTransition_read_buf = 0;
    break;

   default:
    GPIO_TEST_DW.RateTransition_read_buf =
      GPIO_TEST_DW.RateTransition_last_buf_wr;
    break;
  }

  if (GPIO_TEST_DW.RateTransition_read_buf != 0) {
    /* RateTransition: '<Root>/Rate Transition' */
    GPIO_TEST_B.RateTransition = GPIO_TEST_DW.RateTransition_Buffer1;
  } else {
    /* RateTransition: '<Root>/Rate Transition' */
    GPIO_TEST_B.RateTransition = GPIO_TEST_DW.RateTransition_Buffer0;
  }

  GPIO_TEST_DW.RateTransition_read_buf = -1;

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* MATLABSystem: '<Root>/Digital Output1' */
  tmp = rt_roundd_snf(GPIO_TEST_B.RateTransition);
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

  /* End of MATLABSystem: '<Root>/Digital Output1' */
  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  GPIO_TEST_M->Timing.taskTime0 =
    ((time_T)(++GPIO_TEST_M->Timing.clockTick0)) * GPIO_TEST_M->Timing.stepSize0;
  switch (GPIO_TEST_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    GPIO_TEST_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    GPIO_TEST_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    GPIO_TEST_M->Timing.rtmDbBufWriteBuf1 =
      !GPIO_TEST_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  GPIO_TEST_M->Timing.rtmDbBufClockTick1[GPIO_TEST_M->Timing.rtmDbBufWriteBuf1] =
    GPIO_TEST_M->Timing.clockTick0;
  GPIO_TEST_M->Timing.rtmDbBufLastBufWr1 = GPIO_TEST_M->Timing.rtmDbBufWriteBuf1;
  GPIO_TEST_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void GPIO_TEST_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(GPIO_TEST_M, -1);
  GPIO_TEST_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  GPIO_TEST_M->Sizes.checksums[0] = (2612801450U);
  GPIO_TEST_M->Sizes.checksums[1] = (3074942484U);
  GPIO_TEST_M->Sizes.checksums[2] = (1076021327U);
  GPIO_TEST_M->Sizes.checksums[3] = (580580783U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    GPIO_TEST_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&GPIO_TEST_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)&GPIO_TEST_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GPIO_TEST_M->extModeInfo,
      &GPIO_TEST_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GPIO_TEST_M->extModeInfo, GPIO_TEST_M->Sizes.checksums);
    rteiSetTPtr(GPIO_TEST_M->extModeInfo, rtmGetTPtr(GPIO_TEST_M));
  }

  GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  GPIO_TEST_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  GPIO_TEST_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  GPIO_TEST_DW.RateTransition_Buffer0 =
    GPIO_TEST_P.RateTransition_InitialCondition;
  GPIO_TEST_DW.RateTransition_write_buf = -1;
  GPIO_TEST_DW.RateTransition_read_buf = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (GPIO_TEST_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    GPIO_TEST_M->Timing.rtmDbBufReadBuf1 =
      GPIO_TEST_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  GPIO_TEST_M->Timing.clockTick1 = GPIO_TEST_M->
    Timing.rtmDbBufClockTick1[GPIO_TEST_M->Timing.rtmDbBufReadBuf1];
  GPIO_TEST_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* InitializeConditions for DiscreteStateSpace: '<S2>/Discrete State Space' */
  GPIO_TEST_DW.DiscreteStateSpace_DSTATE =
    GPIO_TEST_P.DiscreteTransferFcnwithinitials;

  /* SystemInitialize for Outport: '<S1>/1' */
  GPIO_TEST_B.y = GPIO_TEST_P.u_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  GPIO_TEST_DW.obj.matlabCodegenIsDeleted = false;
  GPIO_TEST_DW.obj.SampleTime = GPIO_TEST_P.AnalogInput_SampleTime;
  GPIO_TEST_DW.obj.isInitialized = 1L;
  GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (54UL);
  GPIO_TEST_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  GPIO_TEST_DW.obj_b.matlabCodegenIsDeleted = false;
  GPIO_TEST_DW.obj_b.isInitialized = 1L;
  GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  GPIO_TEST_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  GPIO_TEST_DW.obj_j.matlabCodegenIsDeleted = false;
  GPIO_TEST_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(13, 1);
  GPIO_TEST_DW.obj_j.isSetupComplete = true;
}

/* Model terminate function */
void GPIO_TEST_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!GPIO_TEST_DW.obj.matlabCodegenIsDeleted) {
    GPIO_TEST_DW.obj.matlabCodegenIsDeleted = true;
    if ((GPIO_TEST_DW.obj.isInitialized == 1L) &&
        GPIO_TEST_DW.obj.isSetupComplete) {
      GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!GPIO_TEST_DW.obj_b.matlabCodegenIsDeleted) {
    GPIO_TEST_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((GPIO_TEST_DW.obj_b.isInitialized == 1L) &&
        GPIO_TEST_DW.obj_b.isSetupComplete) {
      GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(GPIO_TEST_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!GPIO_TEST_DW.obj_j.matlabCodegenIsDeleted) {
    GPIO_TEST_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
