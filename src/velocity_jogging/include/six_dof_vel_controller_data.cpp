/*
 * six_dof_vel_controller_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "six_dof_vel_controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Fri May 17 15:21:32 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "six_dof_vel_controller.h"
#include "six_dof_vel_controller_private.h"

/* Block parameters (default storage) */
P_six_dof_vel_controller_T six_dof_vel_controller_P = {
  /* Variable: am
   * Referenced by:
   *   '<S1>/Saturation4'
   *   '<S2>/Saturation'
   *   '<S3>/Saturation4'
   *   '<S4>/Saturation4'
   *   '<S5>/Saturation4'
   *   '<S6>/Saturation4'
   */
  { 253.2467, 253.2467, 253.2467, 253.2467, 253.2467, 253.2467 },

  /* Variable: jm
   * Referenced by:
   *   '<S1>/Saturation7'
   *   '<S1>/Saturation9'
   *   '<S2>/Saturation3'
   *   '<S2>/Saturation8'
   *   '<S3>/Saturation7'
   *   '<S3>/Saturation9'
   *   '<S4>/Saturation7'
   *   '<S4>/Saturation9'
   *   '<S5>/Saturation7'
   *   '<S5>/Saturation9'
   *   '<S6>/Saturation7'
   *   '<S6>/Saturation9'
   */
  { 986.6757, 986.6757, 986.6757, 986.6757, 986.6757, 986.6757 },

  /* Variable: ka
   * Referenced by:
   *   '<S1>/Gain4'
   *   '<S2>/Gain1'
   *   '<S3>/Gain4'
   *   '<S4>/Gain4'
   *   '<S5>/Gain4'
   *   '<S6>/Gain4'
   */
  { 60.0, 60.0, 60.0, 60.0, 60.0, 60.0 },

  /* Variable: kv
   * Referenced by:
   *   '<S1>/Gain5'
   *   '<S2>/Gain2'
   *   '<S3>/Gain5'
   *   '<S4>/Gain5'
   *   '<S5>/Gain5'
   *   '<S6>/Gain5'
   */
  { 600.0, 600.0, 600.0, 600.0, 600.0, 600.0 },

  /* Variable: sm
   * Referenced by:
   *   '<S1>/Saturation6'
   *   '<S2>/Saturation2'
   *   '<S3>/Saturation6'
   *   '<S4>/Saturation6'
   *   '<S5>/Saturation6'
   *   '<S6>/Saturation6'
   */
  { 185.0, 185.0, 185.0, 185.0, 185.0, 185.0 },

  /* Variable: vm
   * Referenced by:
   *   '<S1>/Saturation5'
   *   '<S2>/Saturation1'
   *   '<S3>/Saturation5'
   *   '<S4>/Saturation5'
   *   '<S5>/Saturation5'
   *   '<S6>/Saturation5'
   */
  { 130.0, 130.0, 130.0, 130.0, 130.0, 130.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Delay4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Delay4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Delay4'
   */
  0.0,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<S2>/Delay2'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<S2>/Delay1'
   */
  1U,

  /* Computed Parameter: Delay5_DelayLength
   * Referenced by: '<S3>/Delay5'
   */
  1U,

  /* Computed Parameter: Delay4_DelayLength
   * Referenced by: '<S3>/Delay4'
   */
  1U,

  /* Computed Parameter: Delay5_DelayLength_a
   * Referenced by: '<S1>/Delay5'
   */
  1U,

  /* Computed Parameter: Delay4_DelayLength_l
   * Referenced by: '<S1>/Delay4'
   */
  1U,

  /* Computed Parameter: Delay5_DelayLength_f
   * Referenced by: '<S4>/Delay5'
   */
  1U,

  /* Computed Parameter: Delay4_DelayLength_d
   * Referenced by: '<S4>/Delay4'
   */
  1U,

  /* Computed Parameter: Delay5_DelayLength_i
   * Referenced by: '<S5>/Delay5'
   */
  1U,

  /* Computed Parameter: Delay4_DelayLength_da
   * Referenced by: '<S5>/Delay4'
   */
  1U,

  /* Computed Parameter: Delay5_DelayLength_m
   * Referenced by: '<S6>/Delay5'
   */
  1U,

  /* Computed Parameter: Delay4_DelayLength_c
   * Referenced by: '<S6>/Delay4'
   */
  1U
};
