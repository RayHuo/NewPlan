#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/554467558/EpisCNF.o \
	${OBJECTDIR}/_ext/554467558/EpisDNF.o \
	${OBJECTDIR}/_ext/554467558/Progression.o \
	${OBJECTDIR}/_ext/554467558/Vocabulary.o \
	${OBJECTDIR}/_ext/554467558/atoms.o \
	${OBJECTDIR}/_ext/554467558/formulatab.o \
	${OBJECTDIR}/_ext/554467558/init.o \
	${OBJECTDIR}/_ext/554467558/lex.o \
	${OBJECTDIR}/_ext/554467558/parse.o \
	${OBJECTDIR}/_ext/554467558/plan.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/newplan

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/newplan: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/newplan ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/554467558/EpisCNF.o: /home/xhd/Desktop/newplan/EpisCNF.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/EpisCNF.o /home/xhd/Desktop/newplan/EpisCNF.cpp

${OBJECTDIR}/_ext/554467558/EpisDNF.o: /home/xhd/Desktop/newplan/EpisDNF.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/EpisDNF.o /home/xhd/Desktop/newplan/EpisDNF.cpp

${OBJECTDIR}/_ext/554467558/Progression.o: /home/xhd/Desktop/newplan/Progression.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/Progression.o /home/xhd/Desktop/newplan/Progression.cpp

${OBJECTDIR}/_ext/554467558/Vocabulary.o: /home/xhd/Desktop/newplan/Vocabulary.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/Vocabulary.o /home/xhd/Desktop/newplan/Vocabulary.cpp

${OBJECTDIR}/_ext/554467558/atoms.o: /home/xhd/Desktop/newplan/atoms.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/atoms.o /home/xhd/Desktop/newplan/atoms.cpp

${OBJECTDIR}/_ext/554467558/formulatab.o: /home/xhd/Desktop/newplan/formulatab.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/formulatab.o /home/xhd/Desktop/newplan/formulatab.cpp

${OBJECTDIR}/_ext/554467558/init.o: /home/xhd/Desktop/newplan/init.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/init.o /home/xhd/Desktop/newplan/init.cpp

${OBJECTDIR}/_ext/554467558/lex.o: /home/xhd/Desktop/newplan/lex.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/lex.o /home/xhd/Desktop/newplan/lex.cpp

${OBJECTDIR}/_ext/554467558/parse.o: /home/xhd/Desktop/newplan/parse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/parse.o /home/xhd/Desktop/newplan/parse.cpp

${OBJECTDIR}/_ext/554467558/plan.o: /home/xhd/Desktop/newplan/plan.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/554467558
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/554467558/plan.o /home/xhd/Desktop/newplan/plan.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/newplan

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
