/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_Final_Project_2024.c
 *
 * Code generated for Simulink model 'Copy_of_Final_Project_2024'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Oct 15 17:19:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_Final_Project_2024.h"
#include "rtwtypes.h"
#include "Copy_of_Final_Project_2024_private.h"

/* Block signals (default storage) */
B_Copy_of_Final_Project_2024_T Copy_of_Final_Project_2024_B;

/* Block states (default storage) */
DW_Copy_of_Final_Project_2024_T Copy_of_Final_Project_2024_DW;

/* Real-time model */
static RT_MODEL_Copy_of_Final_Projec_T Copy_of_Final_Project_2024_M_;
RT_MODEL_Copy_of_Final_Projec_T *const Copy_of_Final_Project_2024_M =
  &Copy_of_Final_Project_2024_M_;

/* Model step function */
void Copy_of_Final_Project_2024_step(void)
{
  /* MATLABSystem: '<Root>/Analog Input' */
  if (Copy_of_Final_Project_2024_DW.obj.SampleTime !=
      Copy_of_Final_Project_2024_P.AnalogInput_SampleTime) {
    Copy_of_Final_Project_2024_DW.obj.SampleTime =
      Copy_of_Final_Project_2024_P.AnalogInput_SampleTime;
  }

  Copy_of_Final_Project_2024_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (Copy_of_Final_Project_2024_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &Copy_of_Final_Project_2024_B.AnalogInput, MW_ANALOGIN_UINT16);

  /* Gain: '<Root>/Gain1' */
  Copy_of_Final_Project_2024_B.Gain1 = (uint32_T)
    Copy_of_Final_Project_2024_P.Gain1_Gain *
    Copy_of_Final_Project_2024_B.AnalogInput;

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain1'
   */
  writeDigitalPin(13, (uint8_T)(Copy_of_Final_Project_2024_B.Gain1 >> 17));

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Copy_of_Final_Project_2024_M->Timing.taskTime0 =
    ((time_T)(++Copy_of_Final_Project_2024_M->Timing.clockTick0)) *
    Copy_of_Final_Project_2024_M->Timing.stepSize0;
}

/* Model initialize function */
void Copy_of_Final_Project_2024_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Copy_of_Final_Project_2024_M, -1);
  Copy_of_Final_Project_2024_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Copy_of_Final_Project_2024_M->Sizes.checksums[0] = (1266029478U);
  Copy_of_Final_Project_2024_M->Sizes.checksums[1] = (3764739569U);
  Copy_of_Final_Project_2024_M->Sizes.checksums[2] = (1514160268U);
  Copy_of_Final_Project_2024_M->Sizes.checksums[3] = (57196732U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Copy_of_Final_Project_2024_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Copy_of_Final_Project_2024_M->extModeInfo,
      &Copy_of_Final_Project_2024_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Copy_of_Final_Project_2024_M->extModeInfo,
                        Copy_of_Final_Project_2024_M->Sizes.checksums);
    rteiSetTPtr(Copy_of_Final_Project_2024_M->extModeInfo, rtmGetTPtr
                (Copy_of_Final_Project_2024_M));
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  Copy_of_Final_Project_2024_DW.obj.matlabCodegenIsDeleted = false;
  Copy_of_Final_Project_2024_DW.obj.SampleTime =
    Copy_of_Final_Project_2024_P.AnalogInput_SampleTime;
  Copy_of_Final_Project_2024_DW.obj.isInitialized = 1L;
  Copy_of_Final_Project_2024_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(56UL);
  Copy_of_Final_Project_2024_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  Copy_of_Final_Project_2024_DW.obj_d.matlabCodegenIsDeleted = false;
  Copy_of_Final_Project_2024_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Copy_of_Final_Project_2024_DW.obj_d.isSetupComplete = true;
}

/* Model terminate function */
void Copy_of_Final_Project_2024_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!Copy_of_Final_Project_2024_DW.obj.matlabCodegenIsDeleted) {
    Copy_of_Final_Project_2024_DW.obj.matlabCodegenIsDeleted = true;
    if ((Copy_of_Final_Project_2024_DW.obj.isInitialized == 1L) &&
        Copy_of_Final_Project_2024_DW.obj.isSetupComplete) {
      Copy_of_Final_Project_2024_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(56UL);
      MW_AnalogIn_Close
        (Copy_of_Final_Project_2024_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!Copy_of_Final_Project_2024_DW.obj_d.matlabCodegenIsDeleted) {
    Copy_of_Final_Project_2024_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
