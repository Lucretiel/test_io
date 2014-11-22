#!/bin/sh

if test ! -f 'test'
then
    echo "Building..."
    sh build.sh
fi

if test ! -f 'test.in'
then
    echo "Generating Files..."
    python3 create_test.py > test.in 2> test.out
fi

echo "Running tests..."
sh test_script
