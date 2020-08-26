. common.sh

if [[ -n "`docker images | grep ${PREFIX}-cc`" ]];
then 
  docker -t ${PREFIX}-cc .
fi

echo "docker run -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it ${PREFIX}-cc:latest /usr/bin/make $@"
docker run -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it ${PREFIX}-cc:latest /usr/bin/make $@
