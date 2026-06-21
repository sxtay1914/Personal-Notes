# Chapter 20 Text Processing

## Commands
1. cat: concatenate files vertically and print to stdout
2. sort
3. uniq 
4. cut
5. paste
6. join: join files horizontally, treat files as relational table && need to be sorted
7. comm
8. diff
9. patch
10. tr
11. sed
12. aspell: interactive spellchecker


## Options for cat
* -A : print non-visible char
* -n: print lines
* -s: suppress multiple blank lines

## Options for sort
* -b: ignore leading spaces 
* -f: ignore (remember as forget case)
* -n: numeric sort
* -r: reverse 
* -k: sort base on key fields
* -m: merge different files together without performing sort from scratch again once merged. Caveat: the file must be sorted alrdy
* -o: output to file rather than to stdout
* -t: field separator, by default fields are separated by tabs and spaces

`[me@linuxbox ~]$ sort --key=1,1 --key=2n distros.txt`
1,1: means start at field 1 ends at field 1
2n: means start at field 2 & extend to the end. Use numeric sort 
