## Permissions
* r: can ls dir
* x: can cd into dir if dir name is known

### Change permissions
* -> octal way (eg. chmod 677)
* -> symbolic way (eg. chmod u+x)

### Can you write without w set but not x?
Yes, able to modify file's content but not able to ls
But if modify file outside of dir wihout **x**, the write cannot be done

### Real collaboration
chown changes ownership of files and dir, but it is not enough for collab.
* gotta take note of the system's default permission (**umask**)
* newly created files will have diff permission (**chmod**)

## Changing identities
* sudo: temporarily execute command as root, doesnt load root env
* su: becomes root interatively, doesnt load root env
* su - : load root env

