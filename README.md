# fun
##  A collection of trash!
Here lies a bunch of small c++ programs that I created either on my spare time, or when I wanted to code but was exhausted from other projects.
## List of "trashes":

| Name | Description | Date  | Dependencies | Notes |
| - | - | - | - | - | - |
| Bouncy | Balls bouncing, with gravity | 2021年 11月 17日 | None |
| Interrupted Silence | Random sounds playing at random intervals | 2021年 11月 20日 | aplay (optional: normalize-audio) | Comes with a bash script to convert mp3 files to wav and normalize audio. |

### Bugs:
#### Bouncy:
 - Balls will not reach zero velocity (they will keep alternating between the two last rows).
 - ~~Can crash due to memory errors~~ Fixed (Didn't check bounds correctly)
#### Interrupted Silence:
 - N/A
