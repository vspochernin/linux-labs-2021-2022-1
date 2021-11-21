#!/bin/bash

sudo insmod hello-1.ko
sudo insmod hello-2.ko
sudo insmod hello-3.ko
sudo insmod hello-4.ko
sudo insmod hello-5.ko mystring="superstring" myshort=124 myint=1000 mylong=9999
sudo insmod startstop1.ko

