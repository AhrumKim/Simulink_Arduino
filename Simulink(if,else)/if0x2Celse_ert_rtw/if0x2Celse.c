/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: if0x2Celse.c
 *
 * Code generated for Simulink model 'if0x2Celse'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 15:14:39 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "if0x2Celse.h"
#include "rtwtypes.h"
#include "if0x2Celse_private.h"

/* Block signals (default storage) */
B_if0x2Celse_T if0x2Celse_B;

/* Block states (default storage) */
DW_if0x2Celse_T if0x2Celse_DW;

/* Real-time model */
static RT_MODEL_if0x2Celse_T if0x2Celse_M_;
RT_MODEL_if0x2Celse_T *const if0x2Celse_M = &if0x2Celse_M_;

/* Model step function */
void if0x2Celse_step(void)
{
  real_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(if0x2Celse_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(if0x2Celse_DW.IfActionSubsystem_SubsysRanBC);

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step2'
   */
  tmp = if0x2Celse_M->Timing.t[0];
  if (tmp < if0x2Celse_P.Step1_Time) {
    /* Step: '<Root>/Step1' */
    if0x2Celse_B.Step1 = if0x2Celse_P.Step1_Y0;
  } else {
    /* Step: '<Root>/Step1' */
    if0x2Celse_B.Step1 = if0x2Celse_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* If: '<Root>/If' */
  if (if0x2Celse_B.Step1 > 2.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant'
     *  SignalConversion generated from: '<S2>/In1'
     */
    if0x2Celse_B.Merge = if0x2Celse_P.Constant_Value;
    srUpdateBC(if0x2Celse_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant1'
     *  SignalConversion generated from: '<S1>/In1'
     */
    if0x2Celse_B.Merge = if0x2Celse_P.Constant1_Value;
    srUpdateBC(if0x2Celse_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/If' */
  /* Step: '<Root>/Step2' */
  if (tmp < if0x2Celse_P.Step2_Time) {
    /* Step: '<Root>/Step2' */
    if0x2Celse_B.Step2 = if0x2Celse_P.Step2_Y0;
  } else {
    /* Step: '<Root>/Step2' */
    if0x2Celse_B.Step2 = if0x2Celse_P.Step2_YFinal;
  }

  /* Switch: '<Root>/Switch' */
  if (if0x2Celse_B.Step2 > if0x2Celse_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if0x2Celse_B.Switch = if0x2Celse_P.Constant2_Value;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    if0x2Celse_B.Switch = if0x2Celse_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch' */
  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((if0x2Celse_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((if0x2Celse_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  if0x2Celse_M->Timing.t[0] =
    ((time_T)(++if0x2Celse_M->Timing.clockTick0)) *
    if0x2Celse_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    if0x2Celse_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void if0x2Celse_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&if0x2Celse_M->solverInfo,
                          &if0x2Celse_M->Timing.simTimeStep);
    rtsiSetTPtr(&if0x2Celse_M->solverInfo, &rtmGetTPtr(if0x2Celse_M));
    rtsiSetStepSizePtr(&if0x2Celse_M->solverInfo,
                       &if0x2Celse_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&if0x2Celse_M->solverInfo, (&rtmGetErrorStatus
      (if0x2Celse_M)));
    rtsiSetRTModelPtr(&if0x2Celse_M->solverInfo, if0x2Celse_M);
  }

  rtsiSetSimTimeStep(&if0x2Celse_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&if0x2Celse_M->solverInfo, false);
  rtsiSetSolverName(&if0x2Celse_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(if0x2Celse_M, &if0x2Celse_M->Timing.tArray[0]);
  rtmSetTFinal(if0x2Celse_M, -1);
  if0x2Celse_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  if0x2Celse_M->Sizes.checksums[0] = (1283083962U);
  if0x2Celse_M->Sizes.checksums[1] = (1833879920U);
  if0x2Celse_M->Sizes.checksums[2] = (1224761914U);
  if0x2Celse_M->Sizes.checksums[3] = (159571909U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    if0x2Celse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&if0x2Celse_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&if0x2Celse_DW.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(if0x2Celse_M->extModeInfo,
      &if0x2Celse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(if0x2Celse_M->extModeInfo, if0x2Celse_M->Sizes.checksums);
    rteiSetTPtr(if0x2Celse_M->extModeInfo, rtmGetTPtr(if0x2Celse_M));
  }
}

/* Model terminate function */
void if0x2Celse_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
