#!/bin/bash

test_cases_file="test_cases"
program="dist/Debug/GNU-Linux-x86/newplan"

cat $test_cases_file | while read oneline
do
    $program $oneline
    echo
done

exit 0
