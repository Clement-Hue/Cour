BASENAME= center
LATEX= latex
DVItoPDF= dvipdf

all: center
center: $(BASENAME).tex
	$(LATEX) $<
	$(DVItoPDF) $@.dvi

clean: 
	rm center.aux center.log center.dvi
