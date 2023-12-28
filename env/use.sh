#!/bin/bash

IMAGE_NAME="imganquan/cppenv-ub"
IMAGE_TAG="0.1"
CONTAINER_NAME="ubuntu"

# docker run -it --rm --name=cpp-playground \
#  --mount type=bind,source=${PWD},target=/src \
#  ${IMAGE_NAME}:${IMAGE_TAG} \
#  bash

docker run -it --name=${CONTAINER_NAME} \
        --mount type=bind,source=${PWD},target=/src \
        ${IMAGE_NAME}:${IMAGE_TAG} \
        zsh
