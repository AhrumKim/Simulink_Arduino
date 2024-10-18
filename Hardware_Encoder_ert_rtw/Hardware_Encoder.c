/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Hardware_Encoder.c
 *
 * Code generated for Simulink model 'Hardware_Encoder'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Oct 15 14:14:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Hardware_Encoder.h"
#include "Hardware_Encoder_private.h"

/* Block signals (default storage) */
B_Hardware_Encoder_T Hardware_Encoder_B;

/* Block states (default storage) */
DW_Hardware_Encoder_T Hardware_Encoder_DW;

/* Real-time model */
static RT_MODEL_Hardware_Encoder_T Hardware_Encoder_M_;
RT_MODEL_Hardware_Encoder_T *const Hardware_Encoder_M = &Hardware_Encoder_M_;

/* Model step function */
void Hardware_Encoder_step(void)
{
  /* MATLABSystem: '<Root>/Encoder1' */
  if (Hardware_Encoder_DW.obj.SampleTime !=
      Hardware_Encoder_P.Encoder1_SampleTime) {
    Hardware_Encoder_DW.obj.SampleTime = Hardware_Encoder_P.Encoder1_SampleTime;
  }

  if (Hardware_Encoder_DW.obj.TunablePropsChanged) {
    Hardware_Encoder_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder1' */
  MW_EncoderRead(Hardware_Encoder_DW.obj.Index, &Hardware_Encoder_B.Encoder1);

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Hardware_Encoder_M->Timing.taskTime0 =
    ((time_T)(++Hardware_Encoder_M->Timing.clockTick0)) *
    Hardware_Encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void Hardware_Encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Hardware_Encoder_M, 20.0);
  Hardware_Encoder_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Hardware_Encoder_M->Sizes.checksums[0] = (1449608592U);
  Hardware_Encoder_M->Sizes.checksums[1] = (1080417385U);
  Hardware_Encoder_M->Sizes.checksums[2] = (358274785U);
  Hardware_Encoder_M->Sizes.checksums[3] = (3256322629U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Hardware_Encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Hardware_Encoder_M->extModeInfo,
      &Hardware_Encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Hardware_Encoder_M->extModeInfo,
                        Hardware_Encoder_M->Sizes.checksums);
    rteiSetTPtr(Hardware_Encoder_M->extModeInfo, rtmGetTPtr(Hardware_Encoder_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  Hardware_Encoder_DW.obj.Index = 0U;
  Hardware_Encoder_DW.obj.matlabCodegenIsDeleted = false;
  Hardware_Encoder_DW.obj.SampleTime = Hardware_Encoder_P.Encoder1_SampleTime;
  Hardware_Encoder_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Hardware_Encoder_DW.obj.Index);
  Hardware_Encoder_DW.obj.isSetupComplete = true;
  Hardware_Encoder_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder1' */
  MW_EncoderReset(Hardware_Encoder_DW.obj.Index);
}

/* Model terminate function */
void Hardware_Encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!Hardware_Encoder_DW.obj.matlabCodegenIsDeleted) {
    Hardware_Encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((Hardware_Encoder_DW.obj.isInitialized == 1L) &&
        Hardware_Encoder_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
