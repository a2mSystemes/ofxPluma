 #Module Makefile
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/config.addons.mk
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/config.project.mk
ADDONS_INCLUDES_MODULE = $(addprefix "-I", $(PROJECT_ADDONS_INCLUDES))
MODULE_CFLAGS = -export-dynamic -fPIC -Wall -Wextra -O2 -g
MODULE_LDFLAGS = -shared 
MODULE_RM = rm -f  # rm command
MODULE_TARGET_LIB = MyModule.so # target lib


MODULE_SRCS = MyModule.cpp
MODULE_OBJS = $(SRCS:.c=.o)
MODULES_DEST = bin/data/.modules/Core

.PHONY: moduleHelp

moduleHelp:
	@echo 
	@echo ofxPluma
	@echo Compilling module : $(MODULE_TARGET_LIB)

$(MODULE_TARGET_LIB): 
	@echo 'compiling modules lib'
	@echo project addons includes $(ADDONS_INCLUDES_MODULE)
	@mkdir -p $(MODULES_DEST)
	$(CXX) $(MODULE_CFLAGS) $(MODULE_LDFLAGS) $(OPTIMIZATION_CFLAGS) $(CFLAGS) $(CXXFLAGS) $(OF_CORE_INCLUDES_CFLAGS) $(ADDONS_INCLUDES_MODULE) src/$(MODULE_SRCS) -o $(MODULES_DEST)/$@ 
