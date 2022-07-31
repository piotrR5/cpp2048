#!/bin/bash

echo checking if required dependencies are installed

REQUIRED_PKG1="libncurses5-dev"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG1|grep "install ok installed")
echo Checking for $REQUIRED_PKG1: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG1. Setting up $REQUIRED_PKG1."
  sudo apt install $REQUIRED_PKG1
fi

REQUIRED_PKG2="libncursesw5-dev"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG2|grep "install ok installed")
echo Checking for $REQUIRED_PKG2: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG2. Setting up $REQUIRED_PKG2."
  sudo apt install $REQUIRED_PKG2
fi

REQUIRED_PKG3="libfmt-dev"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG3|grep "install ok installed")
echo Checking for $REQUIRED_PKG3: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG3. Setting up $REQUIRED_PKG3."
  sudo apt-get install $REQUIRED_PKG3
fi


