LIBSDL =  -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL  -lSDL_image -lSDL_mixer -lpthread
PLATFORM=NARM

PROG    = tictactoe
CC=$(CROSS_COMPILE)g++

INCLS	=  -I/usr/include

#source codes
SRCS = tictactoe.cpp io_threads.cpp game_thread.cpp sound.cpp surface.cpp
#substitute .c by .o to obtain object filenames
OBJS = $(SRCS:.cpp=.o) 
 
#$< evaluates to the target's dependencies,
#$@ evaluates to the target
 
$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)  $(LIBSDL) 
 
$(OBJS):
	$(CC) -c  $*.cpp $(INCLS) -D$(PLATFORM)
                                                                                
clean:
	rm $(OBJS)
