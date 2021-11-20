for i in SFX/*.mp3
do
	newName=${i%.*}.wav

	ffmpeg -i $i $newName -loglevel quiet
	echo -e "Converted: '$i' -> '$newName'"

	rm $i
	echo -e "Removed: '$i'"
done

for i in SFX/*.wav
do
	for j in {1..5}
	do
		normalize-audio $i -q
		echo -e "Normalized '$i' | Pass $j"
	done
done

for i in SFX/*.wav
do
	tempName=${i%.*}.tmp.wav

	ffmpeg -i $i -af silenceremove=window=0:detection=peak:stop_mode=all:start_mode=all:stop_periods=-1:stop_threshold=0 -loglevel quiet $tempName
	echo -e "Removed Silence: '$i' -> '$tempName'"

	rm $i
	echo -e "Removed: '$i'"
	
	mv $tempName $i
	echo -e "Renamed: '$tempName' -> '$i'"
done
