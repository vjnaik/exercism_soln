#!/usr/bin/env bash

name="you"

if [[ -n $1 ]]; then
    name="$1"
fi

echo "One for $name, one for me."