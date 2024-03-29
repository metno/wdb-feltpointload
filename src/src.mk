
#-----------------------------------------------------------------------------
# WDB FeltLoad Component
#-----------------------------------------------------------------------------

feltPointLoad_SOURCES =  src/main.cpp \
					     src/feltConstants.h \
					     src/feltTypeConversion.h \
					     src/feltTypeConversion.cpp \
					     src/FeltFile.cpp \
					     src/FeltFile.h \
					     src/FeltField.cpp \
					     src/FeltField.h \
					     src/FeltLoader.cpp \
					     src/FeltLoader.h \
					     src/FeltGridDefinition.cpp \
					     src/FeltGridDefinition.h \
					     src/FeltLoadConfiguration.cpp \
					     src/FeltLoadConfiguration.h \
						 src/FeltConfigFile.cpp \
						 src/FeltConfigFile.h
	
EXTRA_DIST +=		src/src.mk
