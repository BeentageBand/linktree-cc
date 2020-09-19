. common.sh

if [[ -z "`docker images | grep ${PREFIX}-cc`" ]];
then 
  docker build --no-cache -t ${PREFIX}-cc .
fi

echo "docker run --rm -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it ${PREFIX}-cc:latest /usr/bin/make $@"
docker run --rm -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it ${PREFIX}-cc:latest /usr/bin/make $@
