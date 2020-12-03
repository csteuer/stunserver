include ../common.inc

PROJECT_TARGET := libcommon.a
PROJECT_SRCS := atomichelpers.cpp cmdlineparser.cpp common.cpp fasthash.cpp getconsolewidth.cpp getmillisecondcounter.cpp logger.cpp prettyprint.cpp refcountobject.cpp stringhelper.cpp
PROJECT_OBJS := $(subst .cpp,.o,$(PROJECT_SRCS))
INCLUDES := $(BOOST_INCLUDE)




all: $(PRECOMP_H_GCH) $(PROJECT_TARGET)

clean:
	rm -f $(PROJECT_OBJS) $(PROJECT_TARGET)

$(PROJECT_TARGET): $(PROJECT_OBJS)
	rm -f $@
	$(AR) rv $@ $^ 


	
