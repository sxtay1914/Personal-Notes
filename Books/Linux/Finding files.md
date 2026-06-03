## Chapter 17 Finding files
### Commands:
1. locate
    * doesn’t search in real-time, search through db of path names
2. find
    * search in real-time, slower than locate
3. xargs
4. touch
5. stat

### find
* -type d: limit to directory
* -type f: limit to file

```
find ~ -type f -name “*.JPG” -size +1M | wc -l
```

### Operator
* -and, -or, -not
* () has special meaning to shell, so have to use escape char \( \)

### Predefined actions
* delete
* ls
* print
* quit

### User-Defined Actions
```
-exec command ‘{}’ ‘;’
```
* {} refers to current pathname 
* need to end user-defined actions with ;

### xargs
* take inputs from standard inputs and convert to arg list
```
find ~ -type f -name “foo*” -print | xargs ls -l
