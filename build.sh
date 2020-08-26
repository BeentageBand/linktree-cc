. common.sh

echo "docker run -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/linktree/build -it linktree-cc:latest /usr/bin/make $@"
docker run -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/linktree/build -it linktree-cc:latest /usr/bin/make $@
