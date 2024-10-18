/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_1.c
 *
 * Code generated for Simulink model 'Final_Project_1'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Oct 15 17:38:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_Project_1.h"
#include "rtwtypes.h"
#include "Final_Project_1_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Final_Projec_finally_IN_ACC_off (1UL)
#define Final_Project_1_IN_ACC_off     (1UL)

/* Block states (default storage) */
DW_Final_Project_1_T Final_Project_1_DW;

/* Real-time model */
static RT_MODEL_Final_Project_1_T Final_Project_1_M_;
RT_MODEL_Final_Project_1_T *const Final_Project_1_M = &Final_Project_1_M_;

/* Model step function */
void Final_Project_1_step(void)
{
  /* Chart: '<Root>/Chart' */
  if (Final_Project_1_DW.is_active_c3_Final_Project_1 == 0U) {
    Final_Project_1_DW.is_active_c3_Final_Project_1 = 1U;
    Final_Project_1_DW.is_c3_Final_Project_1 = Final_Project_1_IN_ACC_off;
    Final_Project_1_DW.is_finally_c3_Final_Project_1 =
      Final_Projec_finally_IN_ACC_off;

    /* LED_OFF(); */
  }

  /* End of Chart: '<Root>/Chart' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Final_Project_1_M->Timing.taskTime0 =
    ((time_T)(++Final_Project_1_M->Timing.clockTick0)) *
    Final_Project_1_M->Timing.stepSize0;
}

/* Model initialize function */
void Final_Project_1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Final_Project_1_M, -1);
  Final_Project_1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Final_Project_1_M->Sizes.checksums[0] = (3799823329U);
  Final_Project_1_M->Sizes.checksums[1] = (2594553687U);
  Final_Project_1_M->Sizes.checksums[2] = (3369262613U);
  Final_Project_1_M->Sizes.checksums[3] = (3175428623U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Final_Project_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_Project_1_M->extModeInfo,
      &Final_Project_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_Project_1_M->extModeInfo,
                        Final_Project_1_M->Sizes.checksums);
    rteiSetTPtr(Final_Project_1_M->extModeInfo, rtmGetTPtr(Final_Project_1_M));
  }
}

/* Model terminate function */
void Final_Project_1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
