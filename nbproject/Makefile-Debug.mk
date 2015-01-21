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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/sources/EpisCNF.o \
	${OBJECTDIR}/sources/EpisDNF.o \
	${OBJECTDIR}/sources/Progression.o \
	${OBJECTDIR}/sources/Vocabulary.o \
	${OBJECTDIR}/sources/atoms.o \
	${OBJECTDIR}/sources/formulatab.o \
	${OBJECTDIR}/sources/init.o \
	${OBJECTDIR}/sources/lex.o \
	${OBJECTDIR}/sources/main.o \
	${OBJECTDIR}/sources/parse.o \
	${OBJECTDIR}/sources/plan.o


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

${OBJECTDIR}/sources/EpisCNF.o: sources/EpisCNF.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/EpisCNF.o sources/EpisCNF.cpp

${OBJECTDIR}/sources/EpisDNF.o: sources/EpisDNF.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/EpisDNF.o sources/EpisDNF.cpp

${OBJECTDIR}/sources/Progression.o: sources/Progression.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Progression.o sources/Progression.cpp

${OBJECTDIR}/sources/Vocabulary.o: sources/Vocabulary.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Vocabulary.o sources/Vocabulary.cpp

${OBJECTDIR}/sources/atoms.o: sources/atoms.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/atoms.o sources/atoms.cpp

${OBJECTDIR}/sources/formulatab.o: sources/formulatab.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/formulatab.o sources/formulatab.cpp

${OBJECTDIR}/sources/init.o: sources/init.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/init.o sources/init.cpp

${OBJECTDIR}/sources/lex.o: sources/lex.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/lex.o sources/lex.cpp

${OBJECTDIR}/sources/main.o: sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/main.o sources/main.cpp

${OBJECTDIR}/sources/parse.o: sources/parse.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/parse.o sources/parse.cpp

${OBJECTDIR}/sources/plan.o: sources/plan.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iheadfile -Iheadfile -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/plan.o sources/plan.cpp

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
