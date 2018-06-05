#include "__cf_mdlref_dynamics.h"
#include "mdlref_dynamics_capi.h"
#include "mdlref_dynamics.h"
#include "mdlref_dynamics_private.h"
int_T mo2nfnaknm [ 1 ] ; static RegMdlInfo rtMdlInfo_mdlref_dynamics [ 27 ] =
{ { "j2rfdjcge2s" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "j3rir22u0b" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "higpkwohhy" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "c1tu0klblc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "owdlnsejlu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "p0wdhtge1j" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "dqnhcm1bdh" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "om1xeppebk" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "jjr4a0ymal" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "dsmuh04l14" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "gl3vx5z1nb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "cm3zdlip3l" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "hs0pwhtftd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "dekcnbzlku" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "a4x4bou2tv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "jyicxpgorh" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "ar42usgqeo" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "mdlref_dynamics" } , { "ac2tgih0za" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "dfffqtihjj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "mdlref_dynamics" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , 0 , ( NULL ) } , { "ok5ns2jvcv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "mdlref_dynamics" } , { "ak145u3k0y" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "mo2nfnaknm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"mdlref_dynamics" } , { "pfb2ciiqrqf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "mdlref_dynamics" } , { "pfb2ciiqrq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "mdlref_dynamics" } ,
{ "mdlref_dynamics.h" , MDL_INFO_MODEL_FILENAME , 0 , 0 , ( NULL ) } , {
"mdlref_dynamics.c" , MDL_INFO_MODEL_FILENAME , 0 , 0 , ( void * )
"mdlref_dynamics" } } ; void ar42usgqeo ( p0wdhtge1j * localX ) { localX ->
n2yvg5srwp = 0.0 ; localX -> ones4i0zka = 0.0 ; } void mdlref_dynamics (
const real_T * kxvl2hwkcp , const real_T * hi4rzxlgxh , const real_T *
ngiuje0y2y , real_T * g12v1d0wbb , real_T * c3bfhbqnps , cm3zdlip3l * localB
, p0wdhtge1j * localX ) { * c3bfhbqnps = 0.0 ; * c3bfhbqnps += localX ->
n2yvg5srwp ; localB -> jydq1su5vi = 689.4 * * c3bfhbqnps ; * g12v1d0wbb = 0.0
; * g12v1d0wbb += localX -> ones4i0zka ; localB -> mcuxuljs4k = - 0.00592 * *
g12v1d0wbb ; localB -> lskidoihis = - 63.9979 * * kxvl2hwkcp ; localB ->
f1b2aagdh3 = - 6.8847 * * kxvl2hwkcp ; localB -> nvicugvuv1 = ( localB ->
lskidoihis - * hi4rzxlgxh ) + localB -> jydq1su5vi ; localB -> cxz0zm2svh = (
localB -> mcuxuljs4k - * ngiuje0y2y ) + localB -> f1b2aagdh3 ; } void
jyicxpgorh ( void ) { } void a4x4bou2tv ( cm3zdlip3l * localB , p0wdhtge1j *
localX , owdlnsejlu * localXdot ) { localXdot -> n2yvg5srwp = 0.0 ; localXdot
-> n2yvg5srwp += - 0.6571 * localX -> n2yvg5srwp ; localXdot -> n2yvg5srwp +=
localB -> cxz0zm2svh ; localXdot -> ones4i0zka = 0.0 ; localXdot ->
ones4i0zka += - 0.6385 * localX -> ones4i0zka ; localXdot -> ones4i0zka +=
localB -> nvicugvuv1 ; } void ac2tgih0za ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , ak145u3k0y * const iuhkr151ru , cm3zdlip3l * localB ,
p0wdhtge1j * localX , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof ( real_T )
) ; ( void ) memset ( ( void * ) iuhkr151ru , 0 , sizeof ( ak145u3k0y ) ) ;
mo2nfnaknm [ 0 ] = mdlref_TID0 ; iuhkr151ru -> _mdlRefSfcnS = ( _mdlRefSfcnS
) ; { localB -> jydq1su5vi = 0.0 ; localB -> mcuxuljs4k = 0.0 ; localB ->
lskidoihis = 0.0 ; localB -> f1b2aagdh3 = 0.0 ; localB -> nvicugvuv1 = 0.0 ;
localB -> cxz0zm2svh = 0.0 ; } mdlref_dynamics_InitializeDataMapInfo (
iuhkr151ru , localX , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != (
NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( *
rt_ParentMMI , rt_ChildMMIIdx , & ( iuhkr151ru -> DataMapInfo . mmi ) ) ;
rtwCAPI_SetPath ( iuhkr151ru -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( iuhkr151ru -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_mdlref_dynamics_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; * retVal
= 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_mdlref_dynamics , 27 ) ; * retVal = 1 ; }
