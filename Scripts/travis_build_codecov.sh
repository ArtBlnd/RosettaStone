#!/usr/bin/env bash

set -e

export NUM_JOBS=1

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_COVERAGE=ON
make UnitTests
lcov -c -i -d Tests/UnitTests -o base.info
bin/UnitTests
lcov -a base.info -a test.info -o coverage.info
lcov -r coverage.info '/usr/*' -o coverage.info
lcov -r coverage.info '*/Libraries/*' -o coverage.info
lcov -r coverage.info '*/Programs/*' -o coverage.info
lcov -r coverage.info '*/Tests/*' -o coverage.info
lcov -r coverage.info '*/Tools/*' -o coverage.info
lcov -l coverage.info
bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"