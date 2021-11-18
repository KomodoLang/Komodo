#!/bin/bash

make && build/kom tests/plus.kd
# g++ src/*.cpp -o build/kom.out -lstdc++ -MMD -MP -Wall -static-pie