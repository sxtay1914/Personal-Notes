Chapter 21 Format Text
1. nl: number lines
2. fold: wrap a line
3. fmt: format document
4. pr: paginate a page
5. groff: turn plain text into well-formatted doc 
6. ps2pdf: conver ps to pdf format
## Options for nl
1. nl -b : numbering style for body
    * nl -b a file.txt: include line numbers for all 
    * nl -b n file.txt: no numbering at all
    * nl -b p'paragraph' file.txt: only number lines matching a pattern 
    * nl -b a -i 5 doc.txt: increment line number in 5 instead of 1
2. nl -b -n: numbering format
    * ln: left justified and no leading zero
    * rn: right justified and no leading zero
    * rz: right justified with leading zeros
* Eg. nl -b a -n rz file.txt : show line number for all in body, set numbering format to right justified with leading zero

## Options for fold
1. fold -w 12 -s
    * break the line at width 12 
    * -s : break the line at last space before the width limit is reached

## Options for fmt
1. -c: crown margin mode. What it does is it keeps indentation of first and second line. The rest of the lines follow the indentation of second line
2. -s: split lines and not join, because normally would join tgt
3. -p: format only lines beginning with a prefix

## Options for pr
1. -w: specify the width
2. -l: specify the line number

## Options for groff
short for g(runoff)
* zcat file.gzip | groff -mandoc -T ascii
    * if didn’t specify -T ascii, PostScript is output by default
