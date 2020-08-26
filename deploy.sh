#!/bin/sh
. common.sh

docker run --rm --tid --name lk linktree-cc
docker cp . lk:${TARGET_PATH}
docker commit lk linktree-app
docker stop lk

pushd linktree
docker build -t linktree-app .
docker run --rm -p $HOST_PORT:$TARGET_PORT -e PORT=$TARGET_PORT linktree-app
popd

