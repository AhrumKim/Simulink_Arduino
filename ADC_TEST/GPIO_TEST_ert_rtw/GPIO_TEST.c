/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GPIO_TEST.c
 *
 * Code generated for Simulink model 'GPIO_TEST'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 14:01:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GPIO_TEST.h"
#include "rtwtypes.h"
#include "GPIO_TEST_private.h"

/* Block signals (default storage) */
B_GPIO_TEST_T GPIO_TEST_B;

/* Block states (default storage) */
DW_GPIO_TEST_T GPIO_TEST_DW;

/* Real-time model */
static RT_MODEL_GPIO_TEST_T GPIO_TEST_M_;
RT_MODEL_GPIO_TEST_T *const GPIO_TEST_M = &GPIO_TEST_M_;

/* Model step function */
void GPIO_TEST_step(void)
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (GPIO_TEST_DW.obj.SampleTime != GPIO_TEST_P.AnalogInput_SampleTime) {
    GPIO_TEST_DW.obj.SampleTime = GPIO_TEST_P.AnalogInput_SampleTime;
  }

  GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (54UL);
  MW_AnalogInSingle_ReadResult
    (GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  GPIO_TEST_B.Gain = (uint32_T)GPIO_TEST_P.Gain_Gain * b_varargout_1;

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
}

/* Model initialize function */
void GPIO_TEST_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(GPIO_TEST_M, -1);
  GPIO_TEST_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  GPIO_TEST_M->Sizes.checksums[0] = (4147748066U);
  GPIO_TEST_M->Sizes.checksums[1] = (2339354678U);
  GPIO_TEST_M->Sizes.checksums[2] = (2623266239U);
  GPIO_TEST_M->Sizes.checksums[3] = (1620840593U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    GPIO_TEST_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GPIO_TEST_M->extModeInfo,
      &GPIO_TEST_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GPIO_TEST_M->extModeInfo, GPIO_TEST_M->Sizes.checksums);
    rteiSetTPtr(GPIO_TEST_M->extModeInfo, rtmGetTPtr(GPIO_TEST_M));
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  GPIO_TEST_DW.obj.matlabCodegenIsDeleted = false;
  GPIO_TEST_DW.obj.SampleTime = GPIO_TEST_P.AnalogInput_SampleTime;
  GPIO_TEST_DW.obj.isInitialized = 1L;
  GPIO_TEST_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (54UL);
  GPIO_TEST_DW.obj.isSetupComplete = true;
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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
