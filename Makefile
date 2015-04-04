#############################################################################
# Makefile for building: GARVIS_CM
# Generated by qmake (2.01a) (Qt 4.8.6) on: Fri Apr 3 23:32:48 2015
# Project:  GARVIS_CM.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile GARVIS_CM.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++0x -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		BlackLib/v2_0/BlackADC.cpp \
		BlackLib/v2_0/BlackCore.cpp \
		BlackLib/v2_0/BlackGPIO.cpp \
		BlackLib/v2_0/BlackI2C.cpp \
		BlackLib/v2_0/BlackPWM.cpp \
		BlackLib/v2_0/BlackSPI.cpp \
		BlackLib/v2_0/BlackUART.cpp \
		bb_uart.cpp \
		commandcreator.cpp \
		iomanager.cpp \
		statusmonitor.cpp \
		setthresholds.cpp \
		helpdialog.cpp \
		gloveapi.cpp \
		tutorialwizard.cpp moc_mainwindow.cpp \
		moc_setthresholds.cpp \
		moc_helpdialog.cpp \
		moc_tutorialwizard.cpp
OBJECTS       = main.o \
		mainwindow.o \
		BlackADC.o \
		BlackCore.o \
		BlackGPIO.o \
		BlackI2C.o \
		BlackPWM.o \
		BlackSPI.o \
		BlackUART.o \
		bb_uart.o \
		commandcreator.o \
		iomanager.o \
		statusmonitor.o \
		setthresholds.o \
		helpdialog.o \
		gloveapi.o \
		tutorialwizard.o \
		moc_mainwindow.o \
		moc_setthresholds.o \
		moc_helpdialog.o \
		moc_tutorialwizard.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		GARVIS_CM.pro
QMAKE_TARGET  = GARVIS_CM
DESTDIR       = 
TARGET        = GARVIS_CM

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_setthresholds.h ui_helpdialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GARVIS_CM.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile GARVIS_CM.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile GARVIS_CM.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/GARVIS_CM1.0.0 || $(MKDIR) .tmp/GARVIS_CM1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/GARVIS_CM1.0.0/ && $(COPY_FILE) --parents mainwindow.h BlackLib/v2_0/BlackADC.h BlackLib/v2_0/BlackCore.h BlackLib/v2_0/BlackDef.h BlackLib/v2_0/BlackErr.h BlackLib/v2_0/BlackGPIO.h BlackLib/v2_0/BlackI2C.h BlackLib/v2_0/BlackLib.h BlackLib/v2_0/BlackPWM.h BlackLib/v2_0/BlackSPI.h BlackLib/v2_0/BlackUART.h bb_uart.h commandcreator.h iomanager.h statusmonitor.h constants.h setthresholds.h helpdialog.h gloveapi.h tutorialwizard.h .tmp/GARVIS_CM1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp BlackLib/v2_0/BlackADC.cpp BlackLib/v2_0/BlackCore.cpp BlackLib/v2_0/BlackGPIO.cpp BlackLib/v2_0/BlackI2C.cpp BlackLib/v2_0/BlackPWM.cpp BlackLib/v2_0/BlackSPI.cpp BlackLib/v2_0/BlackUART.cpp bb_uart.cpp commandcreator.cpp iomanager.cpp statusmonitor.cpp setthresholds.cpp helpdialog.cpp gloveapi.cpp tutorialwizard.cpp .tmp/GARVIS_CM1.0.0/ && $(COPY_FILE) --parents mainwindow.ui setthresholds.ui helpdialog.ui .tmp/GARVIS_CM1.0.0/ && (cd `dirname .tmp/GARVIS_CM1.0.0` && $(TAR) GARVIS_CM1.0.0.tar GARVIS_CM1.0.0 && $(COMPRESS) GARVIS_CM1.0.0.tar) && $(MOVE) `dirname .tmp/GARVIS_CM1.0.0`/GARVIS_CM1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/GARVIS_CM1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_setthresholds.cpp moc_helpdialog.cpp moc_tutorialwizard.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_setthresholds.cpp moc_helpdialog.cpp moc_tutorialwizard.cpp
moc_mainwindow.cpp: BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		commandcreator.h \
		constants.h \
		iomanager.h \
		bb_uart.h \
		gloveapi.h \
		mainwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_setthresholds.cpp: iomanager.h \
		bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		constants.h \
		setthresholds.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) setthresholds.h -o moc_setthresholds.cpp

moc_helpdialog.cpp: helpdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) helpdialog.h -o moc_helpdialog.cpp

moc_tutorialwizard.cpp: tutorialwizard.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) tutorialwizard.h -o moc_tutorialwizard.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_setthresholds.h ui_helpdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_setthresholds.h ui_helpdialog.h
ui_mainwindow.h: mainwindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_setthresholds.h: setthresholds.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic setthresholds.ui -o ui_setthresholds.h

ui_helpdialog.h: helpdialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic helpdialog.ui -o ui_helpdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		commandcreator.h \
		constants.h \
		iomanager.h \
		bb_uart.h \
		gloveapi.h \
		tutorialwizard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		commandcreator.h \
		constants.h \
		iomanager.h \
		bb_uart.h \
		gloveapi.h \
		ui_mainwindow.h \
		setthresholds.h \
		helpdialog.h \
		tutorialwizard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

BlackADC.o: BlackLib/v2_0/BlackADC.cpp BlackLib/v2_0/BlackADC.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackADC.o BlackLib/v2_0/BlackADC.cpp

BlackCore.o: BlackLib/v2_0/BlackCore.cpp BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackCore.o BlackLib/v2_0/BlackCore.cpp

BlackGPIO.o: BlackLib/v2_0/BlackGPIO.cpp BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackGPIO.o BlackLib/v2_0/BlackGPIO.cpp

BlackI2C.o: BlackLib/v2_0/BlackI2C.cpp BlackLib/v2_0/BlackI2C.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackI2C.o BlackLib/v2_0/BlackI2C.cpp

BlackPWM.o: BlackLib/v2_0/BlackPWM.cpp BlackLib/v2_0/BlackPWM.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackPWM.o BlackLib/v2_0/BlackPWM.cpp

BlackSPI.o: BlackLib/v2_0/BlackSPI.cpp BlackLib/v2_0/BlackSPI.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackSPI.o BlackLib/v2_0/BlackSPI.cpp

BlackUART.o: BlackLib/v2_0/BlackUART.cpp BlackLib/v2_0/BlackUART.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackUART.o BlackLib/v2_0/BlackUART.cpp

bb_uart.o: bb_uart.cpp bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bb_uart.o bb_uart.cpp

commandcreator.o: commandcreator.cpp commandcreator.h \
		constants.h \
		iomanager.h \
		bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commandcreator.o commandcreator.cpp

iomanager.o: iomanager.cpp iomanager.h \
		bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o iomanager.o iomanager.cpp

statusmonitor.o: statusmonitor.cpp statusmonitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statusmonitor.o statusmonitor.cpp

setthresholds.o: setthresholds.cpp setthresholds.h \
		iomanager.h \
		bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		constants.h \
		ui_setthresholds.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o setthresholds.o setthresholds.cpp

helpdialog.o: helpdialog.cpp helpdialog.h \
		ui_helpdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o helpdialog.o helpdialog.cpp

gloveapi.o: gloveapi.cpp gloveapi.h \
		iomanager.h \
		bb_uart.h \
		BlackLib/v2_0/BlackGPIO.h \
		BlackLib/v2_0/BlackCore.h \
		BlackLib/v2_0/BlackErr.h \
		BlackLib/v2_0/BlackDef.h \
		BlackLib/v2_0/BlackUART.h \
		constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gloveapi.o gloveapi.cpp

tutorialwizard.o: tutorialwizard.cpp tutorialwizard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tutorialwizard.o tutorialwizard.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_setthresholds.o: moc_setthresholds.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_setthresholds.o moc_setthresholds.cpp

moc_helpdialog.o: moc_helpdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_helpdialog.o moc_helpdialog.cpp

moc_tutorialwizard.o: moc_tutorialwizard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_tutorialwizard.o moc_tutorialwizard.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/debian/ || $(MKDIR) $(INSTALL_ROOT)/home/debian/ 
	-$(INSTALL_PROGRAM) /home/strauss/qt-bbb/projects/GARVIS_CM/GARVIS_CM $(INSTALL_ROOT)/home/debian/
	-strip $(INSTALL_ROOT)/home/debian/GARVIS_CM


uninstall_target:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/home/debian/GARVIS_CM
	-$(DEL_DIR) $(INSTALL_ROOT)/home/debian/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

