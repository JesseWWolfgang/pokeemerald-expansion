#!/bin/bash
(
	sleep 4
	echo "started"
)&
(
	IS_WSL=$(grep Microsoft /proc/version)

	if [[ -n $IS_WSL ]] 
	then
		# The shitty way
		# driveLetter=${1:5:1} # Get 5th char of $1. Only get 1 char.
		# driveLetterUpper=${driveLetter^^} # Make drive letter uppercase.
		# winPathNoDrive=${1:7} # Drop the first 7 chars off of $1. I.e. '/mnt/c/'
		# winPath=$driveLetterUpper:/$winPathNoDrive # Concat the drive letter with the win path without a drive letter to make C:/blah.

		# The cool way
		winPath=$(wslpath -m $1)

		# Launch mGBA with the windows path to the rom.
		echo $winPath
		"/mnt/c/Program Files/mGBA/mGBA.exe" "$winPath" -g
	else
		mgba-qt "$1" -g
	fi
)