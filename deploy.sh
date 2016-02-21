#!/bin/bash

cd ./.build
make
if [ -a "FRCUserProgram" ]
then
	echo "removing"
	rm -rf ./FRCUserProgram
fi

mv ./FRC* ./FRCUserProgram
ssh admin@169.254.3.45 'cd /home/lvuser; rm FRCUserProgram;'
scp FRCUserProgram lvuser@169.254.3.45:/home/lvuser
