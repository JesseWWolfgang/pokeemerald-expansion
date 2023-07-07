#!/bin/bash
IS_WSL=$(grep Microsoft /proc/version)

if [[ -n $IS_WSL ]] 
then
    projPath=$(wslpath -a ./)
    echo $projPath
    ./tools/pory/porymap.exe $projPath
else
    ./tools/pory/porymap
fi