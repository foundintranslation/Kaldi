#! /bin/sh

#rm star-end symbols

sed 's/<s>//g' | sed 's/<\/s>//g' | sed 's/^ *//' | sed 's/ *$//' | sed '/^$/d'

