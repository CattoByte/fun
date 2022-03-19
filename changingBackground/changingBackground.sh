#!/bin/bash

backgroundTime=$1
intermissionTime=$2

function changeBackground  {
	#Get full path of background
	backgroundPath="$(pwd)/$1"
	
	#You should change this to work with your OS, as this is coded to run on Ubuntu with GNOME.
	backgroundPath="file:///$backgroundPath"
	gsettings set org.gnome.desktop.background picture-uri "$backgroundPath"
}

function switchToIntermission {
	#Calculate the time that each intermission "frame" will be displayed by using this long command.
	waitTime=$(bc <<< "scale=2; $2 / $(ls backgrounds/intermission -1 | wc -l)")

	for frame in backgrounds/intermission/*.*
	do
		changeBackground $frame
		sleep $waitTime
	done
}	

while true
do
	background=backgrounds/$(ls -p1 backgrounds/ | grep -v "/" | shuf -n 1)

	changeBackground $background
	sleep $backgroundTime
	switchToIntermission $background $intermissionTime
done
