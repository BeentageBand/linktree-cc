#!/bin/sh
. common.sh

docker run -v ${HOST_PATH}:${TARGET_PATH}  -p $HOST_PORT:$TARGET_PORT -e PORT=$TARGET_PORT -w ${TARGET_PATH}/linktree/build -it linktree-cc:latest  ./linktree
