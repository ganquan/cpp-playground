#!/bin/bash

SCRIPT_PATH=$(realpath "$0")

MLPACK_DATA_PATH=$(dirname $(dirname "$SCRIPT_PATH"))/data
export MLPACK_DATA_PATH
echo $MLPACK_DATA_PATH
