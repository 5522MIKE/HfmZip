main: main.o HfmTree.o ShowHelp.o UnCode.0
	gcc -o $@ $^
main.o: main.c HfmTree.h ShowHelp.h UnCode.h
    gcc -c $<
HfmTree.o: HfmTree.c HfmTree.h
    gcc -c $<
ShowHelp.o: ShowHelp.c ShowHelp.h
    gcc -c $<
UnCode.0: UnCode.c UnCode.h HfmTree.h
	gcc -c $<

.PHONY:clean

clean:
    -rm -rf *.o