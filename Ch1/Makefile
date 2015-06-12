CHAPTERS = Ch1 Ch2 Ch3 Ch4 Ch5 Ch6
ARG = Makefile

clean:
	mkdir ../save && mv *.c ../save/ && mv Makefile ../save/
	rm * && mv ../save/* . && rm -rf ../save

update:
	$(foreach ch, $(CHAPTERS), cp $(ARG) ../$(ch);)

%.c: %.c
	if [ -f $@.c ]; then gcc $@.c -Wall -o $@; fi

%:
	if [ ! -f $@.c ]; then sed 's/$$TARGET/$@/g' test.c > $@.c; fi
