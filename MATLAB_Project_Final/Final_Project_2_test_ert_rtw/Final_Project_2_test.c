/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_2_test.c
 *
 * Code generated for Simulink model 'Final_Project_2_test'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 18 09:29:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_Project_2_test.h"
#include "Final_Project_2_test_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Final_Project_2_test_T Final_Project_2_test_B;

/* Block states (default storage) */
DW_Final_Project_2_test_T Final_Project_2_test_DW;

/* Real-time model */
static RT_MODEL_Final_Project_2_test_T Final_Project_2_test_M_;
RT_MODEL_Final_Project_2_test_T *const Final_Project_2_test_M =
  &Final_Project_2_test_M_;

/* Callback for Hardware Interrupt Block: '<Root>/SW1 ' */
void MW_ISR_2(void)
{
  /* Call the system: <S2>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_Project_2_test_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/SW1 ' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem' */
    {
      real_T b_rem;
      real_T u;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1) {
       case 0:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 1;
        break;

       case 1:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 0;
        break;

       default:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 =
          Final_Project_2_test_M->Timing.rtmDbBufLastBufWr1;
        break;
      }

      Final_Project_2_test_M->Timing.clockTick1 =
        Final_Project_2_test_M->Timing.rtmDbBufClockTick1
        [Final_Project_2_test_M->Timing.rtmDbBufReadBuf1];
      Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;

      /* Sum: '<S6>/Sum' incorporates:
       *  Constant: '<S6>/Constant'
       *  UnitDelay: '<S6>/Unit Delay'
       */
      Final_Project_2_test_DW.UnitDelay_DSTATE_d +=
        Final_Project_2_test_P.Constant_Value;

      /* MATLAB Function: '<S6>/MATLAB Function' */
      u = Final_Project_2_test_DW.UnitDelay_DSTATE_d;
      if (Final_Project_2_test_DW.UnitDelay_DSTATE_d > 100.0) {
        u = 1.0;
      }

      if (rtIsNaN(u)) {
        b_rem = (rtNaN);
      } else if (rtIsInf(u)) {
        b_rem = (rtNaN);
      } else if (u == 0.0) {
        b_rem = 0.0;
      } else {
        b_rem = fmod(u, 3.0);
        if (b_rem == 0.0) {
          b_rem = 0.0;
        } else if (u < 0.0) {
          b_rem += 3.0;
        }
      }

      if (b_rem == 0.0) {
        Final_Project_2_test_B.y_l = 0.0;
      } else if (b_rem == 1.0) {
        Final_Project_2_test_B.y_l = 1.0;
      } else {
        Final_Project_2_test_B.y_l = 2.0;
      }

      /* End of MATLAB Function: '<S6>/MATLAB Function' */
      Final_Project_2_test_DW.FunctionCallSubsystem_SubsysRan = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/SW1 ' */
  }

  currentTime = (extmodeSimulationTime_T)
    Final_Project_2_test_M->Timing.clockTick0;
  extmodeEvent(1,currentTime);
}

/* Callback for Hardware Interrupt Block: '<Root>/SW2' */
void MW_ISR_3(void)
{
  /* Call the system: <S2>/Function-Call Subsystem1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_Project_2_test_DW.FunctionCallSubsystem1_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/SW2' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem1' */
    {
      real_T b_rem;
      real_T u;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2) {
       case 0:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 1;
        break;

       case 1:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 0;
        break;

       default:
        Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 =
          Final_Project_2_test_M->Timing.rtmDbBufLastBufWr2;
        break;
      }

      Final_Project_2_test_M->Timing.clockTick2 =
        Final_Project_2_test_M->Timing.rtmDbBufClockTick2
        [Final_Project_2_test_M->Timing.rtmDbBufReadBuf2];
      Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 0xFF;

      /* Sum: '<S7>/Sum' incorporates:
       *  Constant: '<S7>/Constant'
       *  UnitDelay: '<S7>/Unit Delay'
       */
      Final_Project_2_test_DW.UnitDelay_DSTATE +=
        Final_Project_2_test_P.Constant_Value_f;

      /* MATLAB Function: '<S7>/MATLAB Function' */
      u = Final_Project_2_test_DW.UnitDelay_DSTATE;
      if (Final_Project_2_test_DW.UnitDelay_DSTATE > 100.0) {
        u = 1.0;
      }

      if (rtIsNaN(u)) {
        b_rem = (rtNaN);
      } else if (rtIsInf(u)) {
        b_rem = (rtNaN);
      } else if (u == 0.0) {
        b_rem = 0.0;
      } else {
        b_rem = fmod(u, 2.0);
        if (b_rem == 0.0) {
          b_rem = 0.0;
        } else if (u < 0.0) {
          b_rem += 2.0;
        }
      }

      Final_Project_2_test_B.y = !(b_rem == 0.0);

      /* End of MATLAB Function: '<S7>/MATLAB Function' */
      Final_Project_2_test_DW.FunctionCallSubsystem1_SubsysRa = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/SW2' */
  }

  currentTime = (extmodeSimulationTime_T)
    Final_Project_2_test_M->Timing.clockTick0;
  extmodeEvent(2,currentTime);
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
void Final_Project_2_test_step(void)
{
  real_T rtb_UltrasonicSensor;
  uint32_T duration;
  uint16_T b_varargout_1;
  int8_T rtAction;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.ACCOFF_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.ifu101_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.elseifu105_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.else_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.ACCStandby_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.ACCON_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanBC);

  /* MATLABSystem: '<S1>/Analog Input1' */
  if (Final_Project_2_test_DW.obj.SampleTime !=
      Final_Project_2_test_P.AnalogInput1_SampleTime) {
    Final_Project_2_test_DW.obj.SampleTime =
      Final_Project_2_test_P.AnalogInput1_SampleTime;
  }

  Final_Project_2_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(58UL);
  MW_AnalogInSingle_ReadResult
    (Final_Project_2_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Gain: '<S1>/Gain'
   *  MATLABSystem: '<S1>/Analog Input1'
   * */
  Final_Project_2_test_B.DataTypeConversion = (uint8_T)(((uint32_T)
    Final_Project_2_test_P.Gain_Gain * b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor  ' */
  if (Final_Project_2_test_DW.obj_l.TunablePropsChanged) {
    Final_Project_2_test_DW.obj_l.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);
  rtb_UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  /* End of MATLABSystem: '<Root>/Ultrasonic Sensor  ' */
  /* RateTransition: '<S2>/Rate Transition1' */
  Final_Project_2_test_B.RateTransition1 = Final_Project_2_test_B.y_l;

  /* RateTransition: '<S2>/Rate Transition2' */
  Final_Project_2_test_B.RateTransition2 = Final_Project_2_test_B.y;

  /* If: '<S2>/If1' */
  if (Final_Project_2_test_B.RateTransition2 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/Out1'
     */
    Final_Project_2_test_B.Merge3 = Final_Project_2_test_P.Constant_Value_jt;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for If: '<S2>/If1' */
    srUpdateBC(Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  SignalConversion generated from: '<S9>/In1'
     */
    Final_Project_2_test_B.Merge3 = Final_Project_2_test_B.RateTransition1;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Update for If: '<S2>/If1' */
    srUpdateBC(Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem1' */
  }

  /* End of If: '<S2>/If1' */

  /* If: '<S2>/If' */
  rtAction = -1;
  if (Final_Project_2_test_B.Merge3 == 0.0) {
    rtAction = 0;
  } else if (Final_Project_2_test_B.Merge3 == 1.0) {
    rtAction = 1;
  } else if (Final_Project_2_test_B.Merge3 == 2.0) {
    rtAction = 2;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/ACC OFF' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_UltrasonicSensor = floor(Final_Project_2_test_P.Constant_Value_d);
    if (rtIsNaN(rtb_UltrasonicSensor) || rtIsInf(rtb_UltrasonicSensor)) {
      rtb_UltrasonicSensor = 0.0;
    } else {
      rtb_UltrasonicSensor = fmod(rtb_UltrasonicSensor, 256.0);
    }

    /* Merge: '<S2>/Merge' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     */
    Final_Project_2_test_B.Merge = (uint8_T)(rtb_UltrasonicSensor < 0.0 ?
      (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_UltrasonicSensor : (int16_T)
      (uint8_T)rtb_UltrasonicSensor);

    /* Merge: '<S2>/Merge4' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/RGB LED'
     */
    Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant1_Value;

    /* Merge: '<S2>/Merge1' incorporates:
     *  DiscretePulseGenerator: '<S3>/Pulse Generator'
     */
    Final_Project_2_test_B.Merge1 = (Final_Project_2_test_DW.clockTickCounter_g <
      Final_Project_2_test_P.PulseGenerator_Duty) &&
      (Final_Project_2_test_DW.clockTickCounter_g >= 0L) ?
      Final_Project_2_test_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
    if (Final_Project_2_test_DW.clockTickCounter_g >=
        Final_Project_2_test_P.PulseGenerator_Period - 1.0) {
      Final_Project_2_test_DW.clockTickCounter_g = 0L;
    } else {
      Final_Project_2_test_DW.clockTickCounter_g++;
    }

    srUpdateBC(Final_Project_2_test_DW.ACCOFF_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S2>/ACC OFF' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/ACC Standby   ' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* If: '<S5>/If' */
    if (rtb_UltrasonicSensor < 0.1) {
      rtAction = 0;
    } else if (rtb_UltrasonicSensor < 0.5) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S5>/if(u1<0.1)' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Merge: '<S2>/Merge2' incorporates:
       *  Constant: '<S15>/Constant'
       *  SignalConversion generated from: '<S15>/1'
       */
      Final_Project_2_test_B.Merge2 = Final_Project_2_test_P.Constant_Value_e;

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S15>/Constant1'
       *  SignalConversion generated from: '<S15>/PWM_stop1'
       */
      Final_Project_2_test_B.Merge = Final_Project_2_test_P.Constant1_Value_c;

      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S15>/Constant2'
       *  SignalConversion generated from: '<S15>/RGB_LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant2_Value;

      /* DiscretePulseGenerator: '<S15>/Pulse Generator1' */
      Final_Project_2_test_B.PulseGenerator1_a =
        (Final_Project_2_test_DW.clockTickCounter_k <
         Final_Project_2_test_P.PulseGenerator1_Duty) &&
        (Final_Project_2_test_DW.clockTickCounter_k >= 0L) ?
        Final_Project_2_test_P.PulseGenerator1_Amp : 0.0;

      /* DiscretePulseGenerator: '<S15>/Pulse Generator1' */
      if (Final_Project_2_test_DW.clockTickCounter_k >=
          Final_Project_2_test_P.PulseGenerator1_Period - 1.0) {
        Final_Project_2_test_DW.clockTickCounter_k = 0L;
      } else {
        Final_Project_2_test_DW.clockTickCounter_k++;
      }

      srUpdateBC(Final_Project_2_test_DW.ifu101_SubsysRanBC);

      /* End of Outputs for SubSystem: '<S5>/if(u1<0.1)' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S5>/elseif(u1 <0.5)' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Gain: '<S14>/Gain' */
      Final_Project_2_test_B.Gain = (uint8_T)((uint16_T)
        Final_Project_2_test_P.Gain_Gain_f *
        Final_Project_2_test_B.DataTypeConversion);

      /* Merge: '<S2>/Merge' incorporates:
       *  SignalConversion generated from: '<S14>/PWM_50'
       */
      Final_Project_2_test_B.Merge = Final_Project_2_test_B.Gain;

      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S14>/Constant'
       *  SignalConversion generated from: '<S14>/RGB_LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant_Value_n;

      /* Merge: '<S2>/Merge2' incorporates:
       *  DiscretePulseGenerator: '<S14>/Pulse Generator'
       */
      Final_Project_2_test_B.Merge2 =
        (Final_Project_2_test_DW.clockTickCounter_c <
         Final_Project_2_test_P.PulseGenerator_Duty_p) &&
        (Final_Project_2_test_DW.clockTickCounter_c >= 0L) ?
        Final_Project_2_test_P.PulseGenerator_Amp_j : 0.0;

      /* DiscretePulseGenerator: '<S14>/Pulse Generator' */
      if (Final_Project_2_test_DW.clockTickCounter_c >=
          Final_Project_2_test_P.PulseGenerator_Period_h - 1.0) {
        Final_Project_2_test_DW.clockTickCounter_c = 0L;
      } else {
        Final_Project_2_test_DW.clockTickCounter_c++;
      }

      srUpdateBC(Final_Project_2_test_DW.elseifu105_SubsysRanBC);

      /* End of Outputs for SubSystem: '<S5>/elseif(u1 <0.5)' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S5>/else' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Merge: '<S2>/Merge2' incorporates:
       *  Constant: '<S13>/Constant'
       *  SignalConversion generated from: '<S13>/LED_OFF'
       */
      Final_Project_2_test_B.Merge2 = Final_Project_2_test_P.Constant_Value_o;

      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S13>/Constant1'
       *  SignalConversion generated from: '<S13>/RGB_LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant1_Value_j;

      /* Merge: '<S2>/Merge' incorporates:
       *  SignalConversion generated from: '<S13>/PWM_in'
       */
      Final_Project_2_test_B.Merge = Final_Project_2_test_B.DataTypeConversion;
      srUpdateBC(Final_Project_2_test_DW.else_SubsysRanBC);

      /* End of Outputs for SubSystem: '<S5>/else' */
      break;
    }

    /* End of If: '<S5>/If' */

    /* Merge: '<S2>/Merge5' incorporates:
     *  SignalConversion generated from: '<S5>/Buser'
     */
    Final_Project_2_test_B.Merge5 = Final_Project_2_test_B.PulseGenerator1_a;

    /* Merge: '<S2>/Merge1' incorporates:
     *  DiscretePulseGenerator: '<S5>/Pulse Generator'
     */
    Final_Project_2_test_B.Merge1 = (Final_Project_2_test_DW.clockTickCounter_o <
      Final_Project_2_test_P.PulseGenerator_Duty_n) &&
      (Final_Project_2_test_DW.clockTickCounter_o >= 0L) ?
      Final_Project_2_test_P.PulseGenerator_Amp_n : 0.0;

    /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
    if (Final_Project_2_test_DW.clockTickCounter_o >=
        Final_Project_2_test_P.PulseGenerator_Period_p - 1.0) {
      Final_Project_2_test_DW.clockTickCounter_o = 0L;
    } else {
      Final_Project_2_test_DW.clockTickCounter_o++;
    }

    srUpdateBC(Final_Project_2_test_DW.ACCStandby_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S2>/ACC Standby   ' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/ACC ON' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/Red_LED'
     */
    Final_Project_2_test_B.Merge1 = Final_Project_2_test_P.Constant_Value_o4;

    /* If: '<S4>/If' */
    if (rtb_UltrasonicSensor < 0.1) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Merge: '<S2>/Merge2' incorporates:
       *  Constant: '<S11>/Constant1'
       *  SignalConversion generated from: '<S11>/1'
       */
      Final_Project_2_test_B.Merge2 = Final_Project_2_test_P.Constant1_Value_jc;

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S11>/Constant'
       *  SignalConversion generated from: '<S11>/PWM_stop1'
       */
      Final_Project_2_test_B.Merge = Final_Project_2_test_P.Constant_Value_jr;

      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S11>/Constant2'
       *  SignalConversion generated from: '<S11>/RGB_LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant2_Value_o;

      /* DiscretePulseGenerator: '<S11>/Pulse Generator1' */
      Final_Project_2_test_B.PulseGenerator1 =
        (Final_Project_2_test_DW.clockTickCounter_p <
         Final_Project_2_test_P.PulseGenerator1_Duty_m) &&
        (Final_Project_2_test_DW.clockTickCounter_p >= 0L) ?
        Final_Project_2_test_P.PulseGenerator1_Amp_d : 0.0;

      /* DiscretePulseGenerator: '<S11>/Pulse Generator1' */
      if (Final_Project_2_test_DW.clockTickCounter_p >=
          Final_Project_2_test_P.PulseGenerator1_Period_h - 1.0) {
        Final_Project_2_test_DW.clockTickCounter_p = 0L;
      } else {
        Final_Project_2_test_DW.clockTickCounter_p++;
      }

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Update for If: '<S4>/If' */
      srUpdateBC(Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanB_m);

      /* End of Update for SubSystem: '<S4>/If Action Subsystem1' */
    } else if (rtb_UltrasonicSensor < 0.5) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S10>/Constant'
       *  SignalConversion generated from: '<S10>/RGB_LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant_Value_a;

      /* Merge: '<S2>/Merge2' incorporates:
       *  DiscretePulseGenerator: '<S10>/Pulse Generator'
       */
      Final_Project_2_test_B.Merge2 = (Final_Project_2_test_DW.clockTickCounter <
        Final_Project_2_test_P.PulseGenerator_Duty_j) &&
        (Final_Project_2_test_DW.clockTickCounter >= 0L) ?
        Final_Project_2_test_P.PulseGenerator_Amp_ng : 0.0;

      /* DiscretePulseGenerator: '<S10>/Pulse Generator' */
      if (Final_Project_2_test_DW.clockTickCounter >=
          Final_Project_2_test_P.PulseGenerator_Period_f - 1.0) {
        Final_Project_2_test_DW.clockTickCounter = 0L;
      } else {
        Final_Project_2_test_DW.clockTickCounter++;
      }

      /* Merge: '<S2>/Merge' incorporates:
       *  Gain: '<S10>/Gain'
       */
      Final_Project_2_test_B.Merge = (uint8_T)(((uint16_T)
        Final_Project_2_test_P.Gain_Gain_k *
        Final_Project_2_test_B.DataTypeConversion) >> 8);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Update for If: '<S4>/If' */
      srUpdateBC(Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC_b);

      /* End of Update for SubSystem: '<S4>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Merge: '<S2>/Merge2' incorporates:
       *  Constant: '<S12>/Constant'
       *  SignalConversion generated from: '<S12>/LED_OFF'
       */
      Final_Project_2_test_B.Merge2 = Final_Project_2_test_P.Constant_Value_j;

      /* Merge: '<S2>/Merge4' incorporates:
       *  Constant: '<S12>/Constant1'
       *  SignalConversion generated from: '<S12>/RGB LED'
       */
      Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Constant1_Value_n;

      /* Merge: '<S2>/Merge' incorporates:
       *  SignalConversion generated from: '<S12>/Input'
       */
      Final_Project_2_test_B.Merge = Final_Project_2_test_B.DataTypeConversion;

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */

      /* Update for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Update for If: '<S4>/If' */
      srUpdateBC(Final_Project_2_test_DW.IfActionSubsystem2_SubsysRanBC);

      /* End of Update for SubSystem: '<S4>/If Action Subsystem2' */
    }

    /* End of If: '<S4>/If' */

    /* Merge: '<S2>/Merge5' incorporates:
     *  SignalConversion generated from: '<S4>/Buser'
     */
    Final_Project_2_test_B.Merge5 = Final_Project_2_test_B.PulseGenerator1;
    srUpdateBC(Final_Project_2_test_DW.ACCON_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S2>/ACC ON' */
    break;
  }

  /* End of If: '<S2>/If' */

  /* MATLABSystem: '<Root>/Blue LED' */
  rtb_UltrasonicSensor = rt_roundd_snf(Final_Project_2_test_B.Merge2);
  if (rtb_UltrasonicSensor < 256.0) {
    if (rtb_UltrasonicSensor >= 0.0) {
      tmp = (uint8_T)rtb_UltrasonicSensor;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp);

  /* End of MATLABSystem: '<Root>/Blue LED' */

  /* MATLABSystem: '<Root>/Buser' */
  rtb_UltrasonicSensor = rt_roundd_snf(Final_Project_2_test_B.Merge5);
  if (rtb_UltrasonicSensor < 256.0) {
    if (rtb_UltrasonicSensor >= 0.0) {
      tmp = (uint8_T)rtb_UltrasonicSensor;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp);

  /* End of MATLABSystem: '<Root>/Buser' */

  /* MATLABSystem: '<Root>/PWM  ' */
  Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (11UL);
  MW_PWM_SetDutyCycle(Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)Final_Project_2_test_B.Merge);

  /* MATLABSystem: '<Root>/RGB LED(Green)' */
  rtb_UltrasonicSensor = rt_roundd_snf(Final_Project_2_test_B.Merge4);
  if (rtb_UltrasonicSensor < 256.0) {
    if (rtb_UltrasonicSensor >= 0.0) {
      tmp = (uint8_T)rtb_UltrasonicSensor;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(33, tmp);

  /* End of MATLABSystem: '<Root>/RGB LED(Green)' */

  /* MATLABSystem: '<Root>/Red LED' */
  rtb_UltrasonicSensor = rt_roundd_snf(Final_Project_2_test_B.Merge1);
  if (rtb_UltrasonicSensor < 256.0) {
    if (rtb_UltrasonicSensor >= 0.0) {
      tmp = (uint8_T)rtb_UltrasonicSensor;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(12, tmp);

  /* End of MATLABSystem: '<Root>/Red LED' */
  /* MATLABSystem: '<S2>/Digital Output' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_UltrasonicSensor = rt_roundd_snf(Final_Project_2_test_P.Constant_Value_ni);
  if (rtb_UltrasonicSensor < 256.0) {
    if (rtb_UltrasonicSensor >= 0.0) {
      tmp = (uint8_T)rtb_UltrasonicSensor;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Final_Project_2_test_M->Timing.taskTime0 =
    ((time_T)(++Final_Project_2_test_M->Timing.clockTick0)) *
    Final_Project_2_test_M->Timing.stepSize0;
  switch (Final_Project_2_test_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1 =
      !Final_Project_2_test_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  Final_Project_2_test_M->Timing.rtmDbBufClockTick1
    [Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1] =
    Final_Project_2_test_M->Timing.clockTick0;
  Final_Project_2_test_M->Timing.rtmDbBufLastBufWr1 =
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1;
  Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  switch (Final_Project_2_test_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2 =
      !Final_Project_2_test_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  Final_Project_2_test_M->Timing.rtmDbBufClockTick2
    [Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2] =
    Final_Project_2_test_M->Timing.clockTick0;
  Final_Project_2_test_M->Timing.rtmDbBufLastBufWr2 =
    Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2;
  Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
}

/* Model initialize function */
void Final_Project_2_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Final_Project_2_test_M, -1);
  Final_Project_2_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Final_Project_2_test_M->Sizes.checksums[0] = (1811205337U);
  Final_Project_2_test_M->Sizes.checksums[1] = (2345804374U);
  Final_Project_2_test_M->Sizes.checksums[2] = (1376186310U);
  Final_Project_2_test_M->Sizes.checksums[3] = (2384555581U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[24];
    Final_Project_2_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&Final_Project_2_test_DW.ACCOFF_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC_b;
    systemRan[9] = (sysRanDType *)
      &Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanB_m;
    systemRan[10] = (sysRanDType *)
      &Final_Project_2_test_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&Final_Project_2_test_DW.ACCON_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&Final_Project_2_test_DW.else_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Final_Project_2_test_DW.elseifu105_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&Final_Project_2_test_DW.ifu101_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Final_Project_2_test_DW.ACCStandby_SubsysRanBC;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)
      &Final_Project_2_test_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[18] = (sysRanDType *)
      &Final_Project_2_test_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[19] = (sysRanDType *)
      &Final_Project_2_test_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[20] = (sysRanDType *)
      &Final_Project_2_test_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[21] = (sysRanDType *)
      &Final_Project_2_test_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &Final_Project_2_test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_Project_2_test_M->extModeInfo,
      &Final_Project_2_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_Project_2_test_M->extModeInfo,
                        Final_Project_2_test_M->Sizes.checksums);
    rteiSetTPtr(Final_Project_2_test_M->extModeInfo, rtmGetTPtr
                (Final_Project_2_test_M));
  }

  Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  Final_Project_2_test_M->Timing.rtmDbBufLastBufWr1 = 0;
  Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 0xFF;
  Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  Final_Project_2_test_M->Timing.rtmDbBufLastBufWr2 = 0;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/SW1 ' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem'
   */
  /* System initialize for function-call system: '<S2>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Final_Project_2_test_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 =
      Final_Project_2_test_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  Final_Project_2_test_M->Timing.clockTick1 =
    Final_Project_2_test_M->Timing.rtmDbBufClockTick1
    [Final_Project_2_test_M->Timing.rtmDbBufReadBuf1];
  Final_Project_2_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* InitializeConditions for Sum: '<S6>/Sum' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  Final_Project_2_test_DW.UnitDelay_DSTATE_d =
    Final_Project_2_test_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S6>/y' */
  Final_Project_2_test_B.y_l = Final_Project_2_test_P.y_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/SW2' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem1'
   */
  /* System initialize for function-call system: '<S2>/Function-Call Subsystem1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Final_Project_2_test_M->Timing.rtmDbBufWriteBuf2) {
   case 0:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 1;
    break;

   case 1:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 0;
    break;

   default:
    Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 =
      Final_Project_2_test_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  Final_Project_2_test_M->Timing.clockTick2 =
    Final_Project_2_test_M->Timing.rtmDbBufClockTick2
    [Final_Project_2_test_M->Timing.rtmDbBufReadBuf2];
  Final_Project_2_test_M->Timing.rtmDbBufReadBuf2 = 0xFF;

  /* InitializeConditions for Sum: '<S7>/Sum' incorporates:
   *  UnitDelay: '<S7>/Unit Delay'
   */
  Final_Project_2_test_DW.UnitDelay_DSTATE =
    Final_Project_2_test_P.UnitDelay_InitialCondition_a;

  /* SystemInitialize for Outport: '<S7>/SW2' */
  Final_Project_2_test_B.y = Final_Project_2_test_P.SW2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(3), &MW_ISR_3, RISING);

  /* SystemInitialize for IfAction SubSystem: '<S2>/ACC Standby   ' */
  /* SystemInitialize for IfAction SubSystem: '<S5>/if(u1<0.1)' */
  /* SystemInitialize for DiscretePulseGenerator: '<S15>/Pulse Generator1' incorporates:
   *  Outport: '<S15>/Buser'
   */
  Final_Project_2_test_B.PulseGenerator1_a = Final_Project_2_test_P.Buser_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/if(u1<0.1)' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/ACC ON' */
  /* SystemInitialize for IfAction SubSystem: '<S4>/If Action Subsystem1' */
  /* SystemInitialize for DiscretePulseGenerator: '<S11>/Pulse Generator1' incorporates:
   *  Outport: '<S11>/Buser'
   */
  Final_Project_2_test_B.PulseGenerator1 = Final_Project_2_test_P.Buser_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S4>/If Action Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S2>/ACC ON' */

  /* SystemInitialize for Merge: '<S2>/Merge2' */
  Final_Project_2_test_B.Merge2 = Final_Project_2_test_P.Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S2>/Merge5' */
  Final_Project_2_test_B.Merge5 = Final_Project_2_test_P.Merge5_InitialOutput;

  /* SystemInitialize for Merge: '<S2>/Merge' */
  Final_Project_2_test_B.Merge = Final_Project_2_test_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S2>/Merge4' */
  Final_Project_2_test_B.Merge4 = Final_Project_2_test_P.Merge4_InitialOutput;

  /* SystemInitialize for Merge: '<S2>/Merge1' */
  Final_Project_2_test_B.Merge1 = Final_Project_2_test_P.Merge1_InitialOutput;

  /* Start for MATLABSystem: '<S1>/Analog Input1' */
  Final_Project_2_test_DW.obj.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj.SampleTime =
    Final_Project_2_test_P.AnalogInput1_SampleTime;
  Final_Project_2_test_DW.obj.isInitialized = 1L;
  Final_Project_2_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(58UL);
  Final_Project_2_test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor  ' */
  Final_Project_2_test_DW.obj_l.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  Final_Project_2_test_DW.obj_l.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Blue LED' */
  Final_Project_2_test_DW.obj_o.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(9, 1);
  Final_Project_2_test_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Buser' */
  Final_Project_2_test_DW.obj_f.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(5, 1);
  Final_Project_2_test_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM  ' */
  Final_Project_2_test_DW.obj_d.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_d.isInitialized = 1L;
  Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  Final_Project_2_test_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/RGB LED(Green)' */
  Final_Project_2_test_DW.obj_c.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(33, 1);
  Final_Project_2_test_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Red LED' */
  Final_Project_2_test_DW.obj_e.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(12, 1);
  Final_Project_2_test_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  Final_Project_2_test_DW.obj_g.matlabCodegenIsDeleted = false;
  Final_Project_2_test_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Final_Project_2_test_DW.obj_g.isSetupComplete = true;
}

/* Model terminate function */
void Final_Project_2_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Analog Input1' */
  if (!Final_Project_2_test_DW.obj.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((Final_Project_2_test_DW.obj.isInitialized == 1L) &&
        Final_Project_2_test_DW.obj.isSetupComplete) {
      Final_Project_2_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(58UL);
      MW_AnalogIn_Close
        (Final_Project_2_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/Blue LED' */
  if (!Final_Project_2_test_DW.obj_o.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Blue LED' */

  /* Terminate for MATLABSystem: '<Root>/Buser' */
  if (!Final_Project_2_test_DW.obj_f.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Buser' */

  /* Terminate for MATLABSystem: '<Root>/PWM  ' */
  if (!Final_Project_2_test_DW.obj_d.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Final_Project_2_test_DW.obj_d.isInitialized == 1L) &&
        Final_Project_2_test_DW.obj_d.isSetupComplete) {
      Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Final_Project_2_test_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM  ' */

  /* Terminate for MATLABSystem: '<Root>/RGB LED(Green)' */
  if (!Final_Project_2_test_DW.obj_c.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/RGB LED(Green)' */

  /* Terminate for MATLABSystem: '<Root>/Red LED' */
  if (!Final_Project_2_test_DW.obj_e.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Red LED' */
  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!Final_Project_2_test_DW.obj_g.matlabCodegenIsDeleted) {
    Final_Project_2_test_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
