## Chapter 19 Regex

1. grep 
    * -r : recursively grep from list of files
    * grep -r ‘bzip.*’: cannot do ‘bzip*’ will return bzi
    * grep -h : don’t return file names
    * ls | grep '\.zip$'
    * grep -v: inverse, print out unmatched 

## Meta-character
1. dot
2. anchors
    * ^: beginning of the line
    * $: at the end 
3. bracket expressions 
    * grep -h ‘[bg]zip’ dirlist*.txt
    * grep -h ‘[^bg]zip’ dirlist*.txt : cannot have bzip or gzip
    * ls | grep '^[A-Z]': starting with capital letter

## POSIX char
1. [:alnum:]
2. [:digit:]
3. [:lower:]

## Two types of POSIX
1. BRE (Basic Regex)
2. ERE (Extended Regex)
    * ( ) { } ?  + | 

## ERE
grep -E
1. | : or
2. ?: matched 0 or 1 time
3. *: repeat >=0 time
4. +: repeat >=1 time
    * ^([[:alpha:]]+ ?)+$
5. {}: specify number of times
    * {n}: occurs exactly n times
    * {n, m} occurs n->m times
    * {n,} at least n
    * {,m} at most m

## Find
find will return exact match
* find . -regex '.*[^-_./0-9a-zA-Z].*’: find files with weird char

## locate
* locate —regex ‘bin/(bz|gz|zip)’

## zgrep
* to read compressed files
