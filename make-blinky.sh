#!/bin/bash

./bin/arduino-cli compile --output-dir . --fqbn esp32:esp32:esp32s3 blinky
rm blinky.ino.bin
rm blinky.ino.bootloader.bin
rm blinky.ino.elf
rm blinky.ino.map
rm blinky.ino.partitions.bin