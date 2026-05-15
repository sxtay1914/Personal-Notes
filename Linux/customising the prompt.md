## Why do we need "$" and not $ in certain cases:
* this is to prevent expansion 

## What is the function of \[ followed by \]?
* this is to tell bash not to count in non-visible characters, which can result in strange cursor movement/positiion. 
* eg. PS1="\[\033[0;31m\]<\u@\h \W>\$ " without \[ bash will count the char

## What modification can be done?
* we can change color of text
* we can move cursor to different part of terminal

## One thing to note:
* PS1="\[\033[s\033[0;0H\033[0;41m\033[K\033[1;33m\t\033[0m\033[u\]<\u@\h \W>\$ "
  *  \033[0m is needed to turn off color
