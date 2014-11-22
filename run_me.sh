#!/bin/sh

if test ! -f 'test'
then
    echo "Building..."
    sh build.sh &
fi

if test ! -f 'test.in'
then
    echo "Generating test files..."
    python3 create_test.py > test.in 2> test.out &
fi

wait

echo "Running tests..."
sh test_script
