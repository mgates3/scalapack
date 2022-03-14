cdir := BLACS/SRC

#  --------------------------
#  The communication routines
#  --------------------------
comm = \
    $(cdir)/igesd2d_.o \
    $(cdir)/sgesd2d_.o \
    $(cdir)/dgesd2d_.o \
    $(cdir)/cgesd2d_.o \
    $(cdir)/zgesd2d_.o \
    \
    $(cdir)/itrsd2d_.o \
    $(cdir)/strsd2d_.o \
    $(cdir)/dtrsd2d_.o \
    $(cdir)/ctrsd2d_.o \
    $(cdir)/ztrsd2d_.o \
    \
    $(cdir)/igerv2d_.o \
    $(cdir)/sgerv2d_.o \
    $(cdir)/dgerv2d_.o \
    $(cdir)/cgerv2d_.o \
    $(cdir)/zgerv2d_.o \
    \
    $(cdir)/itrrv2d_.o \
    $(cdir)/strrv2d_.o \
    $(cdir)/dtrrv2d_.o \
    $(cdir)/ctrrv2d_.o \
    $(cdir)/ztrrv2d_.o \
    \
    $(cdir)/igebs2d_.o \
    $(cdir)/sgebs2d_.o \
    $(cdir)/dgebs2d_.o \
    $(cdir)/cgebs2d_.o \
    $(cdir)/zgebs2d_.o \
    \
    $(cdir)/igebr2d_.o \
    $(cdir)/sgebr2d_.o \
    $(cdir)/dgebr2d_.o \
    $(cdir)/cgebr2d_.o \
    $(cdir)/zgebr2d_.o \
    \
    $(cdir)/itrbs2d_.o \
    $(cdir)/strbs2d_.o \
    $(cdir)/dtrbs2d_.o \
    $(cdir)/ctrbs2d_.o \
    $(cdir)/ztrbs2d_.o \
    \
    $(cdir)/itrbr2d_.o \
    $(cdir)/strbr2d_.o \
    $(cdir)/dtrbr2d_.o \
    $(cdir)/ctrbr2d_.o \
    $(cdir)/ztrbr2d_.o \
    \
    $(cdir)/igsum2d_.o \
    $(cdir)/sgsum2d_.o \
    $(cdir)/dgsum2d_.o \
    $(cdir)/cgsum2d_.o \
    $(cdir)/zgsum2d_.o \
    \
    $(cdir)/igamx2d_.o \
    $(cdir)/sgamx2d_.o \
    $(cdir)/dgamx2d_.o \
    $(cdir)/cgamx2d_.o \
    $(cdir)/zgamx2d_.o \
    \
    $(cdir)/igamn2d_.o \
    $(cdir)/sgamn2d_.o \
    $(cdir)/dgamn2d_.o \
    $(cdir)/cgamn2d_.o \
    $(cdir)/zgamn2d_.o

#  --------------------
#  The support routines
#  --------------------
supp = \
    $(cdir)/blacs_setup_.o \
    $(cdir)/blacs_set_.o \
    $(cdir)/blacs_get_.o \
    $(cdir)/blacs_abort_.o \
    $(cdir)/blacs_exit_.o \
    $(cdir)/blacs_pnum_.o \
    $(cdir)/blacs_pcoord_.o \
    $(cdir)/ksendid_.o \
    $(cdir)/krecvid_.o \
    $(cdir)/kbsid_.o \
    $(cdir)/kbrid_.o \
    $(cdir)/dcputime00_.o \
    $(cdir)/dwalltime00_.o \
    $(cdir)/blacs_pinfo_.o \
    $(cdir)/blacs_init_.o \
    $(cdir)/blacs_map_.o \
    $(cdir)/blacs_free_.o \
    $(cdir)/blacs_grid_.o \
    $(cdir)/blacs_info_.o \
    $(cdir)/blacs_barr_.o \
    $(cdir)/sys2blacs_.o \
    $(cdir)/blacs2sys_.o \
    $(cdir)/free_handle_.o


#  ----------------------------
#  The fortran and C interfaces
#  ----------------------------
Fintobj   = $(comm) $(supp)
Cintobj   = $(comm:.o=_c.o) $(supp:.o=_c.o)

#  ---------------------
#  The internal routines
#  ---------------------
internal = \
    $(cdir)/BI_HypBS.o \
    $(cdir)/BI_HypBR.o \
    $(cdir)/BI_IdringBS.o \
    $(cdir)/BI_IdringBR.o \
    $(cdir)/BI_MpathBS.o \
    $(cdir)/BI_MpathBR.o \
    $(cdir)/BI_SringBS.o \
    $(cdir)/BI_SringBR.o \
    $(cdir)/BI_TreeBS.o \
    $(cdir)/BI_TreeBR.o \
    $(cdir)/BI_Ssend.o \
    $(cdir)/BI_Rsend.o \
    $(cdir)/BI_Srecv.o \
    $(cdir)/BI_Asend.o \
    $(cdir)/BI_Arecv.o \
    $(cdir)/BI_TreeComb.o \
    $(cdir)/BI_BeComb.o \
    $(cdir)/BI_MringComb.o \
    $(cdir)/BI_ArgCheck.o \
    $(cdir)/BI_TransDist.o \
    $(cdir)/BI_GetBuff.o \
    $(cdir)/BI_UpdateBuffs.o \
    $(cdir)/BI_EmergencyBuff.o \
    $(cdir)/BI_BlacsErr.o \
    $(cdir)/BI_BlacsWarn.o \
    $(cdir)/BI_BlacsAbort.o \
    $(cdir)/BI_BuffIsFree.o \
    $(cdir)/BI_imvcopy.o \
    $(cdir)/BI_smvcopy.o \
    $(cdir)/BI_dmvcopy.o \
    $(cdir)/BI_ivmcopy.o \
    $(cdir)/BI_svmcopy.o \
    $(cdir)/BI_dvmcopy.o \
    $(cdir)/BI_Pack.o \
    $(cdir)/BI_Unpack.o \
    $(cdir)/BI_GetMpiGeType.o \
    $(cdir)/BI_GetMpiTrType.o \
    $(cdir)/BI_ivvsum.o \
    $(cdir)/BI_svvsum.o \
    $(cdir)/BI_dvvsum.o \
    $(cdir)/BI_cvvsum.o \
    $(cdir)/BI_zvvsum.o \
    $(cdir)/BI_ivvamx.o \
    $(cdir)/BI_svvamx.o \
    $(cdir)/BI_dvvamx.o \
    $(cdir)/BI_cvvamx.o \
    $(cdir)/BI_zvvamx.o \
    $(cdir)/BI_ivvamx2.o \
    $(cdir)/BI_svvamx2.o \
    $(cdir)/BI_dvvamx2.o \
    $(cdir)/BI_cvvamx2.o \
    $(cdir)/BI_zvvamx2.o \
    $(cdir)/BI_ivvamn.o \
    $(cdir)/BI_svvamn.o \
    $(cdir)/BI_dvvamn.o \
    $(cdir)/BI_cvvamn.o \
    $(cdir)/BI_zvvamn.o \
    $(cdir)/BI_ivvamn2.o \
    $(cdir)/BI_svvamn2.o \
    $(cdir)/BI_dvvamn2.o \
    $(cdir)/BI_cvvamn2.o \
    $(cdir)/BI_zvvamn2.o \
    $(cdir)/BI_iMPI_amx.o \
    $(cdir)/BI_sMPI_amx.o \
    $(cdir)/BI_dMPI_amx.o \
    $(cdir)/BI_cMPI_amx.o \
    $(cdir)/BI_zMPI_amx.o \
    $(cdir)/BI_iMPI_amx2.o \
    $(cdir)/BI_sMPI_amx2.o \
    $(cdir)/BI_dMPI_amx2.o \
    $(cdir)/BI_cMPI_amx2.o \
    $(cdir)/BI_zMPI_amx2.o \
    $(cdir)/BI_iMPI_amn.o \
    $(cdir)/BI_sMPI_amn.o \
    $(cdir)/BI_dMPI_amn.o \
    $(cdir)/BI_cMPI_amn.o \
    $(cdir)/BI_zMPI_amn.o \
    $(cdir)/BI_iMPI_amn2.o \
    $(cdir)/BI_sMPI_amn2.o \
    $(cdir)/BI_dMPI_amn2.o \
    $(cdir)/BI_cMPI_amn2.o \
    $(cdir)/BI_zMPI_amn2.o \
    $(cdir)/BI_cMPI_sum.o \
    $(cdir)/BI_zMPI_sum.o \
    $(cdir)/BI_ContxtNum.o \
    $(cdir)/BI_GlobalVars.o \
    $(cdir)/BI_TransUserComm.o

$(internal): $(cdir)/Bdef.h $(cdir)/Bconfig.h
$(Fintobj):  $(cdir)/Bdef.h $(cdir)/Bconfig.h

#  ---------------------------------------
#  Make both C and fortran interface BLACS
#  ---------------------------------------
lib_obj += $(internal) $(Fintobj) $(Cintobj)
