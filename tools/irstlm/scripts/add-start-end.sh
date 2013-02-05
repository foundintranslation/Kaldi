#! /bin/sh

#adds sentence start/end symbols to standard input and 
#trims words longer than 80 characters

(echo "</s>" ; sed 's/^/<s> /' | sed 's/$/ <\/s>/';echo "<s>") |\
sed 's/\([^ ]\{80\}\)\([^ ]\{1,\}\)/\1/g'

