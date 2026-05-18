## Packaging systems
* Debian & Red Hat distributions

## What does dependency mean?
* package requiring shared resource
* dependency resolution -> when a software is installed, all related dependencies 

## Type of package tools
* low-level: install & remove
* high-level: metadata search and dependency resolution

## Difference between apt-get and apt
* apt is more stable, use in shell-scripting 

## Installing from repository
1. sudo apt update
    * download package list
2. sudo apt-get 
    * search for package 
3. apt install 
    * install package

## Installing from package file 
* Doesn’t have dependency resolution
