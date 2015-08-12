/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: megatest.c
 *
 * Code generated for Simulink model 'megatest'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Aug 12 19:57:24 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "megatest.h"
#include "megatest_private.h"

/* Real-time model */
RT_MODEL_megatest_T megatest_M_;
RT_MODEL_megatest_T *const megatest_M = &megatest_M_;

/* Model output function */
void megatest_output(void)
{
  uint8_T tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (megatest_P.Constant_Value < 256.0) {
    if (megatest_P.Constant_Value >= 0.0) {
      tmp = (uint8_T)megatest_P.Constant_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S1>/Servo Write' */
  MW_servoWrite(megatest_P.ServoWrite_p1, tmp);
}

/* Model update function */
void megatest_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void megatest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(megatest_M, (NULL));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S1>/Servo Write' */
  MW_servoAttach(megatest_P.ServoWrite_p1, megatest_P.ServoWrite_pinNumber);
}

/* Model terminate function */
void megatest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
