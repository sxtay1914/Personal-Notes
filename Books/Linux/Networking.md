Chapter 16 Networking
## Commands:
* ping
* traceroute: find how many routers pass through 
* ip: identify routing table and network interfaces
* netstat
* ftp
* wget
* ssh

## What is NAS(network-attached storage)?
* centralised server to store/share files over TCP/IP

## Recap on host/domain name?
eg. www.google.com
* www: host name
* google: second-level domain 
* com: top level domain
 ## FTP
* Not secure, because usernames and pw are in clear text
* so now only anonymous servers use
    * what is anonymous server? server with username: anonymous & password: blank or email format
* **secure version**: SFTP 

## SSH
* encrypt communication
* authenticate the remote host
* ‘’ is to prevent expansion in the local dir 

### Copy files
* scp: secure copy
    * scp remote-sys:document.txt .    : copy from remote sys to local working dir
