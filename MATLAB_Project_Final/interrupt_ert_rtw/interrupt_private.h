/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: interrupt_private.h
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

#ifndef RTW_HEADER_interrupt_private_h_
#define RTW_HEADER_interrupt_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "interrupt_types.h"
#include "interrupt.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void MW_ISR_2(void);

#endif                                 /* RTW_HEADER_interrupt_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
