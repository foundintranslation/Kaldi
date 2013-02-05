install: irstlm-manual.tex
	pdflatex irstlm-manual ; \
	bibtex irstlm-manual ; \
	pdflatex irstlm-manual ; \
	pdflatex irstlm-manual ; \
	rm *.aux *.log *.bbl *.blg

uninstall:
	rm *.pdf 

EXTRA_DIST = \
	irstlm-manual.tex 

