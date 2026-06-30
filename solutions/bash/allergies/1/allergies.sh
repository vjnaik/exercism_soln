#!/usr/bin/env bash

score="$1"
list=""
if (( ((score >> 0) & 1) == 1 )); then
    list+="eggs "
fi
if (( ((score >> 1) & 1) == 1 )); then
    list+="peanuts "
fi
if (( ((score >> 2) & 1) == 1 )); then
    list+="shellfish "
fi
if (( ((score >> 3) & 1) == 1 )); then
    list+="strawberries "
fi
if (( ((score >> 4) & 1) == 1 )); then
    list+="tomatoes "
fi
if (( ((score >> 5) & 1) == 1 )); then
    list+="chocolate "
fi
if (( ((score >> 6) & 1) == 1 )); then
    list+="pollen "
fi
if (( ((score >> 7) & 1) == 1 )); then
    list+="cats "
fi
option="$2"
if [[ "$option" == "list" ]]; then
    echo "${list% }"
elif [[ "$list" == *"$3"* ]]; then
    echo "true"
else 
    echo "false"
fi