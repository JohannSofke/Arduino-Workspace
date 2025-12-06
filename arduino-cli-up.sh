#!/bin/bash

if ! command -v ./bin/arduino-cli &> /dev/null
then
    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
fi

./bin/arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
./bin/arduino-cli core install esp32:esp32@3.3.3 