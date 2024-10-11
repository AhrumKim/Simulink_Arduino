/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC_test.c
 *
 * Code generated for Simulink model 'ADC_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 14:38:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC_test.h"
#include "rtwtypes.h"
#include "ADC_test_private.h"

/* Block signals (default storage) */
B_ADC_test_T ADC_test_B;

/* Block states (default storage) */
DW_ADC_test_T ADC_test_DW;

/* Real-time model */
static RT_MODEL_ADC_test_T ADC_test_M_;
RT_MODEL_ADC_test_T *const ADC_test_M = &ADC_test_M_;

/* Model step function */
void ADC_test_step(void)
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ADC_test_DW.obj_n.SampleTime != ADC_test_P.AnalogInput_SampleTime) {
    ADC_test_DW.obj_n.SampleTime = ADC_test_P.AnalogInput_SampleTime;
  }

  ADC_test_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (54UL);
  MW_AnalogInSingle_ReadResult
    (ADC_test_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  ADC_test_B.DataTypeConversion = (uint8_T)(((uint32_T)ADC_test_P.Gain_Gain *
    b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (ADC_test_DW.obj.SampleTime != ADC_test_P.AnalogInput1_SampleTime) {
    ADC_test_DW.obj.SampleTime = ADC_test_P.AnalogInput1_SampleTime;
  }

  ADC_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (55UL);
  MW_AnalogInSingle_ReadResult
    (ADC_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  ADC_test_B.DataTypeConversion1 = (uint8_T)(((uint32_T)ADC_test_P.Gain1_Gain *
    b_varargout_1) >> 17);

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ADC_test_M->Timing.taskTime0 =
    ((time_T)(++ADC_test_M->Timing.clockTick0)) * ADC_test_M->Timing.stepSize0;
}

/* Model initialize function */
void ADC_test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ADC_test_M, -1);
  ADC_test_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  ADC_test_M->Sizes.checksums[0] = (2073593547U);
  ADC_test_M->Sizes.checksums[1] = (861035534U);
  ADC_test_M->Sizes.checksums[2] = (1246348807U);
  ADC_test_M->Sizes.checksums[3] = (958152816U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ADC_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ADC_test_M->extModeInfo,
      &ADC_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ADC_test_M->extModeInfo, ADC_test_M->Sizes.checksums);
    rteiSetTPtr(ADC_test_M->extModeInfo, rtmGetTPtr(ADC_test_M));
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ADC_test_DW.obj_n.matlabCodegenIsDeleted = false;
  ADC_test_DW.obj_n.SampleTime = ADC_test_P.AnalogInput_SampleTime;
  ADC_test_DW.obj_n.isInitialized = 1L;
  ADC_test_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  ADC_test_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  ADC_test_DW.obj.matlabCodegenIsDeleted = false;
  ADC_test_DW.obj.SampleTime = ADC_test_P.AnalogInput1_SampleTime;
  ADC_test_DW.obj.isInitialized = 1L;
  ADC_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (55UL);
  ADC_test_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ADC_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!ADC_test_DW.obj_n.matlabCodegenIsDeleted) {
    ADC_test_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((ADC_test_DW.obj_n.isInitialized == 1L) &&
        ADC_test_DW.obj_n.isSetupComplete) {
      ADC_test_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(ADC_test_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!ADC_test_DW.obj.matlabCodegenIsDeleted) {
    ADC_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((ADC_test_DW.obj.isInitialized == 1L) && ADC_test_DW.obj.isSetupComplete)
    {
      ADC_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close(ADC_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
