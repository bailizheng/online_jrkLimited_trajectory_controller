/*
 * six_dof_pos_controller_capi.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "six_dof_pos_controller".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Mon Apr  1 15:31:34 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "six_dof_pos_controller_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "six_dof_pos_controller.h"
#include "six_dof_pos_controller_capi.h"
#include "six_dof_pos_controller_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 0, TARGET_STRING("six_dof_pos_controller/joint 2/Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1, TARGET_STRING("six_dof_pos_controller/joint 2/Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 2, TARGET_STRING("six_dof_pos_controller/joint 2/Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 3, TARGET_STRING("six_dof_pos_controller/joint 2/Delay4"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 4, TARGET_STRING("six_dof_pos_controller/joint 2/Delay4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 5, TARGET_STRING("six_dof_pos_controller/joint 2/Delay5"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 6, TARGET_STRING("six_dof_pos_controller/joint 2/Delay5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 7, TARGET_STRING("six_dof_pos_controller/joint 2/Delay6"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 8, TARGET_STRING("six_dof_pos_controller/joint 2/Delay6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 9, TARGET_STRING("six_dof_pos_controller/joint_0/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 10, TARGET_STRING("six_dof_pos_controller/joint_0/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 11, TARGET_STRING("six_dof_pos_controller/joint_0/Integrator4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 12, TARGET_STRING("six_dof_pos_controller/joint_0/Delay1"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 13, TARGET_STRING("six_dof_pos_controller/joint_0/Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 14, TARGET_STRING("six_dof_pos_controller/joint_0/Delay2"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 15, TARGET_STRING("six_dof_pos_controller/joint_0/Delay2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 16, TARGET_STRING("six_dof_pos_controller/joint_0/Delay3"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 17, TARGET_STRING("six_dof_pos_controller/joint_0/Delay3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 18, TARGET_STRING("six_dof_pos_controller/joint_1 /Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 19, TARGET_STRING("six_dof_pos_controller/joint_1 /Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 20, TARGET_STRING("six_dof_pos_controller/joint_1 /Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 21, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay4"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 22, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 23, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay5"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 24, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 25, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay6"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 26, TARGET_STRING("six_dof_pos_controller/joint_1 /Delay6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 27, TARGET_STRING("six_dof_pos_controller/joint_3/Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 28, TARGET_STRING("six_dof_pos_controller/joint_3/Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 29, TARGET_STRING("six_dof_pos_controller/joint_3/Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 30, TARGET_STRING("six_dof_pos_controller/joint_3/Delay4"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 31, TARGET_STRING("six_dof_pos_controller/joint_3/Delay4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 32, TARGET_STRING("six_dof_pos_controller/joint_3/Delay5"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 33, TARGET_STRING("six_dof_pos_controller/joint_3/Delay5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 34, TARGET_STRING("six_dof_pos_controller/joint_3/Delay6"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 35, TARGET_STRING("six_dof_pos_controller/joint_3/Delay6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 36, TARGET_STRING("six_dof_pos_controller/joint_4  /Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 37, TARGET_STRING("six_dof_pos_controller/joint_4  /Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 38, TARGET_STRING("six_dof_pos_controller/joint_4  /Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 39, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay4"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 40, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 41, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay5"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 42, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 43, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay6"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 44, TARGET_STRING("six_dof_pos_controller/joint_4  /Delay6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 45, TARGET_STRING("six_dof_pos_controller/joint_5/Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 46, TARGET_STRING("six_dof_pos_controller/joint_5/Integrator3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 47, TARGET_STRING("six_dof_pos_controller/joint_5/Integrator5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 48, TARGET_STRING("six_dof_pos_controller/joint_5/Delay4"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 49, TARGET_STRING("six_dof_pos_controller/joint_5/Delay4"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 50, TARGET_STRING("six_dof_pos_controller/joint_5/Delay5"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 51, TARGET_STRING("six_dof_pos_controller/joint_5/Delay5"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 52, TARGET_STRING("six_dof_pos_controller/joint_5/Delay6"),
    TARGET_STRING("DelayLength"), 1, 0, 0 },

  { 53, TARGET_STRING("six_dof_pos_controller/joint_5/Delay6"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Root Inputs information */
static const rtwCAPI_Signals rtRootInputs[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 54, 0, TARGET_STRING("six_dof_pos_controller/pos"),
    TARGET_STRING(""), 1, 0, 1, 0, 0 },

  { 55, 0, TARGET_STRING("six_dof_pos_controller/vel"),
    TARGET_STRING(""), 2, 0, 1, 0, 0 },

  { 56, 0, TARGET_STRING("six_dof_pos_controller/acc"),
    TARGET_STRING(""), 3, 0, 1, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Root Outputs information */
static const rtwCAPI_Signals rtRootOutputs[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 57, 0, TARGET_STRING("six_dof_pos_controller/POS"),
    TARGET_STRING(""), 1, 0, 1, 0, 1 },

  { 58, 0, TARGET_STRING("six_dof_pos_controller/VEL"),
    TARGET_STRING(""), 2, 0, 1, 0, 1 },

  { 59, 0, TARGET_STRING("six_dof_pos_controller/ACC"),
    TARGET_STRING(""), 3, 0, 1, 0, 1 },

  { 60, 0, TARGET_STRING("six_dof_pos_controller/JRK"),
    TARGET_STRING(""), 4, 0, 1, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 61, TARGET_STRING("am"), 0, 2, 0 },

  { 62, TARGET_STRING("jm"), 0, 2, 0 },

  { 63, TARGET_STRING("ka"), 0, 2, 0 },

  { 64, TARGET_STRING("kp"), 0, 2, 0 },

  { 65, TARGET_STRING("kv"), 0, 2, 0 },

  { 66, TARGET_STRING("sm"), 0, 2, 0 },

  { 67, TARGET_STRING("vm"), 0, 2, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &six_dof_pos_controller_P.Integrator2_IC_k,/* 0: Block Parameter */
  &six_dof_pos_controller_P.Integrator3_IC_i,/* 1: Block Parameter */
  &six_dof_pos_controller_P.Integrator5_IC_i,/* 2: Block Parameter */
  &six_dof_pos_controller_P.Delay4_DelayLength_l,/* 3: Block Parameter */
  &six_dof_pos_controller_P.Delay4_InitialCondition_j,/* 4: Block Parameter */
  &six_dof_pos_controller_P.Delay5_DelayLength_a,/* 5: Block Parameter */
  &six_dof_pos_controller_P.Delay5_InitialCondition_g,/* 6: Block Parameter */
  &six_dof_pos_controller_P.Delay6_DelayLength_c,/* 7: Block Parameter */
  &six_dof_pos_controller_P.Delay6_InitialCondition_p,/* 8: Block Parameter */
  &six_dof_pos_controller_P.Integrator_IC,/* 9: Block Parameter */
  &six_dof_pos_controller_P.Integrator1_IC,/* 10: Block Parameter */
  &six_dof_pos_controller_P.Integrator4_IC,/* 11: Block Parameter */
  &six_dof_pos_controller_P.Delay1_DelayLength,/* 12: Block Parameter */
  &six_dof_pos_controller_P.Delay1_InitialCondition,/* 13: Block Parameter */
  &six_dof_pos_controller_P.Delay2_DelayLength,/* 14: Block Parameter */
  &six_dof_pos_controller_P.Delay2_InitialCondition,/* 15: Block Parameter */
  &six_dof_pos_controller_P.Delay3_DelayLength,/* 16: Block Parameter */
  &six_dof_pos_controller_P.Delay3_InitialCondition,/* 17: Block Parameter */
  &six_dof_pos_controller_P.Integrator2_IC,/* 18: Block Parameter */
  &six_dof_pos_controller_P.Integrator3_IC,/* 19: Block Parameter */
  &six_dof_pos_controller_P.Integrator5_IC,/* 20: Block Parameter */
  &six_dof_pos_controller_P.Delay4_DelayLength,/* 21: Block Parameter */
  &six_dof_pos_controller_P.Delay4_InitialCondition,/* 22: Block Parameter */
  &six_dof_pos_controller_P.Delay5_DelayLength,/* 23: Block Parameter */
  &six_dof_pos_controller_P.Delay5_InitialCondition,/* 24: Block Parameter */
  &six_dof_pos_controller_P.Delay6_DelayLength,/* 25: Block Parameter */
  &six_dof_pos_controller_P.Delay6_InitialCondition,/* 26: Block Parameter */
  &six_dof_pos_controller_P.Integrator2_IC_g,/* 27: Block Parameter */
  &six_dof_pos_controller_P.Integrator3_IC_ix,/* 28: Block Parameter */
  &six_dof_pos_controller_P.Integrator5_IC_a,/* 29: Block Parameter */
  &six_dof_pos_controller_P.Delay4_DelayLength_d,/* 30: Block Parameter */
  &six_dof_pos_controller_P.Delay4_InitialCondition_d,/* 31: Block Parameter */
  &six_dof_pos_controller_P.Delay5_DelayLength_f,/* 32: Block Parameter */
  &six_dof_pos_controller_P.Delay5_InitialCondition_n,/* 33: Block Parameter */
  &six_dof_pos_controller_P.Delay6_DelayLength_n,/* 34: Block Parameter */
  &six_dof_pos_controller_P.Delay6_InitialCondition_k,/* 35: Block Parameter */
  &six_dof_pos_controller_P.Integrator2_IC_n,/* 36: Block Parameter */
  &six_dof_pos_controller_P.Integrator3_IC_j,/* 37: Block Parameter */
  &six_dof_pos_controller_P.Integrator5_IC_p,/* 38: Block Parameter */
  &six_dof_pos_controller_P.Delay4_DelayLength_da,/* 39: Block Parameter */
  &six_dof_pos_controller_P.Delay4_InitialCondition_n,/* 40: Block Parameter */
  &six_dof_pos_controller_P.Delay5_DelayLength_i,/* 41: Block Parameter */
  &six_dof_pos_controller_P.Delay5_InitialCondition_i,/* 42: Block Parameter */
  &six_dof_pos_controller_P.Delay6_DelayLength_p,/* 43: Block Parameter */
  &six_dof_pos_controller_P.Delay6_InitialCondition_o,/* 44: Block Parameter */
  &six_dof_pos_controller_P.Integrator2_IC_h,/* 45: Block Parameter */
  &six_dof_pos_controller_P.Integrator3_IC_a,/* 46: Block Parameter */
  &six_dof_pos_controller_P.Integrator5_IC_k,/* 47: Block Parameter */
  &six_dof_pos_controller_P.Delay4_DelayLength_c,/* 48: Block Parameter */
  &six_dof_pos_controller_P.Delay4_InitialCondition_k,/* 49: Block Parameter */
  &six_dof_pos_controller_P.Delay5_DelayLength_m,/* 50: Block Parameter */
  &six_dof_pos_controller_P.Delay5_InitialCondition_o,/* 51: Block Parameter */
  &six_dof_pos_controller_P.Delay6_DelayLength_j,/* 52: Block Parameter */
  &six_dof_pos_controller_P.Delay6_InitialCondition_ok,/* 53: Block Parameter */
  &six_dof_pos_controller_U.pos[0],    /* 54: Root Input */
  &six_dof_pos_controller_U.vel[0],    /* 55: Root Input */
  &six_dof_pos_controller_U.acc[0],    /* 56: Root Input */
  &six_dof_pos_controller_Y.POS[0],    /* 57: Root Output */
  &six_dof_pos_controller_Y.VEL[0],    /* 58: Root Output */
  &six_dof_pos_controller_Y.ACC[0],    /* 59: Root Output */
  &six_dof_pos_controller_Y.JRK[0],    /* 60: Root Output */
  &six_dof_pos_controller_P.am[0],     /* 61: Model Parameter */
  &six_dof_pos_controller_P.jm[0],     /* 62: Model Parameter */
  &six_dof_pos_controller_P.ka[0],     /* 63: Model Parameter */
  &six_dof_pos_controller_P.kp[0],     /* 64: Model Parameter */
  &six_dof_pos_controller_P.kv[0],     /* 65: Model Parameter */
  &six_dof_pos_controller_P.sm[0],     /* 66: Model Parameter */
  &six_dof_pos_controller_P.vm[0],     /* 67: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  6,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  6                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.008, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { (NULL), 0,
    rtRootInputs, 3,
    rtRootOutputs, 4 },

  { rtBlockParameters, 54,
    rtModelParameters, 7 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3927242544U,
    1178204785U,
    1072010098U,
    3112347696U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  six_dof_pos_controller_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void six_dof_pos_controller_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(six_dof_pos_controller_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(six_dof_pos_controller_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(six_dof_pos_controller_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(six_dof_pos_controller_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(six_dof_pos_controller_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(six_dof_pos_controller_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(six_dof_pos_controller_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(six_dof_pos_controller_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void six_dof_pos_controller_host_InitializeDataMapInfo
    (six_dof_pos_controller_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: six_dof_pos_controller_capi.cpp */
