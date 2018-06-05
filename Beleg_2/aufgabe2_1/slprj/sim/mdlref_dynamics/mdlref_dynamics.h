#include "__cf_mdlref_dynamics.h"
#ifndef RTW_HEADER_mdlref_dynamics_h_
#define RTW_HEADER_mdlref_dynamics_h_
#include "rtw_modelmap.h"
#ifndef mdlref_dynamics_COMMON_INCLUDES_
#define mdlref_dynamics_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#endif
#include "mdlref_dynamics_types.h"
typedef struct { real_T jydq1su5vi ; real_T mcuxuljs4k ; real_T lskidoihis ;
real_T f1b2aagdh3 ; real_T nvicugvuv1 ; real_T cxz0zm2svh ; } cm3zdlip3l ;
typedef struct { real_T n2yvg5srwp ; real_T ones4i0zka ; } p0wdhtge1j ;
typedef struct { real_T n2yvg5srwp ; real_T ones4i0zka ; } owdlnsejlu ;
typedef struct { boolean_T n2yvg5srwp ; boolean_T ones4i0zka ; } c1tu0klblc ;
typedef struct { real_T n2yvg5srwp ; real_T ones4i0zka ; } higpkwohhy ;
struct ok5ns2jvcv { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 2 ] ; int32_T * vardimsAddress [ 2
] ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; }
; typedef struct { cm3zdlip3l rtb ; ak145u3k0y rtm ; } j2rfdjcge2s ; extern
void ac2tgih0za ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , ak145u3k0y *
const iuhkr151ru , cm3zdlip3l * localB , p0wdhtge1j * localX , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern
void mr_mdlref_dynamics_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern const rtwCAPI_ModelMappingStaticInfo *
mdlref_dynamics_GetCAPIStaticMap ( void ) ; extern void ar42usgqeo (
p0wdhtge1j * localX ) ; extern void a4x4bou2tv ( cm3zdlip3l * localB ,
p0wdhtge1j * localX , owdlnsejlu * localXdot ) ; extern void jyicxpgorh (
void ) ; extern void mdlref_dynamics ( const real_T * kxvl2hwkcp , const
real_T * hi4rzxlgxh , const real_T * ngiuje0y2y , real_T * g12v1d0wbb ,
real_T * c3bfhbqnps , cm3zdlip3l * localB , p0wdhtge1j * localX ) ;
#endif
