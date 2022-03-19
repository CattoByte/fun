# fun
##  A collection of trash!
Here lies a bunch of small C, C++, Bash, and whatever else programs that I created either on my spare time, or when I wanted to code but was exhausted from other projects.
Anyone can submit their trashes by making a pull request, but remember, the programs are called "trashes" for a reason, it has to be something that just exists for fun.
I'll take care of updating the README file, though.
## List of "trashes":

| Name			| Description					| Date			| Dependencies				| Notes										| Author	| Target OS		|
| -			| -						| -			| - 					| -										| -		| -			|
| Bouncy		| Balls bouncing, with gravity			| 2021年 11月 17日	| None					|										| キャトバイト	| Linux			|
| Interrupted Silence	| Random sounds playing at random intervals	| 2021年 11月 20日	| aplay (optional: normalize-audio)	| Comes with a bash script to convert mp3 files to wav and normalize audio.	| キャトバイト	| Linux			|
| Changing Background	| A slideshow script, for Gnome			| 2021年 12月 27日	| None					| Allows you to some transition images, I assume this only works with Gnome.	| キャトバイト	| Linux (Ubuntu, Gnome)	|
### Bugs:
#### Bouncy:
 - Balls will not reach zero velocity (they will keep alternating between the two last rows).
 - ~~Can crash due to memory errors~~ Fixed (Didn't check bounds correctly)
#### Interrupted Silence:
 - N/A
