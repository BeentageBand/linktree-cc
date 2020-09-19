. common.sh

docker run -v ${HOST_PATH}:${TARGET_PATH} \
  -p ${HOST_PORT}:${TARGET_PORT} \
  -e PORT=${TARGET_PORT} \
  -e MONGODB_URI=${MONGODB_URI}\
  -w ${TARGET_PATH}/${PREFIX}/build \
  -it bbox:latest ./${PREFIX}
