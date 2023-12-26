#!/bin/bash

IMAGE_NAME="imganquan/cppenv"
IMAGE_TAG="0.1"

# docker run -it --rm --name=cpp-playground \
#  --mount type=bind,source=${PWD},target=/src \
#  ${IMAGE_NAME}:${IMAGE_TAG} \
#  bash

docker run -it --name=cpp-playground \
        --mount type=bind,source=${PWD},target=/src \
        ${IMAGE_NAME}:${IMAGE_TAG} \
        zsh
