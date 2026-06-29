# Chapter 20 Text Processing

## Commands
1. cat: concatenate files vertically and print to stdout
2. sort
3. uniq 
4. cut
5. paste: add columns
6. join: join files horizontally, treat files as relational table && need to be sorted
7. comm: compare files
8. diff
9. patch
10. tr: transliterating, converting char  
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
Eg. sort -k 3.7nbr -k 3.1nbr -k 3.4nbr ( sort date in descending order for MM/DD/YYYY )
[me@linuxbox ~]$ sort --key=1,1 --key=2n distros.txt
1,1: means start at field 1 ends at field 1
2n: means start at field 2 & extend to the end. Use numeric sort 

## uniq
sort first then uniq
* sort foo.txt | uniq

## Options for uniq
* -c: count duplicates
* -d: print only duplicated line
* -i: ignoring case
* -u: print only unique line 
* -f: skip fields separated by space, useful when field is unique identifier 
* -s: skip characters

## Cut options
* -c : cut
    * Eg. extract first 5 char: cut -c 1-5 file.txt 
* -f : extract fields
    * Eg.  extract first & third field: cut -f 1,3 file.txt
* -d : specify custom delimiter
    * Eg. cut -d ‘:’ -f 1,3 file.txt
* —complement : 除了选中的fields
    * Eg. cut -d ‘:’ -f 1,3 —complement file.txt

## Paste
Eg. paste file1.txt file2.txt

## Comm
* have 3 columns: first col contains lines unique to first file, second col contains lines unique to second file, third is common to both
* ￼
* comm -12 file1.txt file2.txt
    * suppresses the first and second col

## Diff 
can compare the whole source code dir (aka source trees) by recursively going into subdirectory

1d0
< a
4a4
> e
1. go to line 1 of file 1 and delete 
2. shows what to delete 
3. go to line 4 of file 1 and add line 4 from file 2
4. shows what to add ( > means from file 2) 

## Diff option
* -c : context format 
￼
* -u: unified format
￼
* N: track new file, because diff usually skip this 
* a: force diff to track all files as standard file, diff usually skip binary file
* r: recursively
How to prepare diff file?
diff -Naur old_file new_file > diff_file

## Patch
patch < diff_file ( dont have to specify target file)

## tr
* tr [range of char to convert from] [range of char to convert to]
## tr option
* -d: delete
    * tr -d ‘\r’ < dos_file > unix_file 
* -s: squeeze 
    * echo “aaabbbccc” | tr -s ab

## sed
**stream editor for filtering and transforming text**
* echo “front” | sed ’s/front/back/‘ : / is delimiter
* sed ‘1s/front/back’ : 1 refers to line 1

## sed option
1. -n: no auto-print   p: print matched line
    * sed -n “3p” file.txt
2. $: means last line
3. /regex/
    * sed -n “/beta/p” file.txt 
4. add1, add2
    * sed -n “2, 4p” file.txt
5. add~step:
    * sed -n “2~2p” file.txt
6. add1, +n:
    * sed -n “2, +2p” file.txt
7. add!: match all except add
8. =: print line number that is matched
9. a: append
10. q: exit and output
11. Q: exit without outputting
12. s: replacement
    * add g to the end 
13. y: perform transliteration

——————————————
sed 's/\([0-9]\{2\}\)\/\([0-9]\{2\}\)\/\([0-9]\{4\}\)$/\3-\1-\2/' distros.txt
— \3-\1-\2: refers to capture group 3 then 1 then 2, in this case it is year, month then day
-------------- 
