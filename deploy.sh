. common.sh

docker run --rm -tid --name lk ${PREFIX}-cc
docker cp . lk:${TARGET_PATH}
docker commit lk ${PREFIX}-app
docker stop lk

pushd ${PREFIX}
  docker build -t ${PREFIX}-app .
  docker run --rm -p ${HOST_PORT}:${TARGET_PORT} -e PORT=$TARGET_PORT ${PREFIX}-app
popd

