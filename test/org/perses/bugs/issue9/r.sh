#!/bin/bash

set -o pipefail
set -o nounset
cp T.java.txt T.java
rm T.class > /dev/null 2>&1 || true
javac T.java && timeout -s 9 5 java T | grep -q '4'
