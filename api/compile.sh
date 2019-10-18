#!/bin/bash
NAME_FILE=$1

if [ -z $NAME_FILE ]; then 
	echo "Veuillez definir votre fichier a compiler "
	exit 1
fi
NAME=`echo $NAME_FILE | cut -d"." -f1`

DIR_SRC="/home/pi/DEV/eHealthLib"

g++ -lpthread -lrt -I${DIR_SRC} ${DIR_SRC}/cooking/arduPi/arduPi.cpp ${DIR_SRC}/eHealth.cpp $NAME.cpp -o $NAME

