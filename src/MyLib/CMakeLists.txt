add_library(MyLib myLib.cpp myLib.h)

install(TARGETS MyLib DESTINATION lib)
install(FILES myLib.h DESTINATION include)
