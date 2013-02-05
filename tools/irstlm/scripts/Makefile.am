#sh_programs = add-start-end.sh build-lm-qsub.sh build-lm.sh machine-type.bash machine-type.csh os-type.bash os-type.csh rm-start-end.sh split-ngt.sh
sh_programs = add-start-end.sh build-lm-qsub.sh build-lm.sh rm-start-end.sh split-ngt.sh
perl_programs = build-sublm.pl goograms2ngrams.pl lm-stat.pl merge-sublm.pl ngram-split.pl sort-lm.pl split-dict.pl
dist_programs = wrapper $(sh_programs) $(perl_programs) 

install:
	for p in $(sh_programs) $(perl_programs) ; do \
		cp $$p $(wrapperbindir) ;\
	done

uninstall:
	for p in $(sh_programs) $(perl_programs) ; do \
                rm -f $(wrapperbindir)/$$p ;\
        done

EXTRA_DIST = $(dist_programs)

