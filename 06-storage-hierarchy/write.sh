#!/bin/bash

rm -f testfile

echo "$(date): start write (file creation)"
dd if=/dev/zero of=testfile bs=100K count=1K
echo "$(date): end write"

rm -f testfile
