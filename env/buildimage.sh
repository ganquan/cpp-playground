#!/bin/bash

IMAGE_NAME="imganquan/cppenv"
IMAGE_TAG="0.1"


docker build -t ${IMAGE_NAME}:${IMAGE_TAG} .
