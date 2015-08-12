/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: megatest.h
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

#ifndef RTW_HEADER_megatest_h_
#define RTW_HEADER_megatest_h_
#include <stddef.h>
#ifndef megatest_COMMON_INCLUDES_
# define megatest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* megatest_COMMON_INCLUDES_ */

#include "megatest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_megatest_T_ {
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S1>/Servo Write'
                                        */
  real_T Constant_Value;               /* Expression: 90
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S1>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_megatest_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_megatest_T megatest_P;

/* Model entry point functions */
extern void megatest_initialize(void);
extern void megatest_output(void);
extern void megatest_update(void);
extern void megatest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_megatest_T *const megatest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'megatest'
 * '<S1>'   : 'megatest/Standard Servo Write'
 */
#endif                                 /* RTW_HEADER_megatest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
