. common.sh

docker run --rm -tid --name lk ${PREFIX}-cc:latest
docker cp ${PREFIX} lk:${TARGET_PATH}
docker commit lk ${PREFIX}-app
docker stop lk

pushd ${PREFIX}
  docker build -t ${PREFIX}-app .
  docker run --rm -p ${HOST_PORT}:${TARGET_PORT} -e MONGODB_URI=${MONGODB_URI} -e PORT=${TARGET_PORT} ${PREFIX}-app
popd

