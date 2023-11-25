#!/bin/bash

# Function to get inverted string
get_inverted() {
  local str=$1
  local inverted=""

  for (( i = 0; i < ${#str}; i++ )); do
    char="${str:i:1}"
    if [[ "$char" =~ [[:alpha:]] ]]; then
      if [[ "$char" == [[:upper:]] ]]; then
        inverted="$inverted$(echo "$char" | tr '[:upper:]' '[:lower:]')"
      elif [[ "$char" == [[:lower:]] ]]; then
        inverted="$inverted$(echo "$char" | tr '[:lower:]' '[:upper:]')"
      fi
    else
      inverted="$inverted$char"
    fi

  done

  echo "$inverted"
}

# Function to get reversed string
get_reversed(){
  local reversed=""
  local str=$1

  for (( i = ${#str} - 1; i >= 0; i-- )); do
    char="${str:i:1}"
    reversed="$reversed$char"
  done

  echo "$reversed"
}

SEPARATOR="@@@"
firstStr=$1
secondStr=$2

returnSecondStr=$(get_inverted "$(get_reversed "$secondStr")")
returnFirstStr=$(get_inverted "$(get_reversed "$firstStr")")$(get_inverted "$firstStr")

returnStr="$returnSecondStr$SEPARATOR$returnFirstStr"

echo "$returnStr"
