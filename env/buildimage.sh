#!/bin/bash

IMAGE_NAME="imganquan/cppenv-ub-mlpack"
IMAGE_TAG="0.1"


docker build -t ${IMAGE_NAME}:${IMAGE_TAG} .
